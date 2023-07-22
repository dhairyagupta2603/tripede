//Motor 1
const int motor = 13;  
//This will run only one time.
void setup(){
    pinMode(motor, OUTPUT);
}


void loop(){
    digitalWrite(motor, HIGH);
}
