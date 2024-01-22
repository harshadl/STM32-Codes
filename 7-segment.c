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
			{
				GPIOD ->BSRR = 0X70000000; // 
				GPIOD ->BSRR = 0X00006000; // SET PIN12,13 to SHOW VALUE "1"
			    
			}
		else
			{
				  GPIOD ->BSRR = 0X60000000; 
					GPIOD ->BSRR = 0X00007000; // SET PIN12,13,14 - TO show VALUE "7"
		     
			}
		}
	}
	
	