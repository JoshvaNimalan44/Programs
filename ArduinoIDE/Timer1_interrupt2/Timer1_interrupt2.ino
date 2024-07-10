// TIMER1 OVERFLOW Interrupt


/*
49911 - 1 sec
57723 - 0.5 sec
*/


void setup() 
{
 
  DDRB |= (1 << DDB5);
  
  noInterrupts();
  TCCR1A = 0;
  TCCR1B = 0;
  TCCR1B |= (1 << CS12) | (1 << CS10);
  TCNT1 = 57723;
  TIMSK1 |= (1 << TOIE1);
  interrupts();
}



ISR(TIMER1_OVF_vect)
{
  TCNT1 = 57723;   
  PORTB ^=(1 << PORTB5);
  
}


void loop()
{
}


