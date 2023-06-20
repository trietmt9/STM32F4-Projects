#include <stm32f446xx.h>
#include <stdint.h>
#include <stdio.h>
#include <UART.h>
#include <ADC.h>

uint32_t sensor_value; 
UART Serial;

int main()
{   
    Serial.USART2_INIT(9600);
    PA1_ADC_INIT();
    adc_conversion();

    while(1)
    {   
        sensor_value = adc_read();
        Serial.uart_write_string("Sensor value: ");
        Serial.uart_write(sensor_value);

    }
}