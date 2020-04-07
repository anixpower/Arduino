int ledPin = 9;    // LED connected to digital pin 9
int fade =0;
void setup() {
  // nothing happens in setup
}

void loop() {


  
  // fade in from min to max in increments of 5 points:
  for (int fade = 0 ; fade <= 255; fade += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fade);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }

  // fade out from max to min in increments of 5 points:
  for (int fade = 255 ; fade >= 0; fade -= 5) {
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fade);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }
}
