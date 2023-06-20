
#ifndef UART_H_
#define UART_H_

#include <stm32f446xx.h>
#include <stdint.h>
// #include <stdio.h>
class UART
{
    public:
    void USART2_INIT(uint32_t baudRate);
    char uart_read(void);
    void uart_write(int data);
    void uart_write_string(const char *str);

};
#endif