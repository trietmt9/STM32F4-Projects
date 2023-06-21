#include <stm32f446xx.h>
#include <stdint.h>
#include <stdio.h>
#include <UART.h>
#include <ADC.h>

using namespace std;

uint32_t sensor_value; 
UART Serial;
adc Analog; 

int main()
{   
    Serial.USART2_INIT(115200);
    Analog.ADC1_INIT();
    Analog.conversion();
    while(1)
    {  
        char buffer[16]; 
        sensor_value = Analog.read();
        sprintf(buffer, "ADC value: %hu\n",sensor_value);
        Serial.uart_write_string(buffer);
    }
}