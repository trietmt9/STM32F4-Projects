#include <ADC.h>

#define GPIOAEN     (1U << 0UL)
#define ADC1EN      (1U << 8UL) // Enable ADC1 module
#define ADC_CH1     (1U << 0L) // Select channel 1 

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

    /*Conversion sequence length*/

    /*Enable ADC module*/
} 