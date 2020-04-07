/*
ANIX TEMP LCD View
Standard Arduino LCD connect .
Thermsistor - PIN A0



*/

// variables for input pin and control LED
  int analogInput = 1;
  float vout = 0.0;
  float vin = 0.0;
  float R1 = 100000.0;    // !! resistance of R1 !!
  float R2 = 10000.0;     // !! resistance of R2 !!
  
 int value = 0;
 
#include <math.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
double Thermister(int RawADC) {
 double Temp;
 Temp = log(((10240000/RawADC) - 10000));
 Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
 Temp = Temp - 273.15;            // Convert Kelvin to Celcius

 return Temp; 
}

//Caracter Grade
byte degree[
8
] = {

B00110,
B01001,
B01001,
B00110,
B00000,
B00000,
B00000,
B00000
}; 
//Sfarsit caracter grade.

void setup() {
  lcd.begin(8, 2);
  lcd.createChar(1, degree);
  delay(200);
  lcd.setCursor(0,0);
  lcd.print("ANIX ELE");//Logo 1/2
  lcd.setCursor(0,1);
  lcd.print("CTRONICS");//Logo 2/2
  delay(1000);
  lcd.clear();
  lcd.print("  ANIX O");//OS Logo 1/2
  lcd.setCursor(0,1);
  lcd.print("S V1.1  ");//OS Logo 2/2
  delay(500);
  lcd.clear();
  
  
  //NEW
  pinMode(analogInput, INPUT);
 
}

void loop() {
  
 int T =(Thermister(analogRead(0)));
 lcd.setCursor(0,0);
 lcd.print(int(Thermister(analogRead(0))));
 lcd.write(1);
 lcd.print("C");
 
 

  //Voltage Read
  
 value = analogRead(analogInput);

  vout = (value * 5.0) / 1024.0;
  vin = vout / (R2/(R1+R2));  
  
  // Print Voltage
  lcd.setCursor(0,1);
//lcd.print("12345678");
  lcd.print(vin);
  lcd.print(" V     ");




 delay(500);

}
