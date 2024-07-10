#include <avr/io.h>


int main() {
  DDRB |= (1 << DDB5);                   // Set pin 5 of port B as output
  DDRB &= ~((1 << DDB4) | (1 << DDB3));  // Set pins 4 and 3 of port B as input

  PORTB |= (1 << PORTB4);  // Enable pull-up resistor on pin 4
  PORTB |= (1 << PORTB3);  // Enable pull-up resistor on pin 3

  int Input1 = (PINB & (1 << PINB4)) >> PINB4;  // Read the state of pin 4 and store it in 'Input1'
  int Input2 = (PINB & (1 << PINB3)) >> PINB3;  // Read the state of pin 3 and store it in 'Input2'



  while (1) 
  {
    if (Input1 == 1) {
      PORTB |= (1 << DDB5);  // If pin 4 is high, set pin 5 high
    }

    if (Input2 == 1) {
      PORTB &= ~(1 << DDB5);  // If pin 3 is high, set pin 5 low
    }
  }
  return 0;
}
