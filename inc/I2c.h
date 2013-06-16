/**
 * *************************************************************************
 * @file     I2c.h
 * @author   Eugen Bartel
 * @version  V1.0
 * @date     27. Mai 2013
 * @brief    Diese Datei enthält die Deklarationen der Funktionen, der Variablen
 *              und die Praeprozessoranweisungen, die bnoetigt werden, um den
 *              I2C Bus als SLAVE zu betreiben zu betreiben.
 * 
 * @note        I2C WIRD ALS SLAVE BETRIEBEN
 ******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __I2c_H
#define __I2c_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "stm32f4xx_conf.h" 
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
#define OWN_ADDRESS 0x02
/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
void I2C_vInit(void);
void I2C1_EV_IRQHandler(void);
inline void I2C_vCleanADDR(void);
inline void I2C_vCleanSTOPF(void);
#endif /* __I2c_H */