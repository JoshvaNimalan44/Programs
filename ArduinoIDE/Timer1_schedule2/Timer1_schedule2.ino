// TIMER1 Task Schedules 2


#define TASKS {Task1}, \
              {Task2}, \
              {Task3}

/*
6250-100MS  63-1MS  256
1562  200MS   1024
*/

typedef struct
{
  void (*fptr) (void);
  int value;
}Schedule;
Schedule pre;



void setup() {

  DDRB |=(1 << DDB5) | (1 << DDB4) | (1 << DDB3);

  noInterrupts();
  pre.value = 6250;

  TCCR1A = 0;
  TCCR1B = 0;

  TCCR1B |= (1 << CS12); //| (1 << CS10);
  TIMSK1 |= (1 << OCIE1A); 
  OCR1A = pre.value;
  interrupts();
}


void Task1() 
{
  PORTB |= (1 << 5);
  PORTB &= ~((1 << 4) | (1 << 3));
}

void Task2() 
{
  PORTB |= (1 << 4);
  PORTB &= ~((1 << 5) | (1 << 3));
}

void Task3() 
{
  PORTB |= (1 << 3);
  PORTB &= ~((1 << 5) | (1 << 4));
}

ISR(TIMER1_COMPA_vect)
{

  OCR1A += pre.value;
  static int Count = 0;
  Schedule data[] = {TASKS};
  
  data[Count].fptr(); 
  Count++;

  int size = sizeof(data) / sizeof(data[0]);
  if(Count >= size)
   {
    Count = 0; 
   }
}

void loop()
{
}
