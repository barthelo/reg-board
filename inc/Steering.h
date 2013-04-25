/**
 * *************************************************************************
 * @file     Engine.h
 * @author   Eugen Bartel
 * @version  V1.0
 * @date     17. April 2013
 * @brief    Diese Datei enthält die Deklarationen der Funktionen, Variablen und
 * 		die Präprozessoranweisungen, die bnoetigt werden, um die
 * 		Lenkung zu betreiben.
 ******************************************************************************/

#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"

#define MAX_ANGLE 30
#define MIN_ANGLE -30
#define PWM_PERIOD 0.02 //Periode in Millisekunden (ms)

void STR_vSetAngle ( int8_t );