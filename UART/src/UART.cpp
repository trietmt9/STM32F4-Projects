#include <stm32f446xx.h>

#define USART2EN (1U<<17UL) // write 1 to bit 17 to Enable USART2

void USART2_TX_INIT(void)
{
    /********** Config UART/USART GPIO pin **********/
    /*Enable clock access to GPIOA*/
    /*Config UART baudrate*/
    
    /*Set PA2 to alternate function mode*/
    /*Set PA2 alternate function to UART_TX*/

}