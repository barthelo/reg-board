/**
 * *************************************************************************
 * @file     Adc.h
 * @author   Eugen Bartel
 * @version  V1.0
 * @date     17. April 2013
 * @brief    Diese Datei enthält die Deklarationen der Funktionen, der Variablen
 *              und die Präprozessoranweisungen, die bnoetigt werden, um den
 *              ADC betreiben.
 ******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ADC_H
#define __ADC_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "stm32f4xx_conf.h" 
#include "stm32f4xx_adc.h"
/* Exported types ------------------------------------------------------------*/
volatile uint16_t ADCConvertedValue[4];
/* Exported constants --------------------------------------------------------*/
#define ADC1_DR_ADDRESS ((uint32_t)0x4001204C) //ADC Regular Data Register of ADC1 (RM0090 p.307)
/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
void ADC_vInit(void);
uint16_t ADC_u16GetADCValue(char);

#endif /* __ADC_H */