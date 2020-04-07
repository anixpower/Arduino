#include <HCSR04.h>
UltraSonicDistanceSensor distanceSensor(9,8);
int D;//Variabila distanta
int Directie = 0; // variabila status directie
const int trigPin = 9;
const int echoPin = 8;
//variabile Distanta senzor hc-sr04
long duration;
int distance;


void setup(){
//Definitie pini control motoare IO
  pinMode(13,OUTPUT); //Dreapta inainte
  pinMode(12,OUTPUT); //Dreapta inapoi
  pinMode(11,OUTPUT); //Stanga intainte  
  pinMode(10,OUTPUT); //Stanga inapoi
  
  Serial.begin(9600);
}

void loop(){
   D = distanceSensor.measureDistanceCm();
  Serial.println(D);
if(D>=20){
    digitalWrite(13,HIGH);//Dreapta inainte
    digitalWrite(12,LOW);
    digitalWrite(11,HIGH);//Stanga intainte  
    digitalWrite(10,LOW);
    Serial.println("Inainte");
    delay(100);
        
      
              
      }
else if(D<20&D>10){
       digitalWrite(13,LOW);
       digitalWrite(12,LOW);
       digitalWrite(11,HIGH);//Stanga intainte  
       digitalWrite(10,LOW);
       
       Serial.println("Stanga");
      delay(100);
      
      }
      else if(D<10){

        digitalWrite(13,LOW);
        digitalWrite(12,HIGH);//Dreapta inapoi
        digitalWrite(11,LOW);
        digitalWrite(10,HIGH);//Stanga inapoi
        delay(1500);
        Serial.println("Inapoi");
delay(100);
      }
            
      }

      void isr(){
}

          
      
     
  
    
      
  

  
  
  
  
  
  
