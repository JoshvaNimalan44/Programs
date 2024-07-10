/*
   UART TX AND RX
*/

#include"Confg.h"

void main (void)
{
	_UART_RESET ();
  _UART_SET ();
	
	while(1)
	{
    _UART_TX ('J');
	}
}