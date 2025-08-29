#include <elapsedMillis.h> //this library should be installed with the help manager

const int RELAY_CONTROL_PIN = 13;
const int TOGGLE_INTERVAL_MS = 5000;
const int SERIAL_BAUD_RATE = 9600;

// State tracking variables
bool relayState = false;                    // Current relay state
elapsedMillis timeElapsed;                  // Automatic timer

void setup() {
  pinMode(RELAY_CONTROL_PIN, OUTPUT);
  Serial.begin(SERIAL_BAUD_RATE);
  Serial.println("Relay controller started");
}

void loop() {
  // Check if enough time has elapsed
  if (timeElapsed >= TOGGLE_INTERVAL_MS) {
    timeElapsed = 0;                        // Reset timer
    
    relayState = !relayState;               // Toggle state
    digitalWrite(RELAY_CONTROL_PIN, relayState);
    
    // Print current state
    Serial.println(relayState ? "Relay ON" : "Relay OFF");
  }
  
  // Other code can run here without being blocked
}
