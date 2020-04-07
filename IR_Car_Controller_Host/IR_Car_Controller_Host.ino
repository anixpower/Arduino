#include <IRremote.h> 
IRrecv irrecv(8);
decode_results results;

void setup() {                

  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);  
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  irrecv.enableIRIn(); // Start the receiver
  decode_results results;
  Serial.begin(9600);

}
//Command 
// 1 - Inainte
// 2 - Inapoi
// 3 - Stanga
// 4 - Dreapta

void loop() {

   if (irrecv.decode(&results)) {
    Serial.println(results.value);
     irrecv.resume(); // Refresh . Get next value 
   if(results.value == 16724685){
      digitalWrite(13, 1);
      digitalWrite(12, 0);
   }
  else if(results.value ==16711935)
  {
      digitalWrite(13, 0);
      digitalWrite(12, 1);
  }
  else
  {
      digitalWrite(13, 0);
      digitalWrite(12, 0);
  }
  
  
  
  
     
  }


}
