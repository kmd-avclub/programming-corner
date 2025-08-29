/*
this sketch takes 3 inputs A0 A1 A2 0-5V and converts to 3 outputs D9 D10 D11 PWM 0-255/0-5V.
It can be used as a sound to light device, assuming a DC bias is set between the audio signals and the analog inputs.
The PWM can control 0-5V loads, MOSFETS for bigger loads (such as 12 or 24VDC led strips), etc.

The analog signals are first ranged from 0~1023 to -511~+512 to match positive/negative phases of origINPUT_Al AC signal
the signal is then multiplied over 0 if it is under 0, effectively turning every negative spike in a positive spike
the signal is then scaled and sent out
*/

// ADC and PWM constants
const int ADC_MAX_VALUE = 1023;           // Arduino 10-bit ADC maximum value
const int ADC_CENTER_VALUE = 512;         // Center point for AC signal (ADC_MAX_VALUE + 1) / 2
const int PWM_MAX_VALUE = 255;            // 8-bit PWM maximum value
const int PWM_MIN_VALUE = 0;              // PWM minimum value

// Scaling factors
const int AC_TO_PWM_DIVISOR = 2;          // Scale factor: ADC_CENTER_VALUE / PWM_MAX_VALUE
const int DC_TO_PWM_DIVISOR = 4;          // Scale factor: ADC_MAX_VALUE / PWM_MAX_VALUE

// Timing constants
const int LOOP_DELAY_MS = 10;             // Delay between processing cycles
const int SETUP_DELAY_MS = 100;           // Initial setup delay

// Pin assignments
const int INPUT_A = 0;
const int INPUT_B = 1;
const int INPUT_C = 2;
const int OUTPUT_A = 9;
const int OUTPUT_B = 10;
const int OUTPUT_C = 11;

float inputSignal;
float outputSignal;

void setup() {
  pinMode(OUTPUT_A, OUTPUT);
  pinMode(OUTPUT_B, OUTPUT);
  pinMode(OUTPUT_C, OUTPUT);
  delay(SETUP_DELAY_MS);
}

void acToPWM(int inputPin, int outputPin){
  inputSignal = analogRead(inputPin);                    // 0 to ADC_MAX_VALUE
  inputSignal -= ADC_CENTER_VALUE;                       // Center around zero: -ADC_CENTER_VALUE to +ADC_CENTER_VALUE
  
  if (inputSignal < PWM_MIN_VALUE){                      // Full-wave rectification
    inputSignal = inputSignal * -1;
  }
  
  outputSignal = inputSignal / AC_TO_PWM_DIVISOR;        // Scale to PWM range: 0 to PWM_MAX_VALUE
  analogWrite(outputPin, outputSignal);                 // Output PWM signal
  delay(LOOP_DELAY_MS);
}

void dcToPWM(int inputPin, int outputPin){
  inputSignal = analogRead(inputPin);                    // 0 to ADC_MAX_VALUE
  outputSignal = inputSignal / DC_TO_PWM_DIVISOR;        // Scale to PWM range: 0 to PWM_MAX_VALUE
  analogWrite(outputPin, outputSignal);                 // Output PWM signal  
  delay(LOOP_DELAY_MS);
}

void loop() {
  //use acToPWM() or dcToPWM()
  acToPWM(INPUT_A, OUTPUT_A);
  acToPWM(INPUT_B, OUTPUT_B);
  acToPWM(INPUT_C, OUTPUT_C);

  /*
  dcToPWM(INPUT_A, OUTPUT_A);
  dcToPWM(INPUT_B, OUTPUT_B);
  dcToPWM(INPUT_C, OUTPUT_C);
  */
}
