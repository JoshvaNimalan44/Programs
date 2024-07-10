#include"Confg.h"

void _UART_RESET (void)
{
	
	CLK_CKDIVR =0x18;
  CLK_PCKENR1=0XFF; //Enable peripherial
	UART1_SR   =0XC0;
	UART1_BRR2 =0X00;
	UART1_BRR1 =0X00;
	UART1_CR3  =0X00;
	UART1_CR2  =0X00;
}


void _UART_SET (void)
{
	
	CLK_CKDIVR  = 0X00;               //set clock 16 Mhz
	UART1_BRR2 |= 0X03;
	UART1_BRR1 |= 0X68;               //9600
	UART1_CR3  &= ~((1<<4) | (1<<5)); //STOP BIT
	UART1_CR2  |= (1<<2) | (1<<3);    //ENABLING_TX AND RX
}

uchar j = 'J'; //TRANSMITTING DATA
uchar n = 'N'; //RECIEVING DATA


void _UART_TX (uchar data)
{
	
	  UART1_DR = data;
		while (!(UART1_SR & (1<<6)));
		
		if(data == j)
		{
			UART_RX_uch ();
		}
}

uchar UART_RX_uch (void)
{
	 
    while (!(UART1_SR & (1<<5)));
		 UART1_DR = n;
		 return UART1_DR;
}
