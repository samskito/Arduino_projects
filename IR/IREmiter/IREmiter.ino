#include <IRremote.h>

/*
On the hardware level, using the IRremote library, 
there’s only one pin we can use to transmit IR data: pin 3.
There’s not any give here; pin 3’s PWM-capabilities make 
it one of the best choices for transmitting the 38kHz 
modulated IR data.
*/

IRsend irsend;

void setup()
{}

void loop() {
  
  irsend.sendNEC(0xE0E006F9, 32);
  delay(2000);

}
