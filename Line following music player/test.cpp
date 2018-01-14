#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>

using namespace std;


 
void DAC (int desired_analog)
{
  int pin7 = desired_analog / 128;
  int pin6 = (desired_analog - pin7 * 128)/64;
  int pin5 = (desired_analog - pin7 * 128 - pin6 * 64) / 32;
  int pin4 = (desired_analog - pin7 * 128 - pin6 * 64 - pin5* 32)/16;
  int pin3 = (desired_analog - pin7 * 128 - pin6 * 64 - pin5* 32 - pin4 *16)/8;
  int pin2 = (desired_analog - pin7 * 128 - pin6 * 64 - pin5* 32 - pin4 *16 - pin3*8)/4;
  int pin1 = (desired_analog - pin7 * 128 - pin6 * 64 - pin5* 32 - pin4 *16 - pin3*8 - pin2*4 )/2;
  int pin0 = (desired_analog - pin7 * 128 - pin6 * 64 - pin5* 32 - pin4 *16 - pin3*8 - pin2*4 - pin1*2)/1;


  cout<<pin7<<pin6<<pin5<<pin4<<pin3<<pin2<<pin1<<pin0<<endl;
}

const double incre = 1/800.0; 
int main()
{
//	float sinvalue [628];
	
	ofstream fout("sinvalues.txt");
	for (int index = 0; index<800; index++)
	{
		
		fout<<fixed<<setprecision(2)<<int(127+127*sin(2*3.14*index*incre) )<<", ";
		if(index%50 ==0)
			fout<<endl;
	}
	 if(!(5^5))
	 cout<< "yes"<<endl;
	
	 
	return 0;
} 


  
/*
  int pin7 = desired_analog / 128;
  int pin6 = (desired_analog - pin7 * 128)/64;
  int pin5 = (desired_analog - pin7 * 128 - pin6 * 64) / 32;
  int pin4 = (desired_analog - pin7 * 128 - pin6 * 64 - pin5* 32) /16;
  int pin3 = (desired_analog - pin7 * 128 - pin6 * 64 - pin5* 32 - pin4 *16)/8;
  int pin2 = (desired_analog - pin7 * 128 - pin6 * 64 - pin5* 32 - pin4 *16 - pin3 *8)/4;
  int pin1 = (desired_analog - pin7 * 128 - pin6 * 64 - pin5* 32 - pin4 *16 - pin3 *8 - pin2*4 )/2;
  int pin0 = (desired_analog - pin7 * 128 - pin6 * 64 - pin5* 32 - pin4 *16 - pin3 *8 - pin2*4 - pin1*2)/1;

  if(pin7)
    digitalWrite(2,HIGH);
   if(pin6)
    digitalWrite(3,HIGH);
   if(pin5)
    digitalWrite(4,HIGH);
   if(pin4)
    digitalWrite(5,HIGH);
   if(pin3)
    digitalWrite(6,HIGH);
   if(pin2)
    digitalWrite(7,HIGH);
   if(pin1)
    digitalWrite(8,HIGH);
   if(pin0)
    digitalWrite(9,HIGH);
  */
