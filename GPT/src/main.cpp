#include <stm32f446xx.h>
#include <GPT.h> 
#include <UART.h>

#define GPIOAEN     (1U << 0UL)
#define PIN5        (1U << 5UL)
#define LEDPIN      PIN5

gpt Timer;
UART Serial;

int main()
{
    /*======== Normal timer setup ========*/
    // RCC->AHB1ENR |= GPIOAEN;
    
    // GPIOA->MODER |= (1U << 10UL);
    // GPIOA->MODER &= ~(1U << 11UL);

    // Serial.USART2_INIT(115200);
    // Timer.init();

/*======== Output Compare timer setup ========*/
    Timer.OutputCompare();

    while (1)
    {
        // /*Wair for UIF*/
        // while(!(TIM2->SR & SR_UIF)){}

        // /*Clear UIF*/
        // TIM2->SR &= ~SR_UIF;

        // GPIOA->ODR ^= LEDPIN;
        // Serial.uart_write_string("1 second passed\n\r");
    }
    

}