/*
 * 80% duty cycle pwm
 */

int t = 0;
void setup()
{
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  
//Timer 2 - Color Sensor Reading
   //set timer2 interrupt at 100Hz
  TCCR2A = 0;// set entire TCCR1A register to 0
  TCCR2B = 0;// same for TCCR1B
  TCNT2  = 0;//initialize counter value to 0
  // set compare match register for 100Hz increments
  OCR2A = 156;//  = (16*10^6) / (100*1024) - 1 (must be <256)
  // turn on CTC mode
  TCCR2A |= (1 << WGM22);
  // Set CS11 bits for 1024 prescaler
  TCCR2B |= (1 << CS12) ;  
  // enable timer compare interrupt
  TIMSK2 |= (1 << OCIE2A);
}

//duty cycle 80%
ISR(TIMER2_COMPA_vect)
{
  t++;
  if(t == 100)
    t =0;
}

void loop()
{
  if(t < 80)
    digitalWrite(10, HIGH);
  else
    digitalWrite(10, LOW);
}
