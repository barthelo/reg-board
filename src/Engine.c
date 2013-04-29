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
 * @brief  Setzt ein PWM am Motor
 * @note   DutyCycle =(TIM3_CCR1/ TIM3_ARR)* 100
 * @param  ENG_fDCycle Einschaltzeit in Prozent;
 * @retval none
 **/
void ENG_vSetDCycle(float ENG_fDCycle)
{
    PWM_u16CCR=(uint16_t)((ENG_fDCycle/100.0f)*(PWM_u16ARR+1));
    TIM_SetCompare1(TIM3,PWM_u16CCR);
}
