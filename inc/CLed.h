/**
 * *************************************************************************
 * @file     CLed.h
 * @author   Eugen Bartel
 * @version  V1.0
 * @date     27. Mai 2013
 * @brief    Diese Datei enthält die Deklarationen der Funktionen, der Variablen
 *              und die Praeprozessoranweisungen, die bnoetigt werden, um den
 *              die Kotroll-LED zu betreiben zu betreiben.
 * 
 ******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __CLed_H
#define __CLed_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "stm32f4xx_conf.h" 
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
#define LED1 GPIO_Pin_12
#define LED2 GPIO_Pin_13
#define LED3 GPIO_Pin_14
#define LED4 GPIO_Pin_15
/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
void LED_vInit(void);
#endif /* __CLed_H */