
// include the library code:
#include <ShiftLCD.h>

// initialize the library with the numbers of the interface pins
ShiftLCD lcd(2, 4, 3);

void setup() {
  // set up the LCD's number of rows and columns: 
  lcd.begin(8, 2);
  // Print a message to the LCD.
  lcd.print("ANIX ELE");
  lcd.setCursor(0, 1);
  lcd.print("CTRONICS");
  delay(1000);
  lcd.clear();

  Serial.begin(9600); 
  
}

void loop() {
  
  int Analog1 = analogRead(A0);
  lcd.setCursor(0, 0);
  lcd.print(Analog1);
  lcd.setCursor(0, 1);
  lcd.print("ANIX");
  
  Serial.println(Analog1);
 delay(100);
}

