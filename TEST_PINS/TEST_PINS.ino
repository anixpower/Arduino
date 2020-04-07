int a;
void setup() {
  
pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
pinMode(11,OUTPUT);
pinMode(10,OUTPUT);
Serial.begin(9600);

}

void loop() {
  digitalWrite(13,LOW);//Dreapta Inainte
  digitalWrite(12,LOW);//Dreapta Inapoi
  digitalWrite(11,HIGH);//?
  digitalWrite(10,LOW);

  
 delay(500);

}
