// Cynthia Tarwireyi, Dhanvarshinie Rajan, Kanokwan Haesatith group: 24 (2023)
// Work package 3
// Exercise 1 
// Submission code: B92

const int led1 = 13;   // define the first LED connected to pin 13
const int led2 = 12;   // define the second LED connected to pin 13
const int button = 7;  // define the button connected to pin 7

void setup()
{
  pinMode(led1, OUTPUT);  // set the first LED as an output
  pinMode(led2, OUTPUT);  // set the second LED as an output
  pinMode(button, INPUT); // set the button as an input
}

void loop()
{
  
  
  digitalWrite(led1, HIGH);   // turn the first LED on
  delay(1000);                // wait for 1 second
  digitalWrite(led1, LOW);    // turn the first LED off
  delay(1000);                // wait for 1 second
  
  int buttonState = digitalRead(button); // read the button state
  digitalWrite(led2, buttonState);       // turn the second LED on or off based on the button state

}
  

