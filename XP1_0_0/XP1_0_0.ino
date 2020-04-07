//VOLTAGE READING VARS

float vout = 0.0;
float vin = 0.0;
float R1 = 98250.0; // resistance of R1 (100K) -see text!
float R2 = 9795.0; // resistance of R2 (10K) - see text!
int value = 0;
//VOLTAGE READING VARS END

//SERVO CONTROL
#include <Servo.h>  
Servo Servo1;  
int pos = 0;
int val ;
//SERVO CONTROL END

void setup() 
{ 
  Servo1.attach(9); 
  pinMode(A5, INPUT);
  Serial.begin(9600);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
} 
 
 
void loop() 
{ 
  //SERVO CONTROL
  val = analogRead(A0);            // reads the value of the potentiometer (value between 0 and 1023) 
  val = map(val, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
  Servo1.write(val);                  // sets the servo position according to the scaled value 
  
  
  
  
  //READ VOLTAGE
   value = analogRead(A5);
   vout = (value * 4.98 ) / 1024.0; // see text
   vin = vout / (R2/(R1+R2)); 
   if (vin<0.09) {
   vin=0.0;//statement to quash undesired reading !
   //READ VOLTAGE END
   }
   
   Serial.println(vin);
   int vinx = vin ;
   if(vin<=6){
   digitalWrite(10,HIGH);
   digitalWrite(11,LOW);
   digitalWrite(12,LOW);
   digitalWrite(13,LOW);
   }else if(vin<=6.5){
   digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
   }else if(vin<=6.8){
   digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
   }else if(vin<=7){
   digitalWrite(10,HIGH);
   digitalWrite(11,HIGH);
   digitalWrite(12,HIGH);
   digitalWrite(13,HIGH);
   }
   else if(vin>7.1){
   digitalWrite(10,HIGH);
   digitalWrite(11,HIGH);
   digitalWrite(12,HIGH);
   digitalWrite(13,HIGH);
   }
   
   else if(vin>12){
     delay(500);
   digitalWrite(10,HIGH);
   digitalWrite(11,HIGH);
   digitalWrite(12,HIGH);
   digitalWrite(13,HIGH);
        delay(500);
   digitalWrite(10,LOW);
   digitalWrite(11,LOW);
   digitalWrite(12,LOW);
   digitalWrite(13,LOW);
   }
   
   
 
}   
 
  
  
  

