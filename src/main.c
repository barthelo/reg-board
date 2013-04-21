#include "stm32f4xx_conf.h"
#include "Engine.h"
#include "Steering.h"
 
int main(void)
{
  //setupEngine();
  setupSteering();
  STR_vsetAngle(-100);
  while(1);
}
