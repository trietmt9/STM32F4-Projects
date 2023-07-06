#include <SySCLK.h>

#define SYSTICK_LOAD_VAL        16000
#define SYSTICK_EN              (1U << 0UL)
#define SYSTICK_CLKSRC          (1U << 2UL)
#define SYSTICK_CNTFLAG         (1U << 16UL)


void delay::delayMs(int delay)
{
    /*Configure systick*/
    /*Reload with number of clk per millisecond*/
    SysTick->LOAD = SYSTICK_LOAD_VAL;

    /*Clear SysTick current value register */
    SysTick->VAL = 0;
    
    /*Enable systick and select internal clk source*/
    SysTick->CTRL = SYSTICK_EN | SYSTICK_CLKSRC;

    for (int i = 0; i < delay; i++){
        while ((SysTick->CTRL & SYSTICK_CNTFLAG) == 0){}
    }
    /*Wait for coutner flag is set*/
    SysTick->CTRL = 0;

}
