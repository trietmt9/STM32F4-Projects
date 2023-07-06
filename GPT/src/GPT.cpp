#include <GPT.h>
#include <stm32f446xx.h>
#include <stdint.h>

#define TIM2EN          (1U << 0UL)
#define CR1_CEN         (1U << 0UL)
#define OCRM1_TOGGLE    ((1U<<4UL)|(1U<<5UL)) // Output compare mode
#define CCER_CC1EN      (1U<<0UL) // Output capture/compare enable
#define AFR5_TIM2_CH1   (1U<<20UL)
void gpt::init(void)
{
    /*Enable clock access to timer2*/
    RCC->APB1ENR |= TIM2EN; 

    /*Set prescaler value*/
    TIM2->PSC = 1600 - 1; // 16MHz / 1600 = 10000

    /*Set auto reload value*/
    TIM2->ARR = 10000 - 1; //10000/10000 = 1Hz

    /*Clear counter*/
    TIM2->CNT = 0;

    /*Enable timer*/
    TIM2->CR1 = CR1_CEN;
}

void gpt::OutputCompare(void)
{
    /*Enalbe clock access to GPIOA*/
    RCC->AHB1ENR |= (1U<<0UL);

    /*Set PA5 to Altinate function mode*/
    GPIOA->MODER &=~(1U<<10UL);
    GPIOA->MODER |= (1U<<11UL);

    /*Set altinate function type to TIM2_CH1*/
    GPIOA->AFR[0] |= AFR5_TIM2_CH1;

    /*Enable clock access to timer2*/
    RCC->APB1ENR |= TIM2EN; 

    /*Set prescaler value*/
    TIM2->PSC = 1600 - 1; // 16MHz / 1600 = 10000

    /*Set auto reload value*/
    TIM2->ARR = 10000 - 1; //10000/10000 = 1Hz

    /*Set output Compare toggle mode*/
    TIM2->CCMR1 = OCRM1_TOGGLE;
    
    /*Enable TIM2 channel 1 in compare mode*/
    TIM2->CCER |= CCER_CC1EN;

    /*Clear counter*/
    TIM2->CNT = 0;

    /*Enable timer*/
    TIM2->CR1 = CR1_CEN;
}