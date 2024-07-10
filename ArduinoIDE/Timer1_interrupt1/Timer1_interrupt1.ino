// TIMER1 Compare Match Interrupt



/*
64 Prsclr

250 - 1ms
25000 - 100ms
*/

void setup() 
{
 
  DDRB |= (1 << DDB5);
  
  noInterrupts();
  TCCR1A = 0;
  TCCR1B = 0;
  TCCR1B |= (1 << CS11) |(1 << CS10); // prsclr 64
  TIMSK1 |= (1 << OCIE1A);
  OCR1A = 250; 
  interrupts();
}



ISR(TIMER1_COMPA_vect)
{
  OCR1A += 250;   //1 MS
  PORTB ^=(1 << PORTB5);
  
}

void loop()
{
}


