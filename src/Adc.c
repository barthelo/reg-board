/**
  ******************************************************************************
  * @file    Adc.c
  * @author  Eugen Bartel
  * @version V1.0
  * @date    17-April-2013
  * @brief   This file provides set of firmware functions ADC
  ******************************************************************************/
#include "Adc.h"

/**
 * @brief  Initialisiert den ADC mit DMA und den dazugehoerigen Ports
 * @param  none
 * @retval none
 **/
void ADC_vInit(void)
{       
    ADC_InitTypeDef ADC_InitStructure;
    ADC_CommonInitTypeDef ADC_CommonInitStructure;
    DMA_InitTypeDef DMA_InitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;

    /* Enable ADC1, DMA2 and GPIO clocks ****************************************/
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2 | RCC_AHB1Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);

    /* DMA2 Stream0 channel0 configuration **************************************/
    DMA_InitStructure.DMA_Channel = DMA_Channel_0;//Channelwahl
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;//Richtung des DMA Quelle-zu-Ziel
    DMA_InitStructure.DMA_BufferSize = 4;//Anzahl der Daten
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;//Erneuter beginn nach Durchlauf von DMA_BufferSize
    
    DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)&ADCConvertedValue;//Speicheradresse im Speicher
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;//Datenyp bzw. zu belegende Groesse im Speicher
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;//DMA_BufferSize mal Druchlauf des Speicher ab DMA_Memory0BaseAddr in DMA_MemoryDataSize_HalfWord Schritten  
    DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;//Uebertragung von Daten ohne von Interrupt unterbrochen zu werden
    
    
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)ADC1_DR_ADDRESS;//Speicherstelle des Inhalts vom periphaeren Geraet
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;//zu lesende Datetyp bzw. Groesse
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;//inkrementaler Druchlauf beim lesen 
    DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;//lesen von Daten ohne von Interrupt unterbrochen zu werden
    
    
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;//Prioritaet des Channels
    DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;//Zwischenspeicher aktivieren ja/nein
    DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_HalfFull;//Schwelle fuer Zwischenspeicher
    DMA_Init(DMA2_Stream0, &DMA_InitStructure);//Setzen der Einstellungen
    DMA_Cmd(DMA2_Stream0, ENABLE);//Aktivieren der gesetzten <einstellungen

    /* Configure ADC1 Channel1 - Channel3 pin as analog input ******************************/
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL ;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    /* ADC Common Init **********************************************************/
    ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;
    ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div2;
    ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;
    ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;
    ADC_CommonInit(&ADC_CommonInitStructure);

    /* ADC1 Init ****************************************************************/
    ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
    ADC_InitStructure.ADC_ScanConvMode = ENABLE;
    ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
    ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
    ADC_InitStructure.ADC_NbrOfConversion = 4;
    ADC_Init(ADC1, &ADC_InitStructure);

    /* ADC1 regular channel configuration *************************************/
    ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_3Cycles);
    ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 2, ADC_SampleTime_3Cycles);
    ADC_RegularChannelConfig(ADC1, ADC_Channel_3, 3, ADC_SampleTime_3Cycles);
    ADC_RegularChannelConfig(ADC1, ADC_Channel_4, 4, ADC_SampleTime_3Cycles);

    /* Enable DMA request after last transfer (Single-ADC mode) */
    ADC_DMARequestAfterLastTransferCmd(ADC1, ENABLE);

    /* Enable ADC3 DMA */
    ADC_DMACmd(ADC1, ENABLE);

    /* Enable ADC3 */
    ADC_Cmd(ADC1, ENABLE);
}
/**
 * @brief  Gibt den Spannungswert aus der ADC Umwandlung fuer die gewaehlte Achse
 * @param  ADC_c16Axis Charakter der gwuenschten Achse x,y oder z
 * @retval ADC_u16ADCValue 12Bit Wert, den der ADC Umgewandelt hat
 **/
uint16_t ADC_u16GetADCValue(char ADC_cAxis)
{
    uint16_t ADC_u16ADCValue;
    switch(ADC_cAxis)
    {
        case 'x':
            ADC_u16ADCValue=ADCConvertedValue[0];
            break;
        case 'y':
            ADC_u16ADCValue=ADCConvertedValue[1];
            break;
        case 'z':
            ADC_u16ADCValue=ADCConvertedValue[2];
            break;
        case 'w':
            ADC_u16ADCValue=ADCConvertedValue[3];
            break;
    }   
    
    return ADC_u16ADCValue;
}