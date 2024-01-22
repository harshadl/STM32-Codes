#include "stm32f4xx.h"
/* LED's are connected to PD12, PD13, PD14,PD15*/
/* 16 MHz SYSCLK */
void delay_millisec(unsigned ms )
{
    unsigned ticks = (ms * (SystemCoreClock/ 8)) / 1000 ;

    SysTick->LOAD = ticks;
    SysTick->VAL = 0;
    SysTick->CTRL = SysTick_CTRL_ENABLE_Msk;

    while ((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) == 0);
    SysTick->CTRL = 0;
}

int main(void) 
{
	RCC->AHB1ENR |= 0x00000008; /* enable GPIOD clock */
	GPIOD->MODER |= 0x55000000; /* set pin to output mode */ 
	
	while(1) {
			GPIOD->ODR^= 0x0000F000; //TURN ALL 4 LEDS ON & OFF
			delay_millisec(500);
	}
}


