/**
  ******************************************************************************
  * @file    Adc.c
  * @author  Eugen Bartel
  * @version V1.0
  * @date    17-April-2013
  * @brief   This file provides set of firmware functions GRY_MEMS
  ******************************************************************************/
#include "Gyro.h"

/**
 * @brief  Berechnet Degree per Secodn aus der Spannung
 * @param  GRY_u32AdcVoltage Spannung, die aus dem ADC ausgelesen wurde
 * @retval GRY_fDps Winkelgeschwindigkeit(Degree per Second)
 **/
float GRY_fDpsOfVoltage(uint32_t GRY_u32AdcVoltage)
{
    float GRY_fDps;
    GRY_fDps=(GRY_u32AdcVoltage-1500.0)/(1.1);
    return GRY_fDps;
}
/**
 * @brief  Berechnet Degree per Secodn aus der Spannung
 * @param  GRY_u32AdcVoltage Spannung, die aus dem ADC ausgelesen wurde
 * @retval GRY_fDps Winkelgeschwindigkeit(Degree per Second)
 **/
float GRY_fGetDps()
{
    float GRY_fDps;
    uint32_t GRY_u32ADC_Voltage=0;
    GRY_u32ADC_Voltage=(uint32_t)ADC_u16GetADCValue('w')*GRY_VREF/0xFFF;
    GRY_fDps=GRY_fDpsOfVoltage(GRY_u32ADC_Voltage);
    
    return GRY_fDps;
}
