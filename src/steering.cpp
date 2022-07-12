#include "steering.h"

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
int CurrentPosition = 500;
int CurrentFreq = 500;
bool PositionNotTooHigh(double position)
{
  if(position<=100)
    return true;

  Serial.print("Position is too high: ");
  Serial.println(position);
  return false;
}

void SetPosition(uint8_t n, double position)
{
  if (PositionNotTooHigh(position))
  {
    int targetFreq = (((SERVOMAX-SERVOMIN)/100)*position)+SERVOMIN;
    if(CurrentPosition<targetFreq)
    {
      for(uint16_t freq = CurrentFreq; freq < targetFreq; freq++)
      {
        pwm.setPWM(n,0,freq);
      }
      CurrentFreq=targetFreq;
    }else
    {
      for(uint16_t freq = CurrentFreq; freq > targetFreq; freq--)
      {
        pwm.setPWM(n,0,freq);
      }
      CurrentFreq=targetFreq;
    }
  }
}