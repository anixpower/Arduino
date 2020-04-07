String message; // variabila bluetooth

 // 1 si r stanga si dreapta  x spate si o fata 
void setup(){
  pinMode(13,OUTPUT); 
  pinMode(12,OUTPUT); 
  pinMode(11,OUTPUT); 
  pinMode(10,OUTPUT); 
  Serial.begin(9600);
}


void loop(){
  
  while(Serial.available())
  {
    message+=char(Serial.read());//salveaza in variabila
  }
  if(!Serial.available())
  {
    if(message!="")
    {//if data is available
      Serial.println(message); //show the data
      if(message=="o"){ 
        digitalWrite(10,HIGH);
        digitalWrite(13,HIGH);

        
      }else if(message=="x"){ 
        digitalWrite(11,HIGH);
        digitalWrite(12,HIGH);

        
      }

else if(message=="r"){ 
        digitalWrite(10,HIGH);


        
      }

      else if(message=="l"){ 
        digitalWrite(13,HIGH);
        

        
      }
      
 
    else if(message=="0")
      {
        digitalWrite(10,LOW);
        digitalWrite(11,LOW);   //protectie
        digitalWrite(12,LOW); 
        digitalWrite(13,LOW);
      }
          
      
      message=""; //clear the data
    }
  }
  delay(50); //delay
  
  
  
  
  
  
}
