#include <Stepper.h>
#include <Servo.h>

#define REVSTEPS 2048
#define STEPSIZE 23 /* 1 degrees  */
#define FINISH 53 /* Led lights up when finished */
int currentStep;

Stepper motor(REVSTEPS, 22, 24, 23, 25);
Servo sg90;

void setup() 
{
  currentStep = 0;
  motor.setSpeed(2);
  
  sg90.attach(2);
  sg90.write(0);
  pinMode(FINISH, OUTPUT);
}

void loop() 
{
  delay(5000);
  while(currentStep < REVSTEPS)
  {
    motor.step(STEPSIZE);
    currentStep += STEPSIZE;
    delay(500);
    
    sg90.write(45);
    delay(400);
    sg90.write(0);
    delay(500);
  }
  if(currentStep >= REVSTEPS)
  {
    digitalWrite(FINISH, HIGH);
  }
}
