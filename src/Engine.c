/**
  ******************************************************************************
  * @file    Engine.c
  * @author  Eugen Bartel
  * @version V1.0
  * @date    17-April-2013
  * @brief   This file provides set of firmware functions to manage the Engine
  ******************************************************************************/
#include "Engine.h"

/**
 * @brief  Initialisiert den Port an dem der Motor angeschlossen ist. Ausserdem
 * 		werden Timer und PWM initialisiert, um den Motor zu betreiben.
 * @param  none
 * @retval none
 **/
void setupEngine()
{
  TIM_TimeBaseInitTypeDef myTIM;
  GPIO_InitTypeDef myGPIO_TIM;
  TIM_OCInitTypeDef myTIM_OC;

  
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
  
  //GPIO's konfigurieren
  myGPIO_TIM.GPIO_Pin=GPIO_Pin_6;
  myGPIO_TIM.GPIO_Mode=GPIO_Mode_AF;
  myGPIO_TIM.GPIO_Speed=GPIO_Speed_100MHz;
  myGPIO_TIM.GPIO_OType=GPIO_OType_PP;
  myGPIO_TIM.GPIO_PuPd=GPIO_PuPd_UP;
  GPIO_Init(GPIOA,&myGPIO_TIM);
  
  GPIO_PinAFConfig(GPIOA,GPIO_PinSource6,GPIO_AF_TIM3);
  
  //Timerwerte konfigurieren
  myTIM.TIM_Period=(10000/50)-1; // ARR = (TIM3 counter clock / TIM3 output clock) - 1 
  myTIM.TIM_Prescaler=((SystemCoreClock /2) / 10000) - 1; //Prescaler = ((SystemCoreClock /2) / 1MHz) - 1 
  myTIM.TIM_ClockDivision=TIM_CKD_DIV1;
  myTIM.TIM_CounterMode=TIM_CounterMode_Up;
  TIM_TimeBaseInit(TIM3,&myTIM);
  
  //1 Kanal konfigurieren
  myTIM_OC.TIM_OCMode=TIM_OCMode_PWM1;
  myTIM_OC.TIM_OutputState=TIM_OutputState_Enable;
  myTIM_OC.TIM_Pulse=30;
  myTIM_OC.TIM_OCPolarity=TIM_OCPolarity_High;
  TIM_OC1Init(TIM3,&myTIM_OC);
  TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);
  

  TIM_ARRPreloadConfig(TIM3, ENABLE);
  TIM_Cmd(TIM3,ENABLE);
}