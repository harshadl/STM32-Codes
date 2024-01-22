/* This program receives a character from UART4 receiver
* then sends it back through UART4 transmitter.
* UART4 is connected to PA0-Tx and PA1-Rx.
* A 3.3V signal level to USB cable is used to connect PA0/PA1 * to
the host PC COM port.
* PA0 - UART4 TX (AF8)
* PA1 - UART4 RX (AF8)
* Use Tera Term on the host PC to send keystrokes and observe the
display * of the characters echoed.
*
* By default, the clock is running at 16 MHz.
*
* This program was tested with Keil uVision v5.24a with DFP v2.11.0
*/
#include "stm32F4xx.h"
void UART4_init(void); 
void UART4_write(int c); 
void delayMs(int);
void LED_CNTRL(void);
char UART4_read(void);
char c;

int main (void) 
	{ 
		RCC->AHB1ENR |= 0x00000008; /* enable GPIOD clock */
		GPIOD->MODER |= 0x55000000; /* set pin to output mode */ 
	
		UART4_init();
			while (1) {
				c = UART4_read(); 
				UART4_write(c);
				LED_CNTRL();

			}
	}
	
	
/* initialize UART4 to transmit at 9600 Baud */
	

void UART4_init (void) 
	{
			RCC->AHB1ENR |= 1; /* Enable GPIOA clock */
			RCC->APB1ENR |= 0x80000; /* Enable UART4 clock */
			
		/* Configure PA0, PA1 for UART4 TX, RX */
			GPIOA->AFR[0] &= ~0x00FF;
			GPIOA->AFR[0] |= 0x0088; /* alt8 for UART4 */
			GPIOA->MODER &= ~0x000F;
			GPIOA->MODER |= 0x000A; /* enable alternate function for PA0, PA1 */
			UART4->BRR = 0x0683; /* 9600 baud @ 16 MHz */ 
			UART4->CR1 = 0x000C;/* enable Tx, Rx, 8-bit data */ 
			UART4->CR2 = 0x0000; /* 1 stop bit
			*/
			UART4->CR3 = 0x0000; /* no flow control */
			UART4->CR1 |= 0x2000; /*enable UART4 */
}
	
/* Write a character to UART4 */
		void UART4_write (int ch) {
		while (!(UART4->SR & 0x0080)) {} // wait until Tx buffer empty
			UART4->DR = (ch & 0xFF);
}
		
/* Read a character from UART4 */

char UART4_read(void) {
	
while (!(UART4->SR & 0x0020)) {} // wait until char arrives
return UART4->DR;
	
}

void LED_CNTRL()
{
					if(c=='G')
				{
					GPIOD ->BSRR = 0XF0000000; // SET PIN12 - TO TURN off LEDR
					GPIOD ->BSRR = 0X00001000; // SET PIN12 - TO TURN ON LED
				}
				else if(c =='O')
				{
					GPIOD ->BSRR = 0XF0000000; // SET PIN12 - TO TURN off LEDR
					GPIOD ->BSRR = 0X00002000; // SET PIN12 - TO TURN ON LED
				}
				else if(c =='R')
				{
					GPIOD ->BSRR = 0XF0000000; // SET PIN12 - TO TURN off LEDR
					GPIOD ->BSRR = 0X00004000; // SET PIN12 - TO TURN ON LED
				}
				else if(c =='B')
				{
					GPIOD ->BSRR = 0XF0000000; // SET PIN12 - TO TURN off LEDR
					GPIOD ->BSRR = 0X00008000; // SET PIN12 - TO TURN ON LED
				}
				else
					GPIOD ->BSRR = 0XF0000000; // SET PIN12 - TO TURN off LEDR
}