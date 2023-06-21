#ifndef ADC_H_
#define ADC_H_ 
#include <stm32f446xx.h>
#include <stdint.h> 

class adc
{
    public: 
    void ADC1_INIT();
    void conversion();
    uint32_t read(void);   
};


#endif