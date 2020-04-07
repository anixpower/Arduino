int leftInput=A3;
int rightInput=A4;
int leftMotor=13;
int rightMotor=12;
int leftValue = 0;
int rightValue = 0;
void setup()
{
  pinMode (leftMotor, OUTPUT);
  pinMode (rightMotor, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  leftValue = analogRead (leftInput/2-100);
  rightValue= analogRead (rightInput/2);
    Serial.print("First  ");
  Serial.println(leftValue);
  Serial.print("Second  ");  
  Serial.println(rightValue);


 if
   ( leftValue < 500 && rightValue < 500)
   {
     digitalWrite (leftMotor, HIGH);
     digitalWrite (rightMotor, HIGH);
   }
   else
   {

     if
     ( leftValue > 500 && rightValue < 500)
    {
      digitalWrite (leftMotor, LOW);
      digitalWrite (rightMotor, HIGH);
    }
 else {
   if (leftValue < 500 && rightValue > 500)
   {
   digitalWrite (rightMotor, LOW);
   digitalWrite (leftMotor, HIGH);
   }
   else
   {
     if (leftValue > 500 && rightValue > 500)
     {digitalWrite (rightMotor, LOW);
       digitalWrite (leftMotor, LOW);
     }}
      }
    }
  
delay(200);
}
    
