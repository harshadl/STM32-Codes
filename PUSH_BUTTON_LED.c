	/* Code to Turn on or off LED by a switch */

	#include "stm32f4xx.h"
	int main(void) {
		RCC->AHB1ENR |= 0x00000008; /* enable GPIOD clock */
		RCC->AHB1ENR |= 1; /*enable GPIOA clock */
		
		//GPIOA->MODER &= ~0x00000C00; /* clear pin mode */ 
		GPIOA->MODER |=0x00000000; /* set pin to INPUT mode */
		
	//	GPIOD->MODER &= ~0x55000000; /* clear pin mode */
    GPIOD->MODER |= 0x55000000; /* set pin to output mode */ 
		
	while(1) 
		{
			if (GPIOA->IDR & 0x00000001) /* if PCA0 is high */
					GPIOD ->BSRR = 0X0000F000; // SET PIN12,13,14,15 - TO TURN ON LED
		else
					GPIOD ->BSRR = 0XF0000000; // SET PIN12,13,14,15 - TO TURN off LED
		}
	}
	
	