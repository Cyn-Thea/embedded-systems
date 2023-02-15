// Cynthia Tarwireyi, Dhanvarshinie Rajan, Kanokwan Haesatith group: 24 (2023)
// Work package 4
// Exercise 2
// Submission code: 44524

#include <Servo.h> //include servo library for servo instance

Servo servoMotor;// declare a Servo object
int servoPin = A0; // define the pin the servo is attached to
volatile int flag = 0; // Variable to keep track of the interrupt flag

void setup() { 
  Serial.begin(9600); // start the serial communication
  servoMotor.attach(servoPin); // attach the servo to the defined pin
  attachInterrupt(digitalPinToInterrupt(servoPin), second, CHANGE); // attaches an interrupt to the servoPin that calls the sec function when the signal changes.
}

void loop() { 
  //starts a loop that iterates from i=0 to i=360 in increments of 6, and from j=0 to j=60. 
  //this loop controls the servo's position and prints the time as int i handles the degree position of the servoMotor and int j handles the the amount of movement,
  //by incrementing i by 6 each time, the servo will move in increments of 6 degrees, resulting in 60 movement that j will be set to, which are the seconds
  for (int i = 0, j = 0; i <= 360, j <= 60; i += 6, j++) {
    if (i <= 180) {
      servoMotor.write(i);// If the servo's position is less than or equal to 180, set the servo's position to `i` . 30 times
    } else {
      servoMotor.write(i - 180);// if the servo's position is greater than 180, set the servo's position to `i - 180` which reset it to the starting point continue another 30 times
    } 
    flag++; // increment the flag variable by one
    if (flag > 0) {
      Serial.println(j); // checks whether the flag variable is greater than 0. If it is, the current second (j) is printed to the serial monitor.
    }
    delay(1000);  // delay for 1 second before continue the loop
  }
}


void second() {// function to handle the interrupt
  flag = !flag; //toggles the value of the flag variable when the interrupt is triggered by the sec function.
}
