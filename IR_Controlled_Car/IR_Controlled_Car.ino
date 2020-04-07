//IR Controlled Car 
//ANIX DEV 
// Code maked for Samsung Remote SN 10072002 
#include <IRremote.h> // Librarie IR 
unsigned int beepHz = 4000; // Hz
unsigned long beepTime = 50; //ms
int dStatus;
int Speed;

int RECV_PIN = 3; //  Pin IR 

IRrecv irrecv(RECV_PIN); // Power IR

decode_results results;

void setup()
{
  Speed = 120;
  dStatus = 1;
  
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(6,OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
     irrecv.resume(); // Receive the next value
   //================================
   if(results.value == 3261853764 )
  {
    dStatus=1;
    digitalWrite(9,HIGH); 
    
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
      
  
}
  else if(results.value == 1972149634){
    //Stanga T
    if(dStatus==1){
    
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    digitalWrite(12,LOW);
    }
    
    if(dStatus==2){
    
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    digitalWrite(12,HIGH);
    }
    
    
  }
  else if(results.value == 1400905448){
    //Dreapta T
    
    if(dStatus==1){
    
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    }
    if(dStatus==2){
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(12,HIGH);
    }
    
    
    
    
  }
  else if(results.value == 3305092678){
    dStatus = 2;
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(12,HIGH);
    
  }
  else
  {
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);

  }

   
  
  
  
  



  
  
}
