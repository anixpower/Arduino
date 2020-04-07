int a;
void setup() {
  // put your setup code here, to run once:
pinMode(A7,INPUT);
Serial.begin(9600);
}

void loop() {
  a = analogRead(A7);
 Serial.println(a);
 delay(500);

}
