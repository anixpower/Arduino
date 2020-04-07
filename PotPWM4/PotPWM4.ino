void setup() {
 pinMode(3,OUTPUT);
 pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
   pinMode(9,OUTPUT);
    pinMode(10,OUTPUT);

}

void loop() {
  int Valoare = analogRead(A0);
  int pValoare= (Valoare/4);
  analogWrite(3,pValoare);
  analogWrite(5,pValoare);
  
  int Valoare1 = analogRead(A1);
  int pValoare1= (Valoare1/4);

  analogWrite(6,pValoare1);
  
  int Valoare2 = analogRead(A2);
  int pValoare2= (Valoare2/4);

  analogWrite(9,pValoare2);
  
  int Valoare3 = analogRead(A3);
  int pValoare3= (Valoare3/4);

  analogWrite(10,pValoare3);
  
  
}
