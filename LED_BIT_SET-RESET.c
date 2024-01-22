#include "stm32f4xx.h"                  // Device header

void delay(void)
{
    volatile int i;
    for(i=0; i<500000 ;i++);
}


int main()
{
	RCC->AHB1ENR |=0x00000008;	//enable clock for PORTD
	GPIOD -> MODER &= 0X01000000; // SET MODE OF PIN12 AS OUTPUT
	GPIOD -> MODER |= 0X01000000; // SET MODE OF PIN12 AS OUTPUT
	
	
	while(1)
	{
		
		GPIOD ->BSRR = 0X00001000; // SET PIN12 - TO TURN ON LED
		delay();
		GPIOD ->BSRR = 0X10000000; // SET PIN12 - TO TURN off LED
		delay();
			
	}
	
}



