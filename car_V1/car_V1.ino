#include <Servo.h>

#define FORWARD 'w'
#define BACK 's'
#define LEFT 'a'
#define RIGHT 'd'
#define STOP 'q'

#define FU 'o'
#define FD 'p'
#define BU 'k'
#define BD 'l'
#define RESET 'i'

char sv = 0;
const int initPos = 90, upPos = 160, downPos = 20;
const int forwardl = 8, backwardl = 7;
const int forwardr = 12, backwardr = 13;
const int frontSegr = 10, backSegr = 6;
const int frontSegl = 11, backSegl = 5;
Servo sfr, sfl, sbr, sbl;

void directionalMovement(char *direction);
void servoMovement(char *lift);

void setup(){
  Serial.begin(9600);
  sfr.attach(frontSegr);
  sfl.attach(frontSegl);
  sbr.attach(backSegr);
  sbl.attach(backSegl);
  sfr.write(initPos);
  sfl.write(initPos);
  sbr.write(initPos);
  sbl.write(initPos);
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
  if (Serial.available()){
    sv = Serial.read();
    directionalMovement(&sv);
    servoMovement(&sv);
  }
}

// wasd movement of wheels
void directionalMovement(char *direction){
  if (*direction == FORWARD){
    digitalWrite(forwardl, HIGH);
    digitalWrite(forwardr, HIGH);
    digitalWrite(backwardr, LOW);
    digitalWrite(backwardl, LOW);
  }
  if (*direction == BACK){
    digitalWrite(forwardl, LOW);
    digitalWrite(forwardr, LOW);
    digitalWrite(backwardr, HIGH);
    digitalWrite(backwardl, HIGH);
  }
  if (*direction == LEFT){
    digitalWrite(forwardl, HIGH);
    digitalWrite(forwardr, LOW);
    digitalWrite(backwardr, HIGH);
    digitalWrite(backwardl, LOW);
  }
  if (*direction == RIGHT){
    digitalWrite(forwardl, LOW);
    digitalWrite(forwardr, HIGH);
    digitalWrite(backwardr, LOW);
    digitalWrite(backwardl, HIGH);
  }
  if (*direction == STOP){
    digitalWrite(forwardl, LOW);
    digitalWrite(backwardl, LOW);
    digitalWrite(forwardr, LOW);
    digitalWrite(backwardr, LOW);
  }
}

void servoMovement(char *lift){
  if (*lift == FU){
  sfr.write(upPos);
  sfl.write(downPos);
  }
  if (*lift == FD){
    sfl.write(upPos);
    sfr.write(downPos);
  }
  if (*lift == BU){
    sbr.write(downPos);
    sbl.write(upPos);
  }
  if (*lift == BD){
    sbl.write(downPos);
    sbr.write(upPos);
  }
  if (*lift == RESET){
    sfr.write(initPos);
    sfl.write(initPos);
    sbr.write(initPos);
    sbl.write(initPos);
  }
}
