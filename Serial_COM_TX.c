/* p4_1.c Send a string "YES" to USART2*/
/*
* USART2 is connected to the ST-Link virtual COM port. * Use Tera
Term to see the message "YES" on a PC.
*
* By default, the clock is running at 16 MHz.
* The UART2 is configured for 9600 Baud.
* PA2 - USART2 TX (AF7)
*
* This program was tested with Keil uVision v5.24a with DFP v2.11.0
*/

#include "stm32F4xx.h"
void USART2_init(void); 
void USART2_write(int c); 
void delayMs(int);
/*------------------------------------------------------------------
---------MAIN function
*-------------------------------------------------------------------
---------*/ 
int main (void) {
USART2_init(); /* initialize USART2 */
while(1) { /* Loop forever */
USART2_write('Y');
USART2_write('e');
USART2_write('s');
USART2_write('\n');	
delayMs(1000); /* leave a gap between messages */
}
}

/*------------------------------------------------------------------
---------Initialize UART pins, Baudrate
*-------------------------------------------------------------------
---------*/ 

void USART2_init (void) {
RCC->AHB1ENR |= 1; /* Enable GPIOA clock */
RCC->APB1ENR |= 0x20000; /* Enable USART2 clock */
	
/* Configure PA2 for USART2_TX */
GPIOA->AFR[0] &= ~0x0F00;
GPIOA->AFR[0] |= 0x0700; /* alt7 for USART2 */
GPIOA->MODER &= ~0x0030;
GPIOA->MODER |= 0x0020; /* enable alternate function for PA2 */
USART2->BRR = 0x0683; /* 9600 baud @ 16 MHz */ 
USART2->CR1 = 0x0008;/* enable Tx, 8-bit data */ 
USART2->CR2 = 0x0000; /* 1 stop bit */
USART2->CR3 = 0x0000; /* no flow control */ 
USART2->CR1 |= 0x2000;/* enable USART2 */
}

void delayMs(int n) {
volatile int i;
for (; n > 0; n--)
	for (i = 0; i < 2000; i++) ; 
}

/* Write a character to USART2 */
void USART2_write (int ch) {
while (!(USART2->SR & 0x0080)) {} // wait until Tx buffer empty
USART2->DR = (ch & 0xFF);
}
