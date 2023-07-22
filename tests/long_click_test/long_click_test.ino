#define FORWARD 'w'
#define BACK 's'
#define LEFT 'a'
#define RIGHT 'd'

int forwardl = 8, backwardl = 7;
int forwardr = 12, backwardr = 13;

void setup(){
  Serial.begin(38400);
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
  char byte = 0;
  while (byte != 'q'){
    Serial.readBytes(&byte, 1);
    
    if (byte == FORWARD){
      digitalWrite(forwardl, HIGH);
      digitalWrite(forwardr, HIGH);
      digitalWrite(backwardr, LOW);
      digitalWrite(backwardl, LOW);
    }
    
    if (byte == BACK){
      digitalWrite(forwardl, LOW);
      digitalWrite(forwardr, LOW);
      digitalWrite(backwardr, HIGH);
      digitalWrite(backwardl, HIGH);
    }
    
    if (byte == LEFT){
      digitalWrite(forwardl, HIGH);
      digitalWrite(forwardr, LOW);
      digitalWrite(backwardr, HIGH);
      digitalWrite(backwardl, LOW);
    }
    
    if (byte == RIGHT){
      digitalWrite(forwardl, LOW);
      digitalWrite(forwardr, HIGH);
      digitalWrite(backwardr, HIGH);
      digitalWrite(backwardl, LOW);
    }
  } // !q
}
