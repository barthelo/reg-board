#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"

#include "Pwm.h"
#include "Engine.h"
#include "Steering.h"

int main(void)
{
  SystemInit();
  PWM_vInit();
  ENG_vSetDCycle(8.8);

  while(1);
}
