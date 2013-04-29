#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"

#include "Pwm.h"
#include "Engine.h"
#include "Steering.h"

int main(void)
{
  SystemInit();
  PWM_vInit();
  ENG_vSetDCycle(7.5);
  STR_vSetAngle(0);

  while(1);
}