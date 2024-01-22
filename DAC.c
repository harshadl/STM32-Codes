
/* Vout = DOR x (VREF / 4096)

1v = DOR x (3.3 / 4096)

=>  DOR = 1241 */


#include "stm32f4xx.h"

void delay(void)
{
    volatile int i;
    for(i=0; i<5000 ;i++);
}


int main(void) {
	 uint32_t DAC_OUT[4] = {0, 1241, 2482, 3723};
    uint8_t i = 0;
int data;
RCC->AHB1ENR |= 1; /* enable GPIOA clock */
GPIOA->MODER |= 0x00000300; /* PA4 analog */
/* setup DAC */
RCC->APB1ENR |= 1 << 29; /* enable DAC clock */
DAC->CR |= 1; /* enable DAC */
while(1) {
DAC->DHR12R1 =  DAC_OUT[i++];
	 if(i == 4)
        {  
            i = 0;
        }
				delay();
}
}