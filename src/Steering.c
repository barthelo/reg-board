/**
  ******************************************************************************
  * @file    Engine.c
  * @author  Eugen Bartel
  * @version V1.0
  * @date    17-April-2013
  * @brief   This file provides set of firmware functions to manage the Steering
  ******************************************************************************/
#include "Steering.h"

/**
 * @brief  Diese Funktion berechnet nach der Formel (y=79604*x-121)
 * 		die Einschaltdauer (PWM) in ms aus dem Winkel.
 * 		Nach der Berechnung wird die Einschaltzeit im Microcontroller
 * 		eingestellt.
 * @note	Die Formel wir in der Funktion nach der Variable x umgestellt
 * 		eingesetzt. Dabei ist y der Winkle in Grad. X ist die Eeinschaltzeit
 *		in Millisekunden.
 * @param  angle Winkel in dem die Reifen einschlagen. Bereich: -30°<=angle<=+30°
 * @retval none
 **/
void STR_vSetAngle(int8_t STR_i8Angle)
{
    float32_t STR_fDCycle=0;
    uint16_t STR_u16CCR=0;
    /*TODO*/uint16_t STR_u16ARR=0;
    //Pruefen, ob der Winkle den Bereich ueberschreitet. 
    //Bei Bedarf auf maximalwerte setzen.
    if(STR_i8Angle>MAX_ANGLE)
    {
        STR_i8Angle=MAX_ANGLE;
    }
    if(STR_i8Angle<MIN_ANGLE)
    {
        STR_i8Angle=MIN_ANGLE;
    }
    
    //Berechnen der neuen DutyCycle aus der Einschaltzeit
    STR_fDCycle=2*((((STR_i8Angle+10)+121)/79604.0)*100.0)/PWM_PERIOD;
    //Setzen der neuen DutyCycle
    /*TODO*/STR_u16CCR=(uint16_t)((STR_fDCycle/100.0)*(STR_u16ARR+1));
    TIM_SetCompare2(TIM3,STR_u16CCR);
}       