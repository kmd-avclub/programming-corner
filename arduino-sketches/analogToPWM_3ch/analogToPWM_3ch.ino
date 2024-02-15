/*
this sketch takes 3 inputs A0 A1 A2 0-5V and converts to 3 outputs D9 D10 D11 PWM 0-255/0-5V.
It can be used as a sound to light device, asuming a DC bias set between the audio signals and the analog inputs.
The PWM can control 0-5V loads, or MOSFETS for bigger loads (such as 12 or 24VDC led strips).

The analog signal are first ranged from 0~1024 to -512~+512 to match positive/negative phases of original AC signal
the signal is then multiplied over 0 if it is under 0, effectively turning every negative spike in a positive spike
the signal is then divided by 2 and sent out
*/

float inputSignal;
float outputSignal;
const int delayTime = 10;
const int inA = 0;
const int inB = 1;
const int inC = 2;
const int outA = 9;
const int outB = 10;
const int outC = 11;

void setup() {
  pinMode(outA, OUTPUT);
  pinMode(outB, OUTPUT);
  pinMode(outC, OUTPUT);
  delay(100);
}

void acToPWM(int inputPin, int outputPin){
  inputSignal = analogRead(inputPin);          //inputSignal 0~1024
  inputSignal -= inputSignal/2;                //inputSignal (0~1024-512)/2 = -512~512
  if (inputSignal < 0){                        //if inputSignal reaches under 0 (=every negative phase), multiply it above 0 (- * - = +)
    inputSignal = inputSignal * -1;
  }
  outputSignal = inputSignal/2;                //inputSignal (0~512)/2 becomes outputSignal 0~255, range of PWM
  digitalWrite(outputPin, outputSignal);
  delay(delayTime);
}

void dcToPWM(int inputPin, int outputPin){
  inputSignal = analogRead(inputPin);
  outputSignal = inputSignal/4;                //inputSignal (0~1024)/2 becomes outputSignal 0~255, range of PWM
  digitalWrite(outputPin, outputSignal);
  delay(delayTime);
}

void loop() {
  //use acToPWM() or dcToPWM()
  acToPWM(inA, outA);
  acToPWM(inB, outB);
  acToPWM(inC, outC);
}
