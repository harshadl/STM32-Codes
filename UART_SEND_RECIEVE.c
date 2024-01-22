#include "stm32F4xx.h"
void USART2_init(void); 
char USART2_read(void); 
void delayMs(int);

/*------------------------------------------------------------------
---------MAIN function
*-------------------------------------------------------------------
---------*/ 

int main (void) {
char c;
	RCC->AHB1ENR |= 0x00000008; /* enable GPIOD clock */		
	RCC->AHB1ENR |= 1; /* enable GPIOA clock */ 
			GPIOA->MODER &=~0x00000C00; /* clear pin mode */ 
			GPIOA->MODER |= 0x00000400; /* set pin to output mode */
			GPIOD->MODER |= 0x55000000; /* set pin to output mode */ 
USART2_init(); /* initialize USART2 */
	
while(1) { /* Loop forever */
c = USART2_read(); /* wait for a character received */ 
	if(c=='R')
	{
					GPIOD ->BSRR = 0X0000F000; // SET PIN12 - TO TURN ON LED
					delayMs(1000);
	}
	else
					GPIOD ->BSRR = 0XF0000000; // SET PIN12 - TO TURN off LED
  
}
}


/*------------------------------------------------------------------
---------Initialize UART pins, Baudrate
*-------------------------------------------------------------------
---------*/ void USART2_init (void) 
	{
		
		RCC->APB1ENR |= 0x20000; /* Enable USART2 clock */
		USART2->BRR = 0x008B; /* 115200 baud @ 16 MHz */ 
			USART2->CR1 = 0x0004; /* enable Rx, 8-bit data */ 
			USART2->CR2 = 0x0000; /* 1 stop bit */ 
			USART2->CR3 = 0x0000; /* no flow control */ 
			USART2->CR1 |= 0x2000; /* enable USART2 */
		
		/* Configure PA3 for USART2 RX */
		GPIOA->AFR[0] &= ~0xF000;
		GPIOA->AFR[0] |= 0x7000; /* alt7 for USART2 */
		GPIOA->MODER &= ~0x00C0;
		GPIOA->MODER |= 0x0080; /* enable alternate function for PA3 */

}



/* Read a character from USART2 */
	char USART2_read(void) {
	while (!(USART2->SR & 0x0020)) {} // wait until char arrives
	return USART2->DR;
}


	void delayMs(int n) 
		{
	int i;
	for (; n > 0; n--)
	for (i = 0; i < 2000; i++) ;
		}