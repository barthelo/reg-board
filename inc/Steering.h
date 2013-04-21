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

/*

#define MAX_PWM_PERCENT 11.115
#define MIN_PWM_PERCENT 5.5575
#define MEAN_PWM_Percent 8.33625
*/

void setupSteering();
void setPWM_Steering();
void STR_vsetAngle(int8_t);