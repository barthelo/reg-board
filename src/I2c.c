/**
  ******************************************************************************
  * @file    I2c.c
  * @author  Eugen Bartel
  * @version V1.0
  * @date    25-May-2013
  * @brief   This file provides set of firmware functions I2C_SLAVE
  * 
  * @note    I2C WIRD ALS SLAVE BETRIEBEN
  ******************************************************************************/
#include "I2c.h"

/**
 * @brief  Richtet die benoetigten Ports und Interrupts ein, die fuer
 *              den Betrieb benoetigt werden.
 * @param  none
 * @retval none
 **/
void I2C_vInit(void)
{
  GPIO_InitTypeDef myGPIO;
  I2C_InitTypeDef myI2C;
  NVIC_InitTypeDef  myNVIC;
  
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE);
  
  /*//Performing reset
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
  RCC_APB1PeriphResetCmd(RCC_APB1Periph_I2C1, ENABLE);
  RCC_APB1PeriphResetCmd(RCC_APB1Periph_I2C1, DISABLE);*/
  
  myGPIO.GPIO_Pin=GPIO_Pin_7 | GPIO_Pin_8;//Choose Pin
  myGPIO.GPIO_Mode=GPIO_Mode_AF;//GPIO_Mode set to AlternateFunction
  myGPIO.GPIO_Speed=GPIO_Speed_50MHz;//Port Speed set to 50MHz
  myGPIO.GPIO_OType=GPIO_OType_OD;//OperatingType set to OpenDrain
  myGPIO.GPIO_PuPd=GPIO_PuPd_NOPULL;//Pull-Up/Pull-Down set to Pull-Up
  GPIO_Init(GPIOB, &myGPIO);
  
  GPIO_PinAFConfig(GPIOB,GPIO_PinSource7,GPIO_AF_I2C1);//Set Pin7 to AF_I2C1 -->SDA
  GPIO_PinAFConfig(GPIOB,GPIO_PinSource8,GPIO_AF_I2C1);//Set Pin8 to AF_I2C1 -->SCL
  
  I2C_DeInit(I2C1);
  myI2C.I2C_ClockSpeed=100000;//ClockSpedd 100kHz
  myI2C.I2C_Mode=I2C_Mode_I2C;//Set Mode to I2C -not- to SMBusDevice or SMBusHost
  myI2C.I2C_DutyCycle=I2C_DutyCycle_2;//50% DutyCycle --> Standard
  myI2C.I2C_OwnAddress1=OWN_ADDRESS;//Set own Adress
  myI2C.I2C_Ack=I2C_Ack_Enable;//I2C Ack Enabled
  myI2C.I2C_AcknowledgedAddress=I2C_AcknowledgedAddress_7bit;//Run I2C on 7Bit-Address Mode
  
  I2C_Cmd(I2C1,ENABLE);//Peripheral enable 
  I2C_ITConfig(I2C1,I2C_IT_EVT | I2C_IT_BUF,ENABLE);
  I2C_Init(I2C1, &myI2C);//Apply configuration
  
  myNVIC.NVIC_IRQChannel=I2C1_EV_IRQn;
  myNVIC.NVIC_IRQChannelPreemptionPriority=0;
  myNVIC.NVIC_IRQChannelSubPriority=1;
  myNVIC.NVIC_IRQChannelCmd=ENABLE;
  NVIC_Init(&myNVIC);
  
}
/**
 * @brief  Interruptfunktion, die bei jedem Event aufgerufen wird,
 *              der bei dem Betrieb auftritt
 * @param  none
 * @retval none
 * @note   Je nachdem welcher Event auftritt, wird in den entsprechenden 
 *              case-Eintrag gesprungen. In der Funktion sind alle Events
 *              aufgelistet. Es muessen nicht alle Events verwendet werden.            
 **/
void I2C1_EV_IRQHandler(void)
{
    char data;
    GPIO_SetBits(GPIOD,GPIO_Pin_12);
    switch(I2C_GetLastEvent(I2C1))
    {
        /*EV1*/
        case I2C_EVENT_SLAVE_RECEIVER_ADDRESS_MATCHED:
            GPIO_SetBits(GPIOD,GPIO_Pin_13);
            I2C_vCleanADDR();
        break;
        /*EV2*/
        case I2C_EVENT_SLAVE_BYTE_RECEIVED:            
            data=I2C_ReceiveData(I2C1);
            if(data==68)
            {
                GPIO_SetBits(GPIOD,GPIO_Pin_14);
            }
        break;
        /*EV3*/
        case I2C_EVENT_SLAVE_BYTE_TRANSMITTED:
        break;
        /*EV3_2*/
        case I2C_EVENT_SLAVE_ACK_FAILURE:
        break;
        /*EV4*/
        case I2C_EVENT_SLAVE_STOP_DETECTED:
            GPIO_SetBits(GPIOD,GPIO_Pin_15);
            I2C_vCleanSTOPF();
        break;
    }
}
/**
 * @brief  Leert das ADDR-Register, um mit der Datenubertragung nach dem
 *         pruefen der Adresse.
 * @param  none
 * @retval none
 * @note   Weitere Infos in Manula Seite 579f.           
 **/
inline void I2C_vCleanADDR(void)
{
 
  while ((I2C1->SR1 & I2C_SR1_ADDR) == I2C_SR1_ADDR)
  {
    (void)I2C1->SR1;
    (void)I2C1->SR2;
  }
 
}
/**
 * @brief  Leert das STOPF-Register, um die Datenubertragung
 *         abzuschliessen.
 * @param  none
 * @retval none
 * @note   Weitere Infos in Manula Seite 579f.           
 **/
inline void I2C_vCleanSTOPF(void)
{
  while ((I2C1->SR1&I2C_SR1_STOPF) == I2C_SR1_STOPF)
  {
    (void)I2C1->SR1;
        I2C1->CR1 |= 0x1;
  }
}