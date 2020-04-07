#include <Wire.h>
#include <LiquidCrystal_I2C.h>
String message;
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
int Process;
void setup() {
  Process=0;
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin (9600);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("ANIX ELECTRONICS");
  lcd.setCursor(0,1);
  lcd.print("Bluetooth LCD v1");
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
  delay(2500);
  // S1
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);

  lcd.clear();
  lcd.setCursor(0,0);

  
}

void loop() {
  
  while(Serial.available())
  {//while there is data available on the serial monitor
    message+=char(Serial.read());//store string from serial command
  }
  if(!Serial.available())
  {
    
    if(Process==0){
    
    if(message=="!"){
       lcd.clear(); 
       message="";
      }
      
      if(message=="-"){
       lcd.setCursor(0,1);
       message="";
      
      }
      
      if(message=="+"){
       lcd.setCursor(0,0);
       message="";
      }
      
      
    if(message!="")
    {//if data is available
      lcd.print(message); //show the data
      }
      
      
    }
    
    
    
    if(Process==1){
      lcd.setCursor(0,0);
      lcd.print("LED TEST");
      digitalWrite(13,HIGH);
      digitalWrite(12,LOW);
      digitalWrite(11,HIGH);
      digitalWrite(10,LOW);
      delay(200);
      digitalWrite(13,LOW);
      digitalWrite(12,HIGH);
      digitalWrite(11,LOW);
      digitalWrite(10,HIGH);
      delay(200);
    }
    
    
    if(Process==2){
      
     int a = analogRead(A0);
     int b = analogRead(A0);
     lcd.setCursor(0,0);
     lcd.print("aRead1:");
     lcd.print(a);
       lcd.print("   ");
     lcd.setCursor(0,1);
     lcd.print("aRead2:");
     lcd.print(b);
       lcd.print("   ");
     delay(250);
     
      
    }
    
    
    if(message=="1"){
     Process=0;
     lcd.clear();
    }
    if(message=="2"){
     Process=1; 
     lcd.clear();
      
    }
    if(message=="3"){
     Process=2; 
     lcd.clear();
      
    }
    
    
    
    
    
    
    
    
      message="";// CLEAR DATA FROM Var . Avoiding loop Error 
   
   
   


}

}
