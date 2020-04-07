#include <HCSR04.h>
UltraSonicDistanceSensor distanceSensor(6, 5);
int S1 ; //Senzor D1
int S2 ; //Senzor D2
int SW1 ;//Variabila MOD
int Dis;//Variabila distanta din senzor

void setup(){
//Definitie pini control motoare IO
  pinMode(9,INPUT);//Senzor Stanga
  pinMode(8,INPUT);//Senzor Dreapta
  pinMode(13,OUTPUT); //Dreapta inainte
  pinMode(12,OUTPUT); //Dreapta inapoi
  pinMode(11,OUTPUT); //Stanga intainte  
  pinMode(10,OUTPUT); //Stanga inapoi
  pinMode(7,INPUT);// Switch intre LineFollower si ObjectAvoidance
  
}

void loop(){
  S1 = digitalRead(9); //Senzor Stanga
  S2 = digitalRead(8); //Senzor Dreapta
  SW1 = digitalRead(7);//Switch MOD




  
if(SW1==1){
   

 if(S1==0&S2==0){ //INAINTE

 
    digitalWrite(13,HIGH);//Dreapta inainte
    digitalWrite(12,LOW);
    digitalWrite(11,HIGH);//Stanga intainte  
    digitalWrite(10,LOW);
    

  
        
              
      }else if(S1==1&S2==0){
 
    digitalWrite(13,HIGH);//Dreapta inainte
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);



      }
      else if(S1==0&S2==1){

    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,HIGH);//Stanga intainte  
    digitalWrite(10,LOW);
      }

}
else{
    Dis = distanceSensor.measureDistanceCm();

if(Dis>=15){
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    
    digitalWrite(13,HIGH);//Dreapta inainte
    digitalWrite(12,LOW);
    digitalWrite(11,HIGH);//Stanga intainte  
    digitalWrite(10,LOW);
    delay(100);


}else if(Dis<15){

    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
      delay(100);
    digitalWrite(13,LOW);//inapoi x secunde
    digitalWrite(12,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(10,HIGH);


    
    delay(1000);
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    delay(100);
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,HIGH);
    digitalWrite(10,LOW);
    delay(1000);

    

}

}
}
      
      






 

      

    
      
  

  
  
  
  
  
  
