#include "stm32f4xx.h"
#include "stm32f4xx_conf.h" 

#define LED_A GPIO_Pin_4 
#define LED_B GPIO_Pin_5 
#define LED_C GPIO_Pin_6 
#define LED_D GPIO_Pin_7 
#define LED_E GPIO_Pin_8 
#define LED_F GPIO_Pin_9 
#define LED_G GPIO_Pin_10


void SS_vInit(void);
void SS_vPrint(uint8_t,uint8_t);