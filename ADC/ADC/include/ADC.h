#ifndef ADC_H_
#define ADC_H_ 
#include <stm32f446xx.h>
#include <stdint.h> 

void PA1_ADC_INIT();
void adc_conversion();
uint32_t adc_read(void);

#endif