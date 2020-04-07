int sV;
void setup() {
 pinMode(1,OUTPUT);

}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  sV = analogRead(2);
  // print out the value you read:
  analogWrite(1,sV); 

}
