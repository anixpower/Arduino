String message; // variabila bluetooth

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
 // 1 si r stanga si dreapta  x spate si o fata 
void setup(){
  pinMode(13,OUTPUT); 
  pinMode(12,OUTPUT); 
  pinMode(11,OUTPUT); 
  pinMode(10,OUTPUT); 
  Serial.begin(9600);
  
  lcd.begin();
  lcd.backlight();
  lcd.print("Loading ...");
  lcd.setCursor(0,1);
  lcd.print("ANIX Sys v1.0");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Load Complete.");
  delay(1000);
  lcd.clear();
  lcd.print("Ready");
  
  
}


void loop(){
  
  while(Serial.available())
  {
    message+=char(Serial.read());//salveaza in variabila
  }
  if(!Serial.available())
  {
    if(message!="")
    {
      Serial.println(message); 
      if(message=="o"){ 
        digitalWrite(10,HIGH);
        digitalWrite(13,HIGH);

        
      }else if(message=="x"){ 
        digitalWrite(11,HIGH);
        digitalWrite(12,HIGH);

        
      }
 
    else if(message=="0")
      {
        digitalWrite(10,LOW);
        digitalWrite(11,LOW);   //Cancel ALL
        digitalWrite(12,LOW); 
        digitalWrite(13,LOW);
      }
          
      
      message=""; //clear the data
    }
  }
  delay(50); //delay
  
  
  
  
  
  
}
