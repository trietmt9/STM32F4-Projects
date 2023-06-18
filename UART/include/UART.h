
#ifndef UART_H_
#define UART_H_

void uart_set_baudrate(USART_TypeDef *UARTx, uint32_t PeripherialCLK, uint32_t Baudrate);
uint16_t uart_div_compute(uint32_t PeripherialCLK, uint32_t Baudrate);
void uart_write(int data);
void USART2_TX_INIT(void);

#endif