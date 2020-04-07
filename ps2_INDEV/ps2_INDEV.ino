#include <ps2.h>
//Pin 5 is the mouse data pin, pin 6 is the clock pin
PS2 mouse(6, 5);


void mouse_init()
{
  mouse.write(0xff);  // reset
  mouse.read();  // ack byte
  mouse.read();  // blank */
  mouse.read();  // blank */
  mouse.write(0xf0);  // remote mode
  mouse.read();  // ack
  delayMicroseconds(100);
}

void setup()
{
  Serial.begin(9600);
  mouse_init();
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(13,OUTPUT);
}

void loop()
{
  char mstat;
  char mx;
  char my;

  /* get a reading from the mouse */
  mouse.write(0xeb);  // give me data!
  mouse.read();      // ignore ack
  mstat = mouse.read();
  mx = mouse.read();
  my = mouse.read();

  /* send the data back up */
  Serial.print(mstat, BIN);
  Serial.print("\tX=");
  Serial.print(mx, DEC);
  Serial.print("\tY=");
  Serial.print(my, DEC);
  Serial.println();
  
  

  
  
  if(my>=1){
  digitalWrite(7,HIGH);
  }
  else
  {digitalWrite(7,LOW);
  }
  
    if(my<=-1){
  digitalWrite(8,HIGH);
  }
  else
  {digitalWrite(8,LOW);
  }
  
  
    if(mx>=1){
  digitalWrite(9,HIGH);
  }
  else
  {digitalWrite(9,LOW);
  }
  
    if(mx<=-1){
  digitalWrite(10,HIGH);
  }
  else
  {digitalWrite(10,LOW);
  }
  
  if(mstat == 9){
    digitalWrite(13,HIGH);
  }
else
{digitalWrite(13,LOW);
}

  }
    //  delay(20);  /* twiddle */

