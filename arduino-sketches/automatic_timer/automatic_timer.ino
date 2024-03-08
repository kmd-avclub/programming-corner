const int PIN_OUT = 13; //this is the control cable pin that will go to the relay module, remember to plug also +5V and GND from the arduino to the relay module
const int DELAY_TIME = 5000; //set timer value in milliseconds here (1sec = 1000ms)


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(PIN_OUT, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(PIN_OUT, HIGH);  // turn the LED on (HIGH is the voltage level)
  Serial.println("pin 13 is on");
  delay(DELAY_TIME);                      // wait for a second
  digitalWrite(PIN_OUT, LOW);   // turn the LED off by making the voltage LOW
  Serial.println("pin 13 is off");
  delay(DELAY_TIME);                      // wait for a second
}
