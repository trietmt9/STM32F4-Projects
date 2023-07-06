#include <GPT.h>
#include <stm32f446xx.h>
#include <stdint.h>

#define TIM2EN      (1U << 0UL)
#define CR1_CEN     (1U << 0UL)

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