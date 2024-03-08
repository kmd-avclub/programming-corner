const int PIN_OUT = 13;
const int DELAY_TIME = 1000;


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(PIN_OUT, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(PIN_OUT, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(DELAY_TIME);                      // wait for a second
  digitalWrite(PIN_OUT, LOW);   // turn the LED off by making the voltage LOW
  delay(DELAY_TIME);                      // wait for a second
}
