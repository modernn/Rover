#include "Steering.h"


Steering::Steering()
{
  pwm = Adafruit_PWMServoDriver();
  int CurrentPosition = 500;
  int CurrentFreq = 500;
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);

}

void Steering::Steer(double position)
{
  int targetFreq = (((SERVOMAX-SERVOMIN)/100)*position)+SERVOMIN;
  pwm.setPWM(0, 0, targetFreq);
  pwm.setPWM(1, 0, targetFreq);
  pwm.setPWM(2, 0, targetFreq);
  pwm.setPWM(3, 0, targetFreq);
}


