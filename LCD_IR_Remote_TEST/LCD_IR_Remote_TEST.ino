// LEFT   16754775
// RIGHT  16756815
// OK     16749165
// UP     16724685
// DOWN   16711935
//


#include <LiquidCrystal.h>
#include <IRremote.h> 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
IRrecv irrecv(13);
decode_results results;
int Pos;
int Value1;
int Value2;
int Value3;
int Value4;
void setup() {
  
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  Serial.begin(9600);


lcd.begin(8, 2);  // A 1x16 Line display is addressed as 2x8

lcd.print("ANIX ELE");

lcd.setCursor(0, 1);
lcd.print("CTRONICS");
irrecv.enableIRIn();
delay(2000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("IR 4 CH");
lcd.setCursor(0,1);
lcd.print("Remote");
Pos = 1;


}

void loop() {

   if (irrecv.decode(&results)) {
   // Serial.println(results.value); //DIAGNOSTIC DISABLED
     irrecv.resume(); // Receive the next value
     
     
//POS FUNCTION========================
   if(results.value == 16754775){
     Pos-=1;
     lcd.clear();
   }
  else if(results.value ==16756815)
  {
    Pos+=1;
lcd.clear();

}

if(Pos<1){
       Pos=1;
     }
     if(Pos>4){
  Pos=4;
     }  
//END POS FUNCTION============================
     
     //Change Value1
     if(Pos==1){
   if(results.value == 16724685){
     Value1+=1;
     lcd.clear();
   }
  else if(results.value ==16711935)
  {
    Value1-=1;
lcd.clear();
}
//POS1
     }else if (Pos==2){
          if(results.value == 16724685){
     Value2+=1;
     lcd.clear();
   }
  else if(results.value ==16711935)
  {
    Value2-=1;
lcd.clear();
}
     }
//POS 2
else if (Pos==3){
          if(results.value == 16724685){
     Value3+=1;
     lcd.clear();
   }
  else if(results.value ==16711935)
  {
    Value3-=1;
lcd.clear();
}
}
//POS3

else if (Pos==4){
          if(results.value == 16724685){
     Value4+=1;
     lcd.clear();
   }
  else if(results.value ==16711935)
  {
    Value4-=1;
lcd.clear();
}
}
//POS4
       
       
     
  //LCD Pos System
     
  lcd.setCursor(0,0);
  if(Pos==1){
    lcd.print(">1:"); 
  }
  else
  {
  lcd.print(" 1:"); 
  }
  lcd.print(Value1);

  if(Pos==2){
  lcd.print(">2:"); 
  }
  else
  {lcd.print(" 2:");
  }
  lcd.print(Value2);
  
  lcd.setCursor(0,1); // SE C 
   if(Pos==3){
  lcd.print(">3:"); 
  }
  else
  {lcd.print(" 3:");
  }
  lcd.print(Value3);
  
  
   if(Pos==4){
  lcd.print(">4:"); 
  }
  else
  {lcd.print(" 4:");
  }
  lcd.print(Value4);
  //end if LCD pos system
 
  
  
  

     
  }// IR READING REFRESH END ( Codul ruleaza la receptionarea IR )
  
 
  
  
  
  if(Value1>1){
  Value1=1;
  }  
    if(Value2>1){
  Value2=1;
  }  
    if(Value3>1){
  Value3=1;
  }  
  
      if(Value4>1){
  Value4=1;
  }  
  if(Value1<0){
    Value1=0;
  }
    if(Value2<0){
    Value2=0;
  }
    if(Value3<0){
    Value3=0;
  }
      if(Value4<0){
    Value4=0;
  }
  //WRITE VALUES AFTER CHECK
  digitalWrite(6,Value1);
  digitalWrite(7,Value2);
  digitalWrite(9,Value3);
  digitalWrite(10,Value4);
  
  


}
