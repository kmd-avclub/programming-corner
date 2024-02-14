int analogValue; //set a storage place for our analogRead(0)
const int analogPin=0; //we declare our pins
const int ledG=3;
const int ledY=4;
const int ledR=5;
const int dt=10;  //delay time

void setup() {
pinMode(ledG,OUTPUT);
pinMode(ledY,OUTPUT);
pinMode(ledR,OUTPUT);
}
void loop() {
analogValue=analogRead(analogPin);

if (analogValue > 10 && analogValue < 341){
  digitalWrite(ledG,HIGH);
  digitalWrite(ledY,LOW);
  digitalWrite(ledR,LOW);
}
else if (analogValue > 341 && analogValue < 682){
  digitalWrite(ledG,HIGH);
  digitalWrite(ledY,HIGH);
  digitalWrite(ledR,LOW);
}
else if (analogValue > 682){
  digitalWrite(ledG,HIGH);
  digitalWrite(ledY,HIGH);
  digitalWrite(ledR,HIGH);s
}
else if (analogValue < 10){
  digitalWrite(ledG,LOW);
  digitalWrite(ledY,LOW);
  digitalWrite(ledR,LOW);
}
delay(dt);
}
