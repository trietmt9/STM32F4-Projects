#include <stm32f446xx.h>
#include <stdint.h>

#define GPIOAEN         (1U << 0UL)
#define USART2EN        (1U << 17UL) // write 1 to bit 17 to Enable USART2

#define UART_TE         (1U << 3UL)
#define UART_EN         (1U << 13UL) // Enable UART module

#define SR_TXE          (1U << 7UL)  // Status registor empty bit 

#define SYS_FREQ        16000000UL // Default system clock  
#define APB1_CLK        SYS_FREQ
#define UART_BAUDRATE   9600 



static void uart_set_baudrate(USART_TypeDef *UARTx,uint32_t PeripherialCLK, uint32_t Baudrate);
static uint16_t uart_div_compute(uint32_t PeripherialCLK, uint32_t Baudrate);
void uart_write(int data);
void USART2_TX_INIT(void);

void USART2_TX_INIT(void)
{
    /********** Config UART/USART GPIO pin **********/
        /*Enable clock access to GPIOA*/ 
        RCC->AHB1ENR |= GPIOAEN;
        
        /*Set PA2 to alternate function mode*/
        GPIOA->MODER &=~(1U << 4UL);
        GPIOA->MODER |= (1U << 5UL);

        /*Set PA2 alternate function to UART_TX (AFL7)*/
        GPIOA->AFR[0] |= (1U << 8UL);
        GPIOA->AFR[0] |= (1U << 9UL);
        GPIOA->AFR[0] |= (1U << 10UL);
        GPIOA->AFR[0] &=~(1U << 11UL);
        
    /********** Config UART/USART module **********/
        /*Config UART CLock*/
        RCC->APB1ENR |= USART2EN; 

        /*Config UART baudrate*/
        uart_set_baudrate(USART2, APB1_CLK, UART_BAUDRATE);
        
        /*Config the transfer direction*/
        USART2->CR1 = UART_TE;

        /*Enable UART module*/
        USART2->CR1 |= UART_EN;

}

void uart_write(int data)
{
    /*Make sure transmit data registor is empty*/
    while(!(USART2->SR & SR_TXE)){}
    
    /*Write to transmit data registor*/
    USART2->DR = (data & 0xFF);

}

static void uart_set_baudrate(USART_TypeDef *UARTx,uint32_t PeripherialCLK, uint32_t Baudrate)
{
    UARTx->BRR = uart_div_compute(PeripherialCLK, Baudrate);

}
static uint16_t uart_div_compute(uint32_t PeripherialCLK, uint32_t Baudrate)
{
    return ((PeripherialCLK + (Baudrate/2U))/Baudrate); 
}