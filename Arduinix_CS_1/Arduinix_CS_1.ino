void setup(){
  
 Serial.begin(9600); 
  
}

void loop(){
   int V0 = analogRead(A0);
   int V1 = analogRead(A1);
   int V2 = analogRead(A2);
   int V3 = analogRead(A3);
   int V4 = analogRead(A4);
   int V5 = analogRead(A5);
  
  if (Serial.available() > 0) { 
 message = Serial.read();
  if (message == 'a'){
     Serial.print(V0);

    
  }
  
    if (message == 'b'){
     Serial.print(V1);

    
  }
 
  
}
