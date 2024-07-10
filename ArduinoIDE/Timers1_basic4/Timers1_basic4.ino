

void setup()

{

  DDRB |= (1 << DDB5);
  TCCR1A = 0;
  TCCR1B = 0;
  
}


void Timer1(int data)
{
   TCNT1 = data;
   TIFR1 |= (1 << TOV1); 
   TCCR1B |= (1 << CS10) | (1 << CS12); 
   while (!(TIFR1 & (1 << TOV1)));
   TIFR1 |= (1 << TOV1); 
   TCCR1B = 0;

}
void loop()
{
  
      PORTB |= 1 << PORTB5;
      Timer1(3035);

      PORTB &= ~(1 << PORTB5);
      Timer1(34285);

}