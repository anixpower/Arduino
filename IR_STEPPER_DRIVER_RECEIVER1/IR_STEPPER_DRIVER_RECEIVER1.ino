
#include <Stepper.h>
#include <IRremote.h> 
#define STEPS 45
int Step;

Stepper stepper(STEPS, 8, 9, 10, 11);

IRrecv irrecv(12);
decode_results results;




void setup()
{ 
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  stepper.setSpeed(50); // Speed in RPM
  Step = 0;
  
  irrecv.enableIRIn(); // Start the receiver
}

void loop()
{
  
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
     irrecv.resume(); // Receive the next value
   if(results.value == 16724685){
     stepper.step(1);
   }
  else if(results.value ==16711935)
  {
    stepper.step(-1);
  }
  else
  {
    stepper.step(0);
  }
     
  }
  
  
  
  

  // move a number of steps equal to the change in the
  // sensor reading
  //stepper.step(0);

  // remember the previous value of the sensor



}
