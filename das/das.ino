void setup() {
  pinMode(1,OUTPUT);
  pinMode(0,OUTPUT);
}

void loop() {
  int sensorValue = analogRead(2);
  analogWrite(1,sensorValue/5);
  analogWrite(0,sensorValue/5);
  delay(10);
}
