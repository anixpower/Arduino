void setup() {
  // put your setup code here, to run once:
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(9,OUTPUT);
Serial.begin(9600);

}

void loop() {

  int Val1 = analogRead(A0);
  int Val2 = analogRead(A1);
  Serial.println(Val1/4);
  analogWrite(5,Val1/4);
  analogWrite(6,Val2/4);
  
  
}
