// TIMER1 Task Schedules


void setup() {

  DDRB |=(1 << DDB5) | (1 << DDB4) | (1 << DDB3);

  TCCR1A = 0;
  TCCR1B = 0;

}
void Time_()
{
  TCNT1 = 63972;   // 100ms
  TIFR1 |= (1 << TOV1);
  TCCR1B |= (1 << CS12) | (1 << CS10);
  while(!(TIFR1 & (1 << TOV1)));
  TIFR1 |= (1 << TOV1);
  TCCR1B = 0;
}

void Task1()
{
  Time_();
  PORTB |= (1 << 5);
  PORTB &= ~(1 << 3);
  Task2();
  
}

void Task2()
{
  Time_();
  PORTB &= ~(1 << 5);
  PORTB |= (1 << 4);
  Task3();
  
}

void Task3()
{
  Time_();
  PORTB &= ~(1 << 4);
  PORTB |= (1 << 3);
  Task1();
  
}

void loop() 
{
  Task1();
}
