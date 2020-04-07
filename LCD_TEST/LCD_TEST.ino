#include <LiquidCrystal.h>
int A;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(8, 2);
  pinMode(13,OUTPUT);
  
  lcd.print("ANIX DEV");
  A =1 ;
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  
  lcd.print(A+=1);
  delay(1000);
  digitalWrite(13,LOW);
  delay(1000);
  digitalWrite(13,HIGH);

}

