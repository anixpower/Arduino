#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define trigPin 13
#define echoPin 12
#define trigPin2 11
#define echoPin2 10
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  pinMode(2,OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  /// SENSOR 2
  
  long duration2, distance2;
  digitalWrite(trigPin2, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin2, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2/2) / 29.1;



   if (distance >= 200 || distance <= 0){
    lcd.setCursor(0,0);
    lcd.print("Dist1:");
    lcd.print("OutOfRange");
        digitalWrite(4,HIGH);
   }
  else {
    lcd.setCursor(0,0);
    lcd.print("Dist1:");
    lcd.print(distance);
    lcd.print(" cm      ");
    digitalWrite(4,LOW);
    
  }
  
     if (distance2 >= 200 || distance2 <= 0){
    lcd.setCursor(0,1);
    lcd.print("Dist2:");
    lcd.print("OutOfRange");
        digitalWrite(2,HIGH);
   }
  else {
    lcd.setCursor(0,1);
    lcd.print("Dist1:");
    lcd.print(distance2);
    lcd.print(" cm      ");
    digitalWrite(2,LOW);
  }
  
  

  delay(200);
  //lcd.clear();
}
