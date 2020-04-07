/*
 * Optical Tachometer
 *
 * Uses an IR LED and IR phototransistor to implement an optical tachometer.
 * The IR LED is connected to pin 13 and ran continually. A status LED is connected
 * to pin 12. Pin 2 (interrupt 0) is connected across the IR detector.
 *
 * 
 */

int ledPin = 13;                // IR LED connected to digital pin 13
int statusPin = 12;             // LED connected to digital pin 12

volatile byte rpmcount;
volatile int status;

unsigned int rpm;

unsigned long timeold;

 void rpm_fun()
 {
   //Each rotation, this interrupt function is run twice, so take that into consideration for 
   //calculating RPM
   //Update count
      rpmcount++;
      
   //Toggle status LED   
   if (status == LOW) {
     status = HIGH;
   } else {
     status = LOW;
   }
   digitalWrite(statusPin, status);
 }

void setup()
 {
   Serial.begin(9600);
   //Interrupt 0 is digital pin 2, so that is where the IR detector is connected
   //Triggers on FALLING (change from HIGH to LOW)
   attachInterrupt(0, rpm_fun, FALLING);
   
   //Turn on IR LED
   pinMode(ledPin, OUTPUT); 
   digitalWrite(ledPin, HIGH);
   
   //Use statusPin to flash along with interrupts
   pinMode(statusPin, OUTPUT);

   rpmcount = 0;
   rpm = 0;
   timeold = 0;
   status = LOW;
 }

 void loop()
 {
   //Update RPM every second
   delay(1000);
   //Don't process interrupts during calculations
   detachInterrupt(0);
   //Note that this would be 60*1000/(millis() - timeold)*rpmcount if the interrupt
   //happened once per revolution instead of twice. Other multiples could be used
   //for multi-bladed propellers or fans
   rpm = 30*1000/(millis() - timeold)*rpmcount;
   timeold = millis();
   rpmcount = 0;
   
   //Write it out to serial port
   Serial.println(rpm,DEC);
   
   //Restart the interrupt processing
   attachInterrupt(0, rpm_fun, FALLING);

  }



