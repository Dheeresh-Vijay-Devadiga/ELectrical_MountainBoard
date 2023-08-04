#define RCPin 2
#include "CytronMotorDriver.h"
int RCValue;
int mvalue;

CytronMD motor1(PWM_DIR, 3, 4);  // PWM 1 = Pin 3, DIR 1 = Pin 4.
CytronMD motor2(PWM_DIR, 9, 10); // PWM 2 = Pin 9, DIR 2 = Pin 10.

void setup()
{
  Serial.begin(9600);
  pinMode(RCPin, INPUT);
}
void loop() 
{
  RCValue = pulseIn(RCPin, HIGH);
  Serial.print(RCValue);
 
  if (RCValue>=1450&&RCValue<=1600){
    
    mvalue = 0;
  }
  else {
    
   mvalue = map(RCValue, 1020, 1940,-225, 225);  // 225 is full throtel
   if (mvalue >= 225)
   {
    mvalue = 225;
    }
   if (mvalue <= -225)
   {
    mvalue = -225;
    }
  }
  motor1.setSpeed(mvalue);   
  motor2.setSpeed(mvalue);  
  Serial.print("   mvalue=");
  Serial.println(mvalue);
}
  
  
