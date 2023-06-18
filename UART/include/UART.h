

#ifndef UART_H_
#define UART_H_

#include <stm32f446xx.h>
#include <stdint.h>
// #include <stdio.h>

// static void uart_set_baudrate(USART_TypeDef *UARTx, uint32_t PeripherialCLK, uint32_t Baudrate);
// static uint16_t uart_div_compute(uint32_t PeripherialCLK, uint32_t Baudrate);
void uart_write_string(const char *str);
void uart_write(int data);
char uart_read(void);
void USART2_INIT(void);

#endif