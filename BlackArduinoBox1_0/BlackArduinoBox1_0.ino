int Button1 = 0;
int Button2 = 0;
int Button3 = 0;
void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
}


void loop() {
  Button1 = digitalRead(2);
  Button2 = digitalRead(4);
  Button3 = digitalRead(7);
  
  int V1 = analogRead(A0);
  int V2 = analogRead(A1);
  
  Serial.println("ANALOG READ");
  Serial.println("   ");
  Serial.println(V1);
  Serial.println("   ");
  Serial.println(V2);
  Serial.println("BUTTON STATE" );
  
  Serial.println("   ");
  Serial.println(Button1);
  Serial.println("   ");
  Serial.println(Button2);
  Serial.println("   ");
  Serial.println(Button3);
  delay(250);
  
}
