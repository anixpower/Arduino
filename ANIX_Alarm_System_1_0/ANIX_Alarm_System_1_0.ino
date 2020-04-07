#include <Keypad.h>
int toneHz = 3500;
int toneTime = 50;

void setup() {
  // put your setup code here, to run once:
 pinMode(2,OUTPUT);
 pinMode(10,OUTPUT);
 pinMode(11,OUTPUT);
 pinMode(4, INPUT_PULLUP );
 pinMode(7, INPUT_PULLUP );
 pinMode(8, INPUT_PULLUP );
 pinMode(12, INPUT_PULLUP );
}

void loop() {
  // put your main code here, to run repeatedly: 
  
  int Buton1 = digitalRead(4);
  int Buton2 = digitalRead(7);
  int Buton3 = digitalRead(8);
  int Buton4 = digitalRead(12);
  
  
  if(Buton1 == 0){
    
  tone(2,toneHz,toneTime);
}

if(Buton2 == 0){
    
  tone(2,toneHz,toneTime);
}
if(Buton3 == 0){
    
  tone(2,toneHz,toneTime);
}
if(Buton4 == 0){
    
  tone(2,toneHz,toneTime);
}

}
