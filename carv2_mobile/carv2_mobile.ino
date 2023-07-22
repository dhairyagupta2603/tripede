#include <Servo.h>

#define FORWARD 1
#define BACK 2
#define LEFT 3
#define RIGHT 4
#define STOP 5

#define FU 6
#define FD 7
#define BU 8
#define BD 9
#define RESET 0

int forwardl = 8, backwardl = 7;
int forwardr = 12, backwardr = 13;
int frontSeg = 5, backSeg = 6;
int posf = 0, posb = 0;
int direct = 0, lift = 0;
Servo sf, sb;

void setup(){
  Serial.begin(9600);
  sf.attach(frontSeg);
  sb.attach(backSeg);
  sf.write(0);
  sb.write(0);
  pinMode(forwardl, OUTPUT);
  pinMode(backwardl, OUTPUT);
  pinMode(forwardr, OUTPUT);
  pinMode(backwardr, OUTPUT);
  digitalWrite(forwardl, LOW);
  digitalWrite(backwardl, LOW);
  digitalWrite(forwardr, LOW);
  digitalWrite(backwardr, LOW);
}

void loop(){
  while (Serial.available() > 0){
    direct = Serial.read();
    if (direct == FORWARD){
      digitalWrite(forwardl, HIGH);
      digitalWrite(forwardr, HIGH);
      digitalWrite(backwardr, LOW);
      digitalWrite(backwardl, LOW);
    }
    if (direct == BACK){
      digitalWrite(forwardl, LOW);
      digitalWrite(forwardr, LOW);
      digitalWrite(backwardr, HIGH);
      digitalWrite(backwardl, HIGH);
    }
      
    if (direct == LEFT){
      digitalWrite(forwardl, HIGH);
      digitalWrite(forwardr, LOW);
      digitalWrite(backwardr, HIGH);
      digitalWrite(backwardl, LOW);
    }
      
    if (direct == RIGHT){
      digitalWrite(forwardl, LOW);
      digitalWrite(forwardr, HIGH);
      digitalWrite(backwardr, HIGH);
      digitalWrite(backwardl, LOW);
    }
    
    if (direct == STOP){
      digitalWrite(forwardl, LOW);
      digitalWrite(backwardl, LOW);
      digitalWrite(forwardr, LOW);
      digitalWrite(backwardr, LOW);
    }
    lift = Serial.read();
    if (lift == FU)
      sf.write(70);
    if (lift == FD)
      sf.write(-70);
    if (lift == BU)
      sb.write(70);    
    if (lift == BD)
      sb.write(-70);
    if (lift == RESET){
      sf.write(0);
      sb.write(0);
    }
  }
}
