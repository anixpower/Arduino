
#include <Stepper.h>
#define STEPS 45

Stepper stepper(STEPS, 8, 9, 10, 11);


int previous = 0;  // the previous reading from the analog input

void setup()
{ 
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  stepper.setSpeed(50); // Speed in RPM
}

void loop()
{
  digitalWrite(13,HIGH); 
  int valx = analogRead(0);   // get the sensor value
  int val = ((valx/4)/2.6)-49;
Serial.println(val);
  // move a number of steps equal to the change in the
  // sensor reading
  stepper.step(val - previous);

  // remember the previous value of the sensor
  previous = val;
  digitalWrite(13,LOW); 

}
