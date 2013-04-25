#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"

#include "Pwm.h"
#include "Engine.h"
#include "Steering.h"

int main(void)
{
  SystemInit();
  PWM_vInit();
  //ENG_vSetupEngine();
  //STR_vSetupSteering();
  //STR_vSetAngle(10);
  //ENG_vSetPwm(5.98);

  while(1);
}
