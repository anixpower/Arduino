void setup(){
 pinMode(9,OUTPUT);
 Serial.begin(9600);
}

void loop(){
 int Val1 = analogRead(A0);
  int Val2 = analogRead(A1);
 analogWrite(9,Val1/4); 
  Serial.println("=============");
 Serial.print("Value 1 :");
 Serial.println(Val1/2);
  Serial.print("Value 2 :");
 Serial.println(Val2/2);
 
 delay(200);
}
