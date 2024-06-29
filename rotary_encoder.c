/*
    Project name : Arduino Uno Rotary Encoder 
    Modified Date: 29-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-uno-rotary-encoder
*/

// Define the pins connected to the rotary encoder
const int encoderPinA = 2;  // CLK pin
const int encoderPinB = 3;  // DT pin
const int buttonPin = 4;    // SW (push-button) pin

int encoderPos = 0; // Current position of the encoder
int lastState = 0;  // Previous state of the DT pin

void setup() {
  Serial.begin(9600); // Initialize serial communication for debugging
  pinMode(encoderPinA, INPUT);
  pinMode(encoderPinB, INPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Internal pull-up resistor for button pin
  
  // Print initial encoder position
  Serial.print("Initial position: ");
  Serial.println(encoderPos);
}

void loop() {
  // Read current state of DT pin
  int currentState = digitalRead(encoderPinB);
  
  // Check for rotation
  if (currentState != lastState) {
    if (digitalRead(encoderPinA) != currentState) {
      // Clockwise rotation
      encoderPos++;
    } else {
      // Counterclockwise rotation
      encoderPos--;
    }
    Serial.print("Position: ");
    Serial.println(encoderPos);
  }
  
  lastState = currentState; // Update last state of DT pin
}
