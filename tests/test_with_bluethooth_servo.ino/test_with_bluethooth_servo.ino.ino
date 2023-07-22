#include <SoftwareSerial.h>
#include <Servo.h>
SoftwareSerial bt(2,3);
int pos = 0;
int incomingByte = 0;
Servo serv;

void setup()
{
  Serial.begin(9600);
  bt.begin(9600);
  serv.attach(5);
  serv.write(0);
}

void loop()
{
  if (bt.available() > 0) {
    //Serial.write(bt.read());
    incomingByte = bt.read();
  }
  switch(incomingByte){
    case 'R':
    serv.write(0);
    break;
    case 'U':
    serv.write(45);
    break;
    case 'D':
    serv.write(-45);
    break;
  }
}
