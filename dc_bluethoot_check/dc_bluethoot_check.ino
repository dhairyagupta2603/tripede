#include <SoftwareSerial.h>

SoftwareSerial bt(2,3);
int incomingByte = 0;

void setup()
{
  Serial.begin(9600);
  bt.begin(9600);
  pinMode(8, OUTPUT);
  digitalWrite(8, LOW);
}

void loop()
{
  if (bt.available() > 0) {
    //Serial.write(bt.read());
    incomingByte = bt.read();
  }
  if (incomingByte == 1){
    digitalWrite(8, HIGH);
  }
}
