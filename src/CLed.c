/**
  ******************************************************************************
  * @file    CLed.c
  * @author  Eugen Bartel
  * @version V1.0
  * @date    25-May-2013
  * @brief   This file provides set of firmware functions CLed
  * 
  ******************************************************************************/
#include "CLed.h"

/**
 * @brief  Richtet die benoetigten Ports und Interrupts ein, die fuer
 *              den Betrieb benoetigt werden.
 * @param  none
 * @retval none
 **/
void LED_vInit(void)
{
    GPIO_InitTypeDef myGPIO;
    
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE);
    
    myGPIO.GPIO_Pin=LED1 | LED2 | LED3 | LED4;
    myGPIO.GPIO_Mode=GPIO_Mode_OUT;
    myGPIO.GPIO_OType=GPIO_OType_PP;
    myGPIO.GPIO_Speed=GPIO_Speed_100MHz;
    myGPIO.GPIO_PuPd=GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOD,&myGPIO);
}