/*
ANIX ARDUINO COMPUTER V1.0
Using ANIX OS 1.0 BETA
ARDUINO UNO PINS USED.
*/
#include <PS2Keyboard.h>
const int DataPin = 3; //Keyboard Data
const int IRQpin =  2; //Keyboard CLK
PS2Keyboard keyboard;
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 7, 6, 5, 4); //Display Pins




void setup() {
  lcd.begin(8, 2);
  delay(1000);

  keyboard.begin(2, 3);
  lcd.print("ANIX ELE");//Logo 1/2
  lcd.setCursor(0,1);
  lcd.print("CTRONICS");//Logo 2/2
  delay(1800);
  lcd.clear();
  lcd.print("  ANIX O");//OS Logo 1/2
  lcd.setCursor(0,1);
  lcd.print("S V1.1  ");//OS Logo 2/2
  delay(2000);
  lcd.clear();
  pinMode(13,OUTPUT);
  //Ready to run !
  

}//Setup End

void loop() {
  if (keyboard.available()) {
    
    
    char c = keyboard.read();
 
    
    lcd.print(c);
    //Delete Function
    if (c == PS2_DELETE) {
     lcd.clear();
    }
    //Move cursor 1
   if (c == PS2_PAGEDOWN) {
      lcd.setCursor(0,1);
      digitalWrite(13,HIGH);
    }
    else
    {
      digitalWrite(13,LOW);
    }
    //Move cursor 2
   if (c == PS2_PAGEUP) {
      lcd.setCursor(0,0);
       digitalWrite(13,HIGH);
    }
    else
    {
      digitalWrite(13,LOW);
    }
    
    
    
    
  } //First IF End

  
}// Loop End
    
  
  

