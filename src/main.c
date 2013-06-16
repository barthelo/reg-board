#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"

#include "Pwm.h"
#include "Engine.h"
#include "Steering.h"
#include "Adc.h"
#include "Acc.h"
#include "Gyro.h"
#include "Siebensegment.h"
#include "I2c.h"
#include "CLed.h"

#define delay 0x005FFF
void Delay(__IO uint32_t nCount)
{
    while(nCount--)
    {
    }  
}

int main(void)
{
//     float x;
//     float y;
//     float z;
//     float w;
    SystemInit();
    LED_vInit();
//     PWM_vInit();
//     ADC_vInit();
//     SS_vInit();
    
    I2C_vInit();
  
//     ADC_SoftwareStartConv(ADC1);  
//     ENG_vSetDCycle(7.5);
//     STR_vSetAngle(0);
    
//     GPIO_SetBits(GPIOD,LED1);
//     GPIO_SetBits(GPIOD,LED2);
//     GPIO_SetBits(GPIOD,LED3);
//     GPIO_SetBits(GPIOD,LED4);

    while(1)
    {
//         x=ACC_fGetAcc('x');
//         y=ACC_fGetAcc('y');
//         z=ACC_fGetAcc('z');
//         w=GRY_fGetDps();

    }
}