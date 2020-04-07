#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
// set up the LCD's number of columns and rows:
// A 1x16 Line display is addressed as 2x8
lcd.begin(8, 2);
// Print a message to the LCD.
lcd.print("ANIX ELE");
// Move the cursor to the beginning of the second address block
// (note: line 1 is the second row, since counting begins with 0):
lcd.setCursor(0, 1);
lcd.print("CTRONICS");
}

void loop() {
// set the cursor to column 0, line 1
// (note: line 1 is the second row, since counting begins with 0):
lcd.setCursor(5, 1);
// print the number of seconds since reset:

}
