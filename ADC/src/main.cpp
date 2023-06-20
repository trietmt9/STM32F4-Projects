#include <stm32f446xx.h>
#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <UART.h>
#include <ADC.h>
using namespace std;

uint32_t sensor_value; 
UART Serial;

int main()
{   
    Serial.USART2_INIT(115200);
    PA1_ADC_INIT();

    while(1)
    {  
        char buffer[16]; 
        adc_conversion();
        sensor_value = adc_read();
        sprintf(buffer, "ADC value: %hu\n",sensor_value);
        Serial.uart_write_string(buffer);
    }
}