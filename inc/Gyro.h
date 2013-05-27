/**
 * *************************************************************************
 * @file     Acc.h
 * @author   Eugen Bartel
 * @version  V1.0
 * @date     17. April 2013
 * @brief    Diese Datei enthält die Deklarationen der Funktionen, der Variablen
 *              und die Praeprozessoranweisungen, die bnoetigt werden, um den
 *              Gyrosensor zu betreiben.
 ******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GRY_H
#define __GRY_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "stm32f4xx_conf.h" 
#include "Adc.h"
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
#define GRY_VREF 2928 //Anpassen um gewissen Offsetfehler zu kompensieren
/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
float GRY_fGetDps();
float GRY_fDpsOfVoltage(uint32_t);
#endif /* __GRY_H */