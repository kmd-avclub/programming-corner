/*
this sketch takes 3 inputs A0 A1 A2 0-5V and converts to 3 outputs D9 D10 D11 PWM 0-255/0-5V.
It can be used as a sound to light device, asuming a DC bias set between the audio signals and the analog inputs.
The PWM can control 0-5V loads, or MOSFETS for bigger loads (such as 12 or 24VDC led strips).
*/

float inputSignal;
float outputSignal;
int delayTime = 10;
int inA = 0;
int inB = 1;
int inC = 2;
int outA = 9;
int outB = 10;
int outC = 11;

void setup() {
  pinMode(outA, OUTPUT);
  pinMode(outB, OUTPUT);
  pinMode(outC, OUTPUT);
  delay(100);
}

void aToPWM(int inputPin, int outputPin){
  inputSignal = analogRead(inputPin);
  outputSignal = inputSignal/4;
  digitalWrite(outputPin, outputSignal);
  delay(delayTime);
}

void loop() {
  aToPWM(inA, outA);
  aToPWM(inB, outB);
  aToPWM(inC, outC);
}
