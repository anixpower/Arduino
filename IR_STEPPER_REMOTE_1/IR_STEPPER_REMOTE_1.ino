
#include <IRremote.h>
int buttonState1 = 0; 
int buttonState2 = 0; 
IRsend irsend;

void setup()
{
  pinMode(8,INPUT_PULLUP);
  pinMode(9,INPUT_PULLUP);
  Serial.begin(9600);

}

void loop() {
   buttonState1 = digitalRead(8);
    buttonState2 = digitalRead(9);
 if (buttonState1 == LOW) {     
    // turn LED on:    
     irsend.sendRC5(16724685, 32);
  } 
  else if (buttonState2 == LOW) {     
    irsend.sendRC5(16711935, 32);

  }
  
  else
  {
  }
  
  

  
     
      delay(50);// necesary for stabilisation
    
  
}
