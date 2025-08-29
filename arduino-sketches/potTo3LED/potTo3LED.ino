// Pin definitions
const int ANALOG_INPUT_PIN = 0;
const int LED_GREEN_PIN = 3;
const int LED_YELLOW_PIN = 4;
const int LED_RED_PIN = 5;

// ADC constants
const int ADC_MAX_VALUE = 1023;
const int ADC_MIN_THRESHOLD = 10;

// Calculate thresholds automatically
const int ADC_LOW_THRESHOLD = ADC_MAX_VALUE / 3;      // 341
const int ADC_MID_THRESHOLD = (ADC_MAX_VALUE * 2) / 3; // 682

const int LOOP_DELAY_MS = 10;

int analogValue;

void setup() {
  //declare pins
  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_YELLOW_PIN, OUTPUT);
  pinMode(LED_RED_PIN, OUTPUT);
  //turn LEDs off
  digitalWrite(LED_GREEN_PIN, LOW);
  digitalWrite(LED_YELLOW_PIN, LOW);
  digitalWrite(LED_RED_PIN, LOW);
}

void loop() {
  analogValue = analogRead(ANALOG_INPUT_PIN);
  
  // Turn on LEDs based on level
  if (analogValue >= ADC_MIN_THRESHOLD) {
    digitalWrite(LED_GREEN_PIN, HIGH);  // Always first
    
    if (analogValue > ADC_LOW_THRESHOLD) {
      digitalWrite(LED_YELLOW_PIN, HIGH);  // Medium level
      
      if (analogValue > ADC_MID_THRESHOLD) {
        digitalWrite(LED_RED_PIN, HIGH);  // High level
      }
    }
  }
  
  delay(LOOP_DELAY_MS);
}
