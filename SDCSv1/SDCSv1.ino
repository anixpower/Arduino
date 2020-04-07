int message;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
   pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
     pinMode(4,OUTPUT);
      pinMode(5,OUTPUT);
       pinMode(6,OUTPUT);
        pinMode(7,OUTPUT);
         pinMode(8,OUTPUT);
          pinMode(9,OUTPUT);
           pinMode(10,OUTPUT);
            pinMode(11,OUTPUT);
             pinMode(12,OUTPUT);
              pinMode(13,OUTPUT);
}

void loop() {
  int V0 = analogRead(A0);
    int V1 = analogRead(A1);
      int V2 = analogRead(A2);
        int V3 = analogRead(A3);
          int V4 = analogRead(A4);
            int V5 = analogRead(A5);
  
  if (Serial.available() > 0) { 
 message = Serial.read();
  if (message == 'a'){
    digitalWrite(2,HIGH);
  }
    if (message == 'b'){
    digitalWrite(3,HIGH);
  }
    if (message == 'c'){
    digitalWrite(4,HIGH);
  }
    if (message == 'd'){
    digitalWrite(5,HIGH);
  }
    if (message == 'e'){
    digitalWrite(6,HIGH);
  }
    if (message == 'f'){
    digitalWrite(7,HIGH);
  }
    if (message == 'g'){
    digitalWrite(8,HIGH);
  }
    if (message == 'h'){
    digitalWrite(9,HIGH);
  }
    if (message == 'i'){
    digitalWrite(10,HIGH);
  }
    if (message == 'j'){
    digitalWrite(11,HIGH);
  }
    if (message == 'k'){
    digitalWrite(12,HIGH);
  }
    if (message == 'l'){
    digitalWrite(13,HIGH);
  }
  
    if (message == 'A'){
    digitalWrite(2,LOW);
  }
    if (message == 'B'){
    digitalWrite(3,LOW);
  }
    if (message == 'C'){
    digitalWrite(4,LOW);
  }
    if (message == 'D'){
    digitalWrite(5,LOW);
  }
    if (message == 'E'){
    digitalWrite(6,LOW);
  }
    if (message == 'F'){
    digitalWrite(7,LOW);
  }
    if (message == 'G'){
    digitalWrite(8,LOW);
  }
    if (message == 'H'){
    digitalWrite(9,LOW);
  }
    if (message == 'I'){
    digitalWrite(10,LOW);
  }
    if (message == 'J'){
    digitalWrite(11,LOW);
  }
    if (message == 'K'){
    digitalWrite(12,LOW);
  }
    if (message == 'L'){
    digitalWrite(13,LOW);
  }
  
     if (message == 'M'){
    // Analog Send Data F

    Serial.print(V0);
    Serial.write(",");
    Serial.print(V1);
    Serial.write(",");
    Serial.print(V2);
    Serial.write(",");
    Serial.print(V3);
    Serial.write(",");
    Serial.print(V4);
    Serial.write(",");
    Serial.print(V5);
    Serial.write(",");
    
    
    
    
    
    //End ASDF
  }
  


  }}
