#ifndef GPT_H_
#define GPT_H_
#include <stm32f446xx.h>
#include <stdint.h>

#define SR_UIF      (1U << 0UL) 

class gpt
{
    public:
    void init(void);
    void OutputCompare(void);
};

#endif
