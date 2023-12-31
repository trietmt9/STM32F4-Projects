#include <stm32f4xx.h>
#include <stdint.h>
#include <stdio.h>
#include <UART.h>

#define GPIOAEN     (1U << 0UL)
#define GPIOA_P5    (1U << 5UL)
#define LED_PIN     GPIOA_P5


char input;
UART Serial;
int main()
{

    /*Setup Pin Clock*/
    RCC->AHB1ENR |= GPIOAEN;

    /*Setup mode for PA5*/
    GPIOA->MODER |= (1U << 10UL);
    GPIOA->MODER &=~(1U << 11UL);


    Serial.USART2_INIT(9600);


    while(1)
    {

        input = Serial.uart_read();
        if(input == '1')
        {
            GPIOA->BSRR |= LED_PIN;
            Serial.uart_write_string("LED is on\n\r");
        }
        else if(input == '2')
        {
            GPIOA->BSRR |= (LED_PIN << 16UL);
            Serial.uart_write_string("LED is off\n\r");
        }
        else if(input == '3')
        {
            GPIOA->ODR ^= LED_PIN;
            Serial.uart_write_string("LED is toggled\n\r");
        }
        
    }
}