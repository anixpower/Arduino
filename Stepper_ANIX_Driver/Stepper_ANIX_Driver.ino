

void setup(){
 pinMode(9,OUTPUT);
 pinMode(10,OUTPUT);
 pinMode(11,OUTPUT);
 
  
}

void loop (){
  int pwmx = analogRead(A0);
  int time = analogRead(A1);
  int pwm  = pwmx/4;
  
  analogWrite(9,pwm);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  
  delay(time);
  
  digitalWrite(9,LOW);
  analogWrite(10,pwm);
  digitalWrite(11,LOW);
  
  delay(time);
  
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  analogWrite(11,pwm);
  
  delay(time);
  
  
}
