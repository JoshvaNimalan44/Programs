// #define LEDS {}, \
//               {}, \

// typedef struct
// {
//   int LED1;
//   int LED2;
//   int LED3;
// } LED_st;

// LED_st LED[]={LEDS};

              


 int Button1 =0;
     int Button2 = 0;

void setup()
 {
    DDRB &= ~((1 << DDD2) | (1 << DDD3));  //  Input
    DDRB |= (1 << DDB5) | (1 << DDB4) | (1 << DDB3) | (1 << DDB2) | (1 << DDB1) | (1 << DDB0); // OUTPUT
   
 }

void loop()
{
   Button1 = digitalRead(2);
    Button2 = digitalRead(3);
  // if(Button1 == 1)
  // {
    do{
     Button2 == 0;
    digitalWrite(8,HIGH);
    
   delay(1000);
    digitalWrite(9,HIGH);
    digitalWrite(8,LOW);
    delay(1000);
   digitalWrite(10,HIGH);
   digitalWrite(9,LOW);
    delay(1000);
    digitalWrite(10,LOW);
    }while(Button2 != 1);
  //}
  // if(Button2 == 1)
  // {
     do{
    Button1 == 0;
  digitalWrite(11,HIGH);
    delay(1000);
    digitalWrite(12,HIGH);
     digitalWrite(11,LOW);
    delay(1000);
    digitalWrite(13,HIGH);
     digitalWrite(12,LOW);
    delay(1000);
    digitalWrite(13,LOW);
     }while(Button1 != 1);
  //}


}

