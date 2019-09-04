// RFD Transmit Example Code
// Sending is this simple. Works as any other serial communication device would

#include <RelayXBee.h>

#define RFDSerial Serial1
#define RFD_BAUD 38400

String packet;

void setup() { 
  Serial.begin(9600);
  RFDSerial.begin(RFD_BAUD); 
  }

void loop() {
    packet = "hello";
    RFDSerial.print(packet);
    delay(2000);
}
