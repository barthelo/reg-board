/**
  ******************************************************************************
  * @file    Adc.c
  * @author  Eugen Bartel
  * @version V1.0
  * @date    17-April-2013
  * @brief   This file provides set of firmware functions ACC_MEMS
  ******************************************************************************/
#include "Acc.h"

/**
 * @brief  Gibt die gemittelte Beschleunigung der gewaehlten Achse zurueck
 * @param  ACC_c16Axis Charakter, der die Achse angibt x,y oder z
 * @retval ACC_fAcceleration Beschleunigung in m/s^2
 **/
float ACC_fGetAcc(char ACC_cAxis)
{
    float ACC_fAcceleration;
    uint32_t ACC_u32ADC_Voltage;
    float ACC_fMeanAcc=0;
    uint16_t ACC_u16I;
    for(ACC_u16I=0;ACC_u16I<65000;ACC_u16I++)
    {
        ACC_u32ADC_Voltage=ADC_u16GetADCValue(ACC_cAxis)*3000/0xFFF;
        ACC_fMeanAcc=ACC_fMeanAcc+ACC_u32ADC_Voltage;
    }
    ACC_u32ADC_Voltage=ACC_fMeanAcc/ACC_u16I;
    ACC_fAcceleration=ACC_fAccelerationOfVoltage(ACC_u32ADC_Voltage);
    
    return ACC_fAcceleration;
}
/**
 * @brief  Berechnet aus der Spannug die Beschleunigung
 * @param  ACC_u16AdcVoltage Spannungswert aus dem ADC in Millivolt (mV)
 * @retval ACC_fAccValue Beschleunigung in m-pro-sekunde-quadrat m/s^2
 **/
float ACC_fAccelerationOfVoltage(uint32_t ACC_u32AdcVoltage)
{
    float ACC_fAccValue;
    ACC_fAccValue=(((ACC_VDD/2)-(float)ACC_u32AdcVoltage)*GRAVITATIONAL_ACCELERATION)/480.0;
    return ACC_fAccValue;
}