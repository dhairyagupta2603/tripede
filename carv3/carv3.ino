float tempe;
char sv;
void setup() {
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(13, OUTPUT);
Serial.begin(9600);
}



void loop() {
if (Serial.available())
{
sv=Serial.read();
}
Serial.println(sv);
{



if(sv=='f'){
digitalWrite(13,HIGH);



}
else if(sv=='b')
{
digitalWrite(6,HIGH);
digitalWrite(4,HIGH);
digitalWrite(7,LOW);
digitalWrite(5,LOW);
}
else if(sv=='l')
{
digitalWrite(6,LOW);
digitalWrite(4,HIGH);
digitalWrite(7,HIGH);
digitalWrite(5,LOW);
}
else if(sv=='r')
{
digitalWrite(6,HIGH);
digitalWrite(4,LOW);
digitalWrite(7,LOW);
digitalWrite(5,HIGH);



}
else
{
digitalWrite(6,LOW);
digitalWrite(4,LOW);
digitalWrite(7,LOW);
digitalWrite(13,LOW);
}
tempe = map(((analogRead(A0)-20)*3.04),0,1023,-40,125);
Serial.println(tempe);






}
}
