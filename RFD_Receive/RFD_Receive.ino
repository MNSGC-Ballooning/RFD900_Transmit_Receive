// RFD Receive Example Code

#define RFDSerial Serial1
#define RFD_BAUD 38400  // This is the baud all of our RFDs communicate at. They can be changed to something else, but you have to make sure these always match up.

char packet[100]; // Make sure the size of this array is larger than your largest data string will be. In this case, 100 characters is the max.

void setup() {
  Serial.begin(9600);
  RFDSerial.begin(RFD_BAUD);
}

void loop() {
  if(RFDSerial.available()>0){                  // Checks for any incoming bytes
    delay(10);                                  // Bytes will be received one at a time unless you add a small delay so the buffer fills with your message
    int incomingBytes = RFDSerial.available();  // Checks number of total bytes to be read
    Serial.println(incomingBytes);              // Just for testing to see if delay is sufficient to receive all bytes.
    for(int i=0; i<incomingBytes; i++)
    {
      packet[i] = RFDSerial.read();             // Reads bytes one at a time and stores them in a character array.
    }
    Serial.println(packet);                     // prints whole character array
  }
}
