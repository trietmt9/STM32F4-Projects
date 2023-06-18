#include <stm32f446xx.h>
#include <stdint.h>
#include <stdio.h>
#include <UART.h>
#include <ADC.h>

uint32_t sensor_value; 

int main()
{   
    USART2_INIT();
    PA1_ADC_INIT();
    adc_conversion();

    while(1)
    {   
        sensor_value = adc_read();
        uart_write_string("Sensor value: ");
        uart_write(sensor_value);

    }
}