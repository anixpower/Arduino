// variables for input pin and control LED
  int analogInput = 1;
  float vout = 0.0;
  float vin = 0.0;
  float R1 = 100000.0;    // !! resistance of R1 !!
  float R2 = 10000.0;     // !! resistance of R2 !!

// variable to store the value 
  int value = 0;

void setup(){
  // declaration of pin modes
  pinMode(analogInput, INPUT);
  pinMode(3,OUTPUT);
  Serial.begin(9600);
}

void loop(){
  // read the value on analog input
  value = analogRead(analogInput);

  vout = (value * 5.0) / 1024.0;
  vin = vout / (R2/(R1+R2));  



analogWrite(3,vin*4);
Serial.println(vin);


  // sleep...
  delay(500);
}
