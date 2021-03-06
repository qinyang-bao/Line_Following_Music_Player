/*
 * Test to see if can ouput different music notes - succeeded
 * Major break through!
 * Determined the algorithm and the corresponding "data structure" to output different notes within the confine of the limited memory of Arduino!
 */

//light sensors
int sensor_mid = A0;
int sensor_right = A1;
int sensor_left = A2;

//motorpins for motor driver
int motor_l_1 = 10;
int motor_l_2 = 11;
int motor_r_1 = 12;
int motor_r_2 = 13;

//output pins for R-2R bridge
//2,3,4,5,6,7,8,9;

int t = 0;
byte note = 0;
int period = 1000;
byte multi = 1;

//G3: 392Hz
//A3: 440Hz 
//B3: 493Hz 
//C4: 523Hz 
//D4: 587Hz 
//E4: 659Hz 
//F4: 698Hz 
//G4: 784Hz 

// values for 50 Hz 
byte base_f[800] =
{
127, 
127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 169, 170, 171, 172, 173, 174, 175, 
176, 177, 178, 179, 180, 181, 181, 182, 183, 184, 185, 186, 187, 188, 189, 189, 190, 191, 192, 193, 194, 195, 195, 196, 197, 198, 199, 199, 200, 201, 202, 203, 204, 204, 205, 206, 207, 207, 208, 209, 210, 210, 211, 212, 213, 213, 214, 215, 216, 216, 
217, 218, 218, 219, 220, 220, 221, 222, 222, 223, 224, 224, 225, 226, 226, 227, 227, 228, 229, 229, 230, 230, 231, 232, 232, 233, 233, 234, 234, 235, 235, 236, 236, 237, 237, 238, 238, 239, 239, 240, 240, 241, 241, 241, 242, 242, 243, 243, 243, 244, 
244, 245, 245, 245, 246, 246, 246, 247, 247, 247, 248, 248, 248, 248, 249, 249, 249, 249, 250, 250, 250, 250, 251, 251, 251, 251, 251, 252, 252, 252, 252, 252, 252, 252, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 
253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 252, 252, 252, 252, 252, 252, 251, 251, 251, 251, 251, 250, 250, 250, 250, 250, 249, 249, 249, 248, 248, 248, 248, 247, 247, 247, 246, 246, 246, 245, 245, 245, 244, 244, 
243, 243, 243, 242, 242, 241, 241, 241, 240, 240, 239, 239, 238, 238, 237, 237, 236, 236, 235, 235, 234, 234, 233, 233, 232, 232, 231, 230, 230, 229, 229, 228, 228, 227, 226, 226, 225, 224, 224, 223, 223, 222, 221, 221, 220, 219, 218, 218, 217, 216, 
216, 215, 214, 214, 213, 212, 211, 211, 210, 209, 208, 208, 207, 206, 205, 204, 204, 203, 202, 201, 200, 200, 199, 198, 197, 196, 196, 195, 194, 193, 192, 191, 190, 190, 189, 188, 187, 186, 185, 184, 183, 183, 182, 181, 180, 179, 178, 177, 176, 175, 
174, 173, 172, 172, 171, 170, 169, 168, 167, 166, 165, 164, 163, 162, 161, 160, 159, 158, 157, 156, 155, 154, 153, 152, 151, 150, 150, 149, 148, 147, 146, 145, 144, 143, 142, 141, 140, 139, 138, 137, 136, 135, 134, 133, 132, 131, 130, 129, 128, 127, 
126, 125, 124, 123, 122, 121, 120, 119, 118, 117, 116, 115, 114, 113, 112, 111, 110, 109, 108, 107, 106, 105, 104, 103, 102, 101, 100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 
77, 76, 75, 74, 74, 73, 72, 71, 70, 69, 68, 67, 66, 66, 65, 64, 63, 62, 61, 60, 59, 59, 58, 57, 56, 55, 54, 54, 53, 52, 51, 50, 50, 49, 48, 47, 47, 46, 45, 44, 43, 43, 42, 41, 40, 40, 39, 38, 38, 37, 
36, 35, 35, 34, 33, 33, 32, 31, 31, 30, 29, 29, 28, 28, 27, 26, 26, 25, 25, 24, 23, 23, 22, 22, 21, 20, 20, 19, 19, 18, 18, 17, 17, 16, 16, 15, 15, 14, 14, 13, 13, 13, 12, 12, 11, 11, 10, 10, 10, 9, 
9, 9, 8, 8, 7, 7, 7, 6, 6, 6, 5, 5, 5, 5, 4, 4, 4, 4, 3, 3, 3, 3, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 
9, 10, 10, 11, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15, 16, 16, 17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25, 25, 26, 27, 27, 28, 28, 29, 30, 30, 31, 32, 32, 33, 34, 34, 35, 36, 36, 
37, 38, 39, 39, 40, 41, 42, 42, 43, 44, 45, 45, 46, 47, 48, 48, 49, 50, 51, 52, 52, 53, 54, 55, 56, 56, 57, 58, 59, 60, 61, 62, 62, 63, 64, 65, 66, 67, 68, 69, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 
78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125
};


//darkest - lightest, every 2 adjacent values in the array defines the color range for a note
int color_range [16] =
{
 1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31
};

void setup()
{
  cli();//stop interrupts
  //setup input and output pins
  //set pin 2-7 as output, 1 as output (serial communication to pc), 0 as input (serial communication from pc to board)
  DDRD = DDRD | B11111110;
  
  //set pin 8-13 as outout
  DDRB = DDRB | B00111111;

  //set A0,A1,A2 as input
   DDRC = DDRC | B00000000;

   //setup timers for interrupt
   //Timer 1 - Output to R-2R bridge - speaker
   //set timer1 interrupt at 40000Hz
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0
  // set compare match register for 50000Hz increments
  OCR1A = 49;//  = (16*10^6) / (40000*8) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS11 bits for 8 prescaler
  TCCR1B |= (1 << CS11) ;  
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);

/*
//Timer 2 - Color Sensor Reading
   //set timer2 interrupt at 100Hz
  TCCR2A = 0;// set entire TCCR1A register to 0
  TCCR2B = 0;// same for TCCR1B
  TCNT2  = 0;//initialize counter value to 0
  // set compare match register for 50000Hz increments
  OCR2A = 156;//  = (16*10^6) / (100*1024) - 1 (must be <256)
  // turn on CTC mode
  TCCR2B |= (1 << WGM22);
  // Set CS11 bits for 1024 prescaler
  TCCR2B |= (1 << CS12) ;  
  // enable timer compare interrupt
  TIMSK2 |= (1 << OCIE2A);
 */
 
   Serial.begin(9600); 
   sei();//resume interrupts
}

void loop()
{
 color_to_note(30, note, period, multi);
 delay(5000);
  color_to_note(10, note, period, multi);
  delay(5000);
 
  //Serial.println(analogRead(A0)/4);
  //color_to_note(analogRead(A0), note, period, multi);
}

//interrupt commands for timer 1
ISR(TIMER1_COMPA_vect)
{
  
  t+=1;
  if(t==800) //40000/800= 50hz, base frequency
  t = 0;

//G3: 392Hz
//A3: 440Hz 
//B3: 493Hz 
//C4: 523Hz 
//D4: 587Hz 
//E4: 659Hz 
//F4: 698Hz 
//G4: 784Hz 

DAC(base_f[t%period * multi]);
/*
  switch (note)
  {
    case 1:
      DAC(base_f[index]);
      break;
    case 2:
      DAC(freq_multi ( t, 9));
      break;
    case 3:
      DAC(freq_multi ( t, 10));
      break;
    case 4:
      DAC(freq_multi ( t, 11));
      break;
    case 5:
      DAC(freq_multi ( t, 12));
      break;
    case 6:
      DAC(freq_multi (t, 13));
      break;
     case 7:
      DAC(freq_multi (t, 14));
      break;
      case 8:
      DAC(freq_multi (t, 16));
      break;
  }
  */
}

/*
//interrupt commands for timer2
ISR(TIMER2_COMPA_vect)
{
 color_to_note(30, note, period, multi);
}
*/

//takes in an interger from 1 - 255 analog value and converts it to digital signals
void DAC (byte desired_analog)
{
  PORTD = B00000010 | desired_analog << 2;
  PORTB = desired_analog >> 6;  
}

//G3: 392Hz
//A3: 440Hz 
//B3: 493Hz 
//C4: 523Hz 
//D4: 587Hz 
//E4: 659Hz 
//F4: 698Hz 
//G4: 784Hz 
//takes an analog value from the color sensor and set up for the corresponding note
void color_to_note (int color, byte & note, int & period, byte & multi)
{
  if (color_range[0]<= color && color_range[1]>= color)
  {
     note = 1;
     period = 125;//1000/8
     multi = 8;
     return;
  }
   
  else if (color_range[2]<= color && color_range[3]>= color)
  {
     note = 2;
     period = 111;//1000/9
     multi = 9;
     return;
   }
   
  else if (color_range[4]<= color && color_range[5]>= color)
  {
    note = 3;
    period = 100;//1000/10
     multi = 10;
     return;
  }
  
  else if (color_range[6]<= color && color_range[7]>= color)
  {
    note = 4;
    period = 91;//1000/11
     multi = 11;
     return;
  }
    
  else if (color_range[8]<= color && color_range[9]>= color)
  {
    note = 5;
    period = 83;//1000/12
     multi = 12;
     return;
  }
   
  else if (color_range[10]<= color && color_range[11]>= color)
  {
    note = 6;
    period = 77;//1000/13
     multi = 13;
     return;
  }
  
  else if (color_range[12]<= color && color_range[13]>= color)
  {
    note = 7;
    period = 71;// 1000/14
     multi = 14;
     return;
  }

  //if (color_range[14]<= color && color_range[15]>= color
  else 
  {
    note = 8;
    period = 63;// 1000/16
     multi = 16;
     return;
  }
}


