#include <stm32f4xx.h>
#include <UART.h>

int main()
{
    USART2_TX_INIT();

    while(1)
    {
        uart_write('Y');
    }
}