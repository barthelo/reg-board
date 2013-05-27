/**
 * *************************************************************************
 * @file     Acc.h
 * @author   Eugen Bartel
 * @version  V1.0
 * @date     17. April 2013
 * @brief    Diese Datei enthält die Deklarationen der Funktionen, der Variablen
 *              und die Praeprozessoranweisungen, die bnoetigt werden, um den
 *              Beschleunigungssensor zu betreiben.
 * @note        Der Wert fuer ACC_VDD sollte moeglichst genau gehalten werden,
 *              um exakte Ergebnisse zu bekommen.
 ******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ACC_H
#define __ACC_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "stm32f4xx_conf.h" 
#include "Adc.h"
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
#define GRAVITATIONAL_ACCELERATION 9.81//m/s^2
#define ACC_VDD 3300 //mV
/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
float ACC_fGetAcc(char);
float ACC_fAccelerationOfVoltage(uint32_t);

#endif /* __ACC_H */