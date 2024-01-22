#include "stm32f4xx.h"

int main(void) {
RCC->AHB1ENR |= 0x00000008; /* enable GPIOD clock */
GPIOD->MODER &= ~0x55000000; /* clear pin mode */
GPIOD->MODER |= 0x55000000; /* set pin to output mode */ /*
Configure SysTick */
SysTick->LOAD = 3200000 - 1; /* reload with number of clocks per second */ 
SysTick->VAL = 0;
SysTick->CTRL = 5; /* enable it, no interrupt, use system clock */
while (1) {
if (SysTick->CTRL & 0x10000) { /* if COUNT flag is set */ 
	GPIOD->ODR^= 0x0000F000; /* toggle green LED */
}
}
}
