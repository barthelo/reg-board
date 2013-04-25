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
void ENG_vSetDCycle(float32_t ENG_fDCycle)
{
    uint16_t ENG_u16ARR=0;
    uint16_t ENG_u16CCR=0;
    ENG_u16CCR=(uint16_t)((ENG_fDCycle/100.0)*ENG_u16ARR);
    TIM_SetCompare1(TIM3,ENG_u16CCR);
}
