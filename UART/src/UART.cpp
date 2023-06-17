#include <stm32f446xx.h>

#define GPIOAEN (1U << 0UL)
#define USART2EN (1U << 17UL) // write 1 to bit 17 to Enable USART2

void USART2_TX_INIT(void)
{
    /********** Config UART/USART GPIO pin **********/
        /*Enable clock access to GPIOA*/ 
        RCC->AHB1ENR |= GPIOAEN;
        
        /*Set PA2 to alternate function mode*/
        GPIOA->MODER &=~(1U << 4UL);
        GPIOA->MODER |= (1U << 5UL);

        /*Set PA2 alternate function to UART_TX (AFL7)*/
        GPIOA->AFR[0] |= (1U << 28UL);
        GPIOA->AFR[0] |= (1U << 29UL);
        GPIOA->AFR[0] |= (1U << 30UL);
        GPIOA->AFR[0] &=~(1U << 31UL);
        
    /********** Config UART/USART module **********/
        /*Config UART baudrate*/
        RCC->APB1ENR |= USART2EN; 

        /*Config the transfer direction*/
        /*Enable UART module*/

}
static void uart_set_baudrate(USART_TypeDef *UARTx,uint32_t PeripherialCLK, uint32_t Baudrat)
{
    UARTx->BRR = uart_div_compute(PeripherialCLK, PeripherialCLK);

}
static uint16_t uart_div_compute(uint32_t PeripherialCLK, uint32_t Baudrate)
{
    return ((PeripherialCLK + (Baudrate/2U))/Baudrate); 
}