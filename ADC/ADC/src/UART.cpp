#include <UART.h>

#define GPIOAEN         (1U << 0UL)
#define USART2EN        (1U << 17UL)  // write 1 to bit 17 to Enable USART2

#define UART_TE         (1U << 3UL)
#define UART_RE         (1U << 2UL)
#define UART_EN         (1U << 13UL) // Enable UART module

#define SR_TXE          (1U << 7UL)  // Status registor empty bit 
#define SR_RXNE         (1U << 5UL)  // Status registor is not empty bit 

#define SYS_FREQ        16000000UL   // Default system clock  
#define APB1_CLK        SYS_FREQ
#define UART_BAUDRATE   9600 



void uart_set_baudrate(USART_TypeDef *UARTx,uint32_t PeripherialCLK, uint32_t Baudrate);
uint16_t uart_div_compute(uint32_t PeripherialCLK, uint32_t Baudrate);
void uart_write(int data);
void uart_write_string(const char *str);
char uart_read(void);

int __io_putchar(int data)
{
    uart_write(data);
    return data;
}

void USART2_INIT(void)
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
        
        /*Set PA3 to alternate function mode*/
        GPIOA->MODER &=~(1U << 6UL);
        GPIOA->MODER |= (1U << 7UL);

        /*Set PA3 alternate function to UART_RX (AFL7)*/
        GPIOA->AFR[0] |= (1U << 12UL);
        GPIOA->AFR[0] |= (1U << 13UL);
        GPIOA->AFR[0] |= (1U << 14UL);
        GPIOA->AFR[0] &=~(1U << 15UL);

    /********** Config UART/USART module **********/
        /*Config UART CLock*/
        RCC->APB1ENR |= USART2EN; 

        /*Config UART baudrate*/
        uart_set_baudrate(USART2, APB1_CLK, UART_BAUDRATE);
        
        /*Config the transfer direction*/
        USART2->CR1 = (UART_TE | UART_RE);


        /*Enable UART module*/
        USART2->CR1 |= UART_EN;

}

char uart_read(void)
{
    /*Make sure receive data registor is not empty*/
    while(!(USART2->SR & SR_RXNE)){}

    /*Return data*/
    return USART2->DR;



}

void uart_write(int data)
{
    /*Make sure transmit data registor is empty*/
    while(!(USART2->SR & SR_TXE)){}
    
    /*Write to transmit data registor*/
    USART2->DR = (data & 0xFF);

}

void uart_write_string(const char *str)
{
    while (*str != '\0') {
    uart_write(*str++);
    }
}

void uart_set_baudrate(USART_TypeDef *UARTx,uint32_t PeripherialCLK, uint32_t Baudrate)
{
    UARTx->BRR = uart_div_compute(PeripherialCLK, Baudrate);

}
uint16_t uart_div_compute(uint32_t PeripherialCLK, uint32_t Baudrate)
{
    return ((PeripherialCLK + (Baudrate/2U))/Baudrate); 
}