#include <ShiftLCD.h>
#define lenght 16.0
ShiftLCD lcd(2, 4, 3);
double percent=100.0;
unsigned char b;
unsigned int peace;

//Custom Char
byte p1[8] = {
	  0x10,
	  0x10,
	  0x10,
	  0x10,
	  0x10,
	  0x10,
	  0x10,
	  0x10};
	 
byte p2[8] = {
	  0x18,
	  0x18,
	  0x18,
	  0x18,
	  0x18,
	  0x18,
	  0x18,
	  0x18};
	 
byte p3[8] = {
	  0x1C,
	  0x1C,
	  0x1C,
	  0x1C,
	  0x1C,
	  0x1C,
	  0x1C,
	  0x1C};
	 
byte p4[8] = {
	  0x1E,
	  0x1E,
	  0x1E,
	  0x1E,
	  0x1E,
	  0x1E,
	  0x1E,
	  0x1E};
	 
byte p5[8] = {
	  0x1F,
	  0x1F,
	  0x1F,
	  0x1F,
	  0x1F,
	  0x1F,
	  0x1F,
	  0x1F};





void setup() {
  lcd.createChar(0, p1);
  lcd.createChar(1, p2);
  lcd.createChar(2, p3);
  lcd.createChar(3, p4);
  lcd.createChar(4, p5);
  lcd.begin(8, 2);
  lcd.print("ANIX ELE");
  lcd.setCursor(0, 1);
  lcd.print("CTRONICS");
  delay(1800);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("  ANIX O");
  lcd.setCursor(0, 1);
  lcd.print("S V1.0 ");
  delay(2000);
  
  lcd.clear();
  pinMode(5,OUTPUT);
  pinMode(7,OUTPUT);
}

void loop() {
  digitalWrite(7,HIGH);
  lcd.setCursor(0, 0);
  unsigned int value = analogRead(0);
  int value2 = analogRead(1);
  percent = value/1024.0*100.0;
  double a=lenght/200*percent; //Regalaj Marime indicator.!!!
  if (a>=1) {
	 
	    for (int i=1;i<a;i++) {
	 
	      lcd.write(4);
	 
	      b=i;
	    }
	 
	    a=a-b;
	 
	  }
	 
	  peace=a*5;
  
  switch (peace) {
	 
	  case 0:
	 
	    break;
	 
	  case 1:
	    lcd.write(0);
	 
	    break;
	 
	  case 2:
	    lcd.write(1);
	    break;
	 
	  case 3:
	    lcd.write(2);
	    break;
	 
	  case 4:
	    lcd.write(3);
	    break;
	 
	  }
	 
	//clearing line
	  for (int i =0;i<(lenght-b);i++) {
	 
	    lcd.print(" ");
	  };
lcd.setCursor(0, 1);

	 
	
	 
	  lcd.print(percent);
	  lcd.print(" %   ");
analogWrite(5,value/4.01);
digitalWrite(7,LOW);

	}
  
  


  
  
   
  
  
 




