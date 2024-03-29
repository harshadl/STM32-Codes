#include "stm32f4xx.h"
int main(void) 
	{
// configure PA5 as output to drive the LED
	RCC->AHB1ENR |= 0x00000008; /* enable GPIOD clock */
	GPIOD->MODER &= ~0x55000000; /* clear pin mode */
	GPIOD->MODER |= 0x55000000; /* set pin to output mode */ 
	
	
	// configure TIM2 to wrap around at 1 Hz*/
		
  RCC->APB1ENR |= 1; /* enable TIM2 clock */ 
	TIM2->PSC = 1600 - 1; /* divided by 1600 */ 
	TIM2->ARR = 10000 - 1; /* divided by 10000 */
  TIM2->CNT = 0; /* clear timer counter */ 
	TIM2->CR1 = 1; /* enable TIM2 */
  while (1) {
       while(!(TIM2->SR & 1)) {} /* wait until UIF set */ 
			TIM2->SR &= ~1; /* clear UIF */ 
			GPIOD->ODR^= 0x0000F000; /* toggle green LED */
}}