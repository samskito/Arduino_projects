/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

int RECV_PIN = 11;
int LED_PIN = 2;
int UP_PIN = 3;

IRrecv irrecv(RECV_PIN);

decode_results results;
String sentValue;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(LED_PIN, OUTPUT);
  pinMode(UP_PIN, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    sentValue = String(results.value, HEX);

    // Show received value - HEX
    Serial.println(sentValue); //Serial.println(results.value, HEX);

    // If is the UP button of remote is pressed - e0e006f9 samsung remote
    if (results.value == 0xE0E006F9) {
      Serial.println("UP");
      digitalWrite(UP_PIN, 1);
    }

    digitalWrite(LED_PIN, 1);
    irrecv.resume(); // Receive the next value
  }

  delay(100);
  digitalWrite(LED_PIN, 0);
  digitalWrite(UP_PIN, 0);
}
