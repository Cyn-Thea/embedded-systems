// Cynthia Tarwireyi, Dhanvarshinie Rajan, Kanokwan Haesatith group: 24 (2023)
// Work package 5
// Exercise 1 
// Submission code: 56774

int led1 = 12; // define the first LED connected to pin 13
int led2 = 9;  // define the second LED connected to pin 13
int buttonPin = 4; // define the button connected to pin 9

void setup()
{
  pinMode(led1, OUTPUT);  // set the first LED as an output
  pinMode(led2, OUTPUT);  // set the second LED as an output
  pinMode(buttonPin, INPUT); // set the button as an input
}

void loop()
{
  // read the button state
  int buttonState = digitalRead(buttonPin);
  // check if button is clicked and turn the second LED on or off based on the button state
  if (buttonState == HIGH) {
    // LED should light up
    digitalWrite(led2, HIGH);
  } else {
    // LED should not light up
    digitalWrite(led2, LOW);
  }
  
  
  // Call LED1 to light up
  digitalWrite(led1, HIGH);
  // Wait for 0.5 seconds for the time between blinks
  delay(500); 
  // Call LED1 to turn light off
  digitalWrite(led1, LOW);
  // Wait for 0.5 seconds for the time between blinks
  delay(500); 
}
