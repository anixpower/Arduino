//ANIX Voltage Reading system 
//http://xanx.webs.com
//========================================
//https://www.facebook.com/anixelectronics
//========================================
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int analogInput = 0;
float vout = 0.0;
float vin = 0.0;
float vout2 = 0.0;
float vin2 = 0.0;
float R1 = 97200.0; // resistance of R1 - Check to be precise ( Recomanded 1MOhm /Minimum 100KOhm )  10000 Value  =  10Kohm !!!
float R2 = 10000.0; // resistance of R2 - Check to be precise ( Recomanded 100kOhm /Minimum 10KOhm )
int protection = 0;
int value = 0;
int value2 = 0;
void setup(){
   pinMode(analogInput, INPUT);
   pinMode(9,OUTPUT);
   pinMode(8,OUTPUT);
   lcd.begin(8, 2);
   lcd.setCursor(0,0);
  lcd.print("ANIX ELE");//Logo 1/2
  lcd.setCursor(0,1);
  lcd.print("CTRONICS");//Logo 2/2
  delay(1000);
  lcd.clear();
  lcd.print("  ANIX O");//OS Logo 1/2
  lcd.setCursor(0,1);
  lcd.print("S V1.5  ");//OS Logo 2/2
  delay(500);
  lcd.clear();
   
   
}
void loop(){
  //VOLTAGE READING
  // read the value at analog input
   value = analogRead(A0);
   vout = (value * 5.00) / 1024.0; // see text
   vin = vout / (R2/(R1+R2)); 
   if (vin<0.20) {
   vin=0.0;//statement to quash undesired reading !
   
   }
   value2 = analogRead(A1);
   vout2 = (value2 * 5.00) / 1024.0; // see text
   vin2 = vout2 / (R2/(R1+R2)); 
   if (vin2<0.20) {
   vin2=0.0;//statement to quash undesired reading !
   }
   
   
   

lcd.setCursor(0, 0);
lcd.print("V1=");
lcd.print(vin);

lcd.setCursor(0, 1);
lcd.print("V2=");
lcd.print(vin2);
// END VOLTAGE READING 

//OVERVOLTAGE PROTECTION SYSTEM 1.0

if(vin>15){
  protection = 1;
  
  

}else if (vin2>15){
   protection = 1;
}
else
{
  
  protection = 0;
}

if(protection == 1 ){
  digitalWrite(8,HIGH);
  tone(9,500);
  //Display Problem
  lcd.clear();
   lcd.setCursor(0,0);
  lcd.print("  OVER V");
   lcd.setCursor(0,1);
  lcd.print("OLTAGE");
  //end Display Problem
  
  
  delay(10000);
  lcd.clear();
}
else
{
  noTone(9);
  digitalWrite(8,LOW);
  
}
delay(250);
}
