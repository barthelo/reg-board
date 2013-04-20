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

#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"

void setupEngine();
void setPWM_Engine();
void setVilocity();
void accelerate_without_Slippage();