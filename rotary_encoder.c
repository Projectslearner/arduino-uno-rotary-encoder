/*
    Project name : Rotary encoder
    Modified Date: 09-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-uno-rotary-encoder
*/

#include <AccelStepper.h>

#define STEP_PIN 2    // Define the step pin
#define DIR_PIN 3     // Define the direction pin
#define ENABLE_PIN 4  // Define the enable pin

AccelStepper stepper(1, STEP_PIN, DIR_PIN); // Initialize stepper motor on pins 2 and 3

void setup() 
{
  pinMode(ENABLE_PIN, OUTPUT);  // Set the enable pin as output
  digitalWrite(ENABLE_PIN, LOW); // Enable the motor driver
  stepper.setMaxSpeed(1000);    // Set the maximum speed in steps per second
  stepper.setSpeed(500);        // Set the target speed in steps per second
}

void loop()
{
  stepper.runSpeed();  // Move the stepper motor at the set speed
}
