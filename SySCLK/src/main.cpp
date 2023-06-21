#include <stm32f446xx.h>
#include <SySCLK.h>
#include <UART.h>
#include <stdint.h>
#include <stdio.h>

#define GPIAEN      (1U << 0UL)
#define PA5         (1U << 5UL)
#define LEDPIN      PA5

UART Serial;
delay Delay;

int main()
{
    /*Enable Port A*/
    RCC->AHB1ENR |= GPIAEN;

    /*Setup pin PA5 mode*/
    GPIOA->MODER |= (1U << 10UL);
    GPIOA->MODER &= ~(1U << 11UL);

    Serial.USART2_INIT(9600);

    while (1)
    {
        GPIOA->ODR ^= LEDPIN;
        Serial.uart_write_string("LED is toggled\n\r");
        Delay.delayMs(100);

    }
    

}

