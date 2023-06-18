#include <ADC.h>

#define GPIOAEN         (1U << 0UL)
#define ADC1EN          (1U << 8UL) // Enable ADC1 module

#define ADC_CH1         (1U << 0L) // Select channel 1 
#define ADC_SEQ_LEN_1       0x00
#define ADC_CR2_ON      (1U << 0UL)

#define ADC_SR_EOC      (1U << 1UL)

#define ADC_SWSTART  (1U << 30UL) // Enable conversion of regular channel

void PA1_ADC_INIT();
void adc_conversion();
uint32_t adc_read(void);

void PA1_ADC_INIT()
{
    /********** Config ADC GPIO pin **********/
    /*Enable clock access to GPIOA*/
    RCC->AHB1ENR |= GPIOAEN;

    /*Set alternative ADC function of PA1*/
    GPIOA->MODER |= (1U << 2UL);
    GPIOA->MODER |= (1U << 3UL);

    /********** Config ADC module**********/
    /*Enable clock access to ADC pin's port*/
    RCC->APB2ENR |= ADC1EN;

    /*Conversion sequence start*/
    ADC1->SQR3 = ADC_CH1;

    /*Conversion sequence length*/
    ADC1->SQR1 = ADC_SEQ_LEN_1;

    /*Enable ADC module*/
    ADC1->CR2 |= ADC_CR2_ON;
} 

void adc_conversion()
{
    /*Start ADC conversion*/
    ADC1->CR2 |= ADC_SWSTART; 

}

uint32_t adc_read(void)
{
    /*Wait for conversion completed*/
    while(!(ADC1->SR & ADC_SR_EOC)){}

    /*Read converted result*/
    return ADC1->DR;
}   