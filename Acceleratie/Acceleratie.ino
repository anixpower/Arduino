void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(9,OUTPUT);
pinMode(12,OUTPUT);
pinMode(11,OUTPUT);

}

void loop() {
int Value1 = analogRead(A0);
int Value1C = (((Value1-490)/2)-6);

if(Value1C<=5){
  Value1C=0;
}

if(Value1C>=255){
  Value1C=255;
}
  
  


//Serial.println(Value1C);
analogWrite(9,Value1C);

//delay(200);
}
