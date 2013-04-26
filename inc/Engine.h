/**
 * *************************************************************************
 * @file     Engine.h
 * @author   Eugen Bartel
 * @version  V1.0
 * @date     17. April 2013
 * @brief    Diese Datei enthält die Deklarationen der Funktionen, der Variablen
 *		und die Präprozessoranweisungen, die bnoetigt werden, um den
 * 		Brushless-Motor zu betreiben.
 ******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ENGINE_H
#define __ENGINE_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"
#include "arm_math.h"
#include "Pwm.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
void ENG_vSetDCycle(float32_t);
void setVilocity();
void accelerate_without_Slippage();

#endif /* __ENGINE_H */