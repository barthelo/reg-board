#include "Siebensegment.h"

void SS_vInit(void)
{
 
    GPIO_InitTypeDef myGPIO_TIM;
    
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC,ENABLE);

    //**********GPIO's konfigurieren
    myGPIO_TIM.GPIO_Pin=GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10;
    myGPIO_TIM.GPIO_Mode=GPIO_Mode_OUT;
    myGPIO_TIM.GPIO_Speed=GPIO_Speed_100MHz;
    myGPIO_TIM.GPIO_OType=GPIO_OType_PP;
    myGPIO_TIM.GPIO_PuPd=GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOC,&myGPIO_TIM);

}
void SS_vPrint(uint8_t SS_u8Number,uint8_t SS_u8Digit)
{
    GPIO_SetBits(GPIOC,GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10);
    GPIO_ResetBits(GPIOC,GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3);
    
    switch(SS_u8Digit)
    {
        case 1:             
            GPIO_SetBits(GPIOC, GPIO_Pin_0); 
            break;
        case 2:
            GPIO_SetBits(GPIOC, GPIO_Pin_1); 
            break;
        case 3: 
            GPIO_SetBits(GPIOC, GPIO_Pin_2);
            break;
        case 4:
            GPIO_SetBits(GPIOC, GPIO_Pin_3);
            break;
    }
    switch(SS_u8Number)
    {
        case 11:
            GPIO_SetBits(GPIOC,GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10);
            break;
        case 10:
            GPIO_ResetBits(GPIOC,LED_G);
            break;
        case 0: 
            GPIO_ResetBits(GPIOC, LED_A | LED_B | LED_C | LED_D | LED_E | LED_F);
            break;
        case 1: 
            GPIO_ResetBits(GPIOC, LED_B | LED_C);
            break;
        case 2: 
            GPIO_ResetBits(GPIOC, LED_A | LED_B | LED_G | LED_D | LED_E);
            break;
        case 3: 
            GPIO_ResetBits(GPIOC, LED_A | LED_B | LED_C | LED_D | LED_G);
            break;
        case 4: 
            GPIO_ResetBits(GPIOC, LED_B | LED_C | LED_F | LED_G);
            break;
        case 5: 
            GPIO_ResetBits(GPIOC, LED_A | LED_F | LED_G | LED_C | LED_D);
            break;
        case 6: 
            GPIO_ResetBits(GPIOC, LED_A | LED_F | LED_G | LED_E | LED_D | LED_C);
            break;
        case 7: 
            GPIO_ResetBits(GPIOC, LED_A | LED_B | LED_C);
            break;
        case 8: 
            GPIO_ResetBits(GPIOC, LED_A | LED_B | LED_C | LED_D | LED_E | LED_F | LED_G);
            break;
        case 9: 
            GPIO_ResetBits(GPIOC, LED_A | LED_B | LED_C | LED_D | LED_F | LED_G);
            break;
    }
}