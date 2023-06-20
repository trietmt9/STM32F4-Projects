

#ifndef UART_H_
#define UART_H_

#include <stm32f446xx.h>
#include <stdint.h>
// #include <stdio.h>

// static void uart_set_baudrate(USART_TypeDef *UARTx, uint32_t PeripherialCLK, uint32_t Baudrate);
// static uint16_t uart_div_compute(uint32_t PeripherialCLK, uint32_t Baudrate);
class UART
{
    public:
    void USART2_INIT(uint32_t baudRate);
    char uart_read(void);
    void uart_write(int data);
    void uart_write_string(const char *str);
    void uart_set_baudrate(USART_TypeDef *UARTx,uint32_t PeripherialCLK, uint32_t Baudrate);
    uint16_t uart_div_compute(uint32_t PeripherialCLK, uint32_t Baudrate);

};

#endif