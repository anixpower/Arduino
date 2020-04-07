// ANIX Line Follewer Robot V1.1
// This code is opensource 
// Dr. Le Quark Contraptions
void setup() {
  pinMode(9,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);

 
}


void loop() {

  int Value1 = analogRead(A0);
  int Value2 = analogRead(A1)-80;
  //Serial.println("Reading");
  //Serial.println(Value1);
  //Serial.println(Value2);
  //Serial.println("   ");
  
  digitalWrite(12,LOW);
  analogWrite(9,110);
  if(Value1<100){
    digitalWrite(11,LOW);
    digitalWrite(10,HIGH);
  }
  else if(Value2<100){
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
  }
  else if(Value1&Value2>100){
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
  }
  else if(Value1&Value2<100){
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
  }
  
  
  //delay(200);        // Enable for USB debugging 
}
