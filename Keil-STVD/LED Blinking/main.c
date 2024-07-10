/* LED Blinking  
   main.c
 */
 
 
#include"address.h"


void delay(void);
void led(void);

void delay(void)
{
	int i;
	for(i=0;i<10000;i++)
	{
	}
}

void led(void)
{
	PD_DDR |=(1<<2);
	PD_ODR |=(1<<2);
	PD_CR1 |=(1<<2);
}

void main()
{
   led();
	while (1)
	{
		PD_ODR |=(1<<2);
		delay();
		PD_ODR &= ~(1<<2);
		delay();
	}
}