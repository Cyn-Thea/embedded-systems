// Cynthia Tarwireyi, Dhanvarshinie Rajan, Kanokwan Haesatith group: 24 (2023)
// Work package 6
// Exercise 2
// Submission code: 65524

#define trigPin 7 //Define trigPin as pin 7
#define echoPin 7 // Define echoPin as pin 7
#define speakerPin 9 // Define speakerPin as pin 9
#define led1 5 // Define led1 as pin 5
#define led2 4 // Define led2 as pin 4
#define led3 3 // Define led3 as pin 3
#define led4 2 // Define led4 as pin 2


int distance;// Variable to store the distance in cm
float duration;// Variable to store the duration of the pulse
int cm = 0;// Variable to store the distance in cm after being calculated
int soundLevel = 0;// Variable to store the sound level


void setup() {


pinMode(led1, OUTPUT);// Set led1 pin as an output
pinMode(led2, OUTPUT);// Set led2 pin as an output
pinMode(led3, OUTPUT);// Set led3 pin as an output
pinMode(led4, OUTPUT);// Set led4 pin as an output
pinMode(speakerPin, OUTPUT);// Set speakerPin pin as an output
Serial.begin(9600);// Initialize serial communication 
}

// Function to read the distance from the ultrasonic sensor
long readDistance(int trig_Pin, int echo_Pin ) {
pinMode(trigPin,OUTPUT);// Set trigPin as an output
digitalWrite(trigPin,LOW);// Set the trigPin low for 2 microseconds
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);// Set the trigPin high for 10 microseconds
delayMicroseconds(10);
digitalWrite(trigPin,LOW);// Set the trigPin low again
pinMode(echoPin,INPUT);// Set echoPin as an input
duration = pulseIn(echoPin,HIGH);// Measure the duration of the pulse on the echoPin
distance = duration * 0.01723;// Calculate the distance in cm
return distance;// Return the distance
}


// Function to light up LEDs based on the distance
void litLEDs(int distance) {
  if(distance >200){ //if distance is greater than 200cm, then this if statement gets executed
digitalWrite(led1, LOW); //led1 is turned off
digitalWrite(led2, LOW); //led2 is turned off
digitalWrite(led3, LOW); //led3 is turned off
digitalWrite(led4, LOW);}//led4 is turned off
    
else if (distance <= 90) { //if distance is lesser than or equal to 90 
digitalWrite(led1, LOW);  //led1 is turned off
digitalWrite(led2, HIGH); //led2 is turned on 
digitalWrite(led3, HIGH); //led3 is turned on
digitalWrite(led4, HIGH); //led4 is turned on
} else if (distance <= 120) { //if distance is lesser than or equal to 120
digitalWrite(led1, LOW); //led1 is turned off
digitalWrite(led2, LOW); //led2 is turned off
digitalWrite(led3, HIGH); //led 3 is turned on
digitalWrite(led4, HIGH); //led4 is turned on
} else if (distance <= 200) { //if distance is lesser or equal to 200
digitalWrite(led1, LOW); //led1 is turned off
digitalWrite(led2, LOW); //led2 is turned off
digitalWrite(led3, LOW); //led3 is turned off
digitalWrite(led4, HIGH); //led4 is turned on 
}   
}

void litAllLED() //function to light all LEDs and make it blink
 { //this function is to make the light on and off pausing 100 microseconds in between repeatedly 
  digitalWrite(led1, HIGH); //led1 is on 
	digitalWrite(led2, HIGH); //led2 is on 
	digitalWrite(led3, HIGH); //led3 is on
	digitalWrite(led4, HIGH); //led4 is on
  delay(100); //delay for 100 microseconds
digitalWrite(led1, LOW); //led1 is off
	digitalWrite(led2, LOW); //led2 is off
	digitalWrite(led3, LOW); //led3 is off 
	digitalWrite(led4, LOW); //led4 is off
delay(100);} //delay 100 microseconds



void setSoundLevel(int distance) {
  // Sets the sound level of the speaker based on the distance measured by the sensor
  if (distance < 200 && distance > 25) {
    // Maps the distance to a sound level between 200 Hz and 5000 Hz
    soundLevel = map(distance, 26, 200, 200, 5000);
    // Plays the tone with the calculated sound level for 100ms
    tone(speakerPin, soundLevel, 100);
  } else if (distance <= 25) {
    // If the distance is less than or equal to 25cm, plays a warning tone 5 times with a 200ms interval
    for (int i = 0; i < 5; i++) {
      litAllLED(); //call litAllLED fucntion
      soundLevel = 2000;//Sets the frequency of the tone to 2000 Hz by setting the soundLevel variable.
      tone(speakerPin, soundLevel, 200);//Generates a 200-millisecond tone with a frequency of 2000 Hz on the speakerPin output pin using the tone function.
      delay(200);//pauses the execution for 200 milliseconds
      noTone(speakerPin);//turns off the tone by calling the noTone function
      delay(200);//Pauses the execution for another 200 milliseconds 
    }
  } else {
    // If the distance is greater than 200cm, turns off the speaker
    noTone(speakerPin);
  }
}

void loop()
{
  // Reads the distance from the sensor connected to pins 7 and 7
  distance = readDistance(7,7);
  // Prints the distance to the serial monitor
  Serial.print("\n Distance: ");
  Serial.print(distance);
  Serial.print(" cm");
  // Sets the state of the LEDs based on the distance measured
  litLEDs(distance);
  // Sets the sound level of the speaker based on the distance measured
  setSoundLevel(distance);
  // Waits for 100ms before looping again
  delay(100);
}
