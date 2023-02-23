// Cynthia Tarwireyi, Dhanvarshinie Rajan, Kanokwan Haesatith group: 24 (2023)
// Work package 5
// Exercise 3
// Submission code: 56774


#include "dht.h";
dht DHT;

#define greenLED 13 // define the first LED connected to pin 13
#define redLED 11 // define the seconf LED connected to pin 11
#define blueLED 9 // define the third LED connected to pin 9

#define tempPin A0 // define the temp sensor pin connected to pin A0
#define lightPin A1 // define the light sensor pin connected to pin A1

void setup()
{
  Serial.begin(9600); //initialize the serial
  pinMode(greenLED, OUTPUT); // green as the output pin, which will generate an electrical signal.
  pinMode(redLED, OUTPUT); // red as the output pin, which will generate an electrical signal.
  pinMode(blueLED, OUTPUT); // blue as the output pin, which will generate an electrical signal.
  
  pinMode(tempPin, INPUT);
  pinMode(lightPin, INPUT);
  // Initate the serial port
    Serial.begin(9600);
}

void loop()
{
  // Read the data from the photoresistor
    int lightReading = analogRead(lightPin);
  // Serial.print(lightReading);
    // Map the data on a scale from 0% to 100%
   lightReading = map(lightReading, 11, 830, 0, 100);
    // Print the light persentage to serial
   analogWrite(10, lightReading);// write the mapped value to digital pin 10
 
  Serial.print(lightReading); Serial.println(" Light intensity");  // print the light intensity

   int readData = DHT.read22(tempPin); // use the dht library to read the temp pin.
   float tempInCelsius = DHT.temperature; // use the dht library to read the temperature.
   Serial.print(tempInCelsius); Serial.println(" degrees C"); // print the temp

  
  if (lightReading == 0){ //if light intensity value is 0
    // if temperature is less than -12C, power on the green LED
    if (tempInCelsius <= -12){ 
    	digitalWrite(greenLED, HIGH); //green LED on
    	digitalWrite(redLED, LOW); // red LED off
      	digitalWrite(blueLED, LOW); // blue LED off
    }
    else{// If the temperature is higher than -12
         // Power on the red LED
    	digitalWrite(redLED, HIGH);// red LED on 
      	digitalWrite(greenLED, LOW); // green LED off
      	digitalWrite(blueLED, LOW); // blue LED off
    }
  }
  // if the light intensity is between 1 and 20
  else if (lightReading >= 1 && lightReading <= 20) {
    // if the temperature is between -12 and 0, Power on the green LED
    if(tempInCelsius > -12 && tempInCelsius <= 0){ 
      	digitalWrite(redLED, LOW); // red LED off
      	digitalWrite(greenLED, HIGH); // green LED on 
      	digitalWrite(blueLED, LOW); // blue LED off
    }
    // if the temperature is more than 0, Power on the red LED
    else if (tempInCelsius > 0){ 
        digitalWrite(redLED, HIGH); // red LED on 
      	digitalWrite(greenLED, LOW); // green LED off
      	digitalWrite(blueLED, LOW); // blue LED off
    }
    else{ // If the temperature is lower than -12, Power on the blue led
        digitalWrite(redLED, LOW); // red LED off
      	digitalWrite(greenLED, LOW); // green LED off
      	digitalWrite(blueLED, HIGH); // blue LED on 
    }
  }
  // if the light intensity isbetween 21 and 60
  else if (lightReading >= 21 && lightReading <= 60){ 
    // if the temperature is betwwen 0 and 20, Power on the green LED
    if (tempInCelsius >= 0 && tempInCelsius <= 20){ 
    	digitalWrite(redLED, LOW); // red LED off
      	digitalWrite(greenLED, HIGH); // green LED on 
      	digitalWrite(blueLED, LOW); // blue LED off
    }
    else if(tempInCelsius > 20){ // if the temperature is more than 20, Power on the red LED
        digitalWrite(redLED, HIGH); // red LED on 
      	digitalWrite(greenLED, LOW); // greenLED off
      	digitalWrite(blueLED, LOW); // blue LED off
    }
    else{ // else If the temperature is lower than 0, Power on the blue LED
        digitalWrite(redLED, LOW);// red LED off
      	digitalWrite(greenLED, LOW); // green light off
      	digitalWrite(blueLED, HIGH); // blue LED on 
    }
  }
  // finally, if the light intensity value is between 61 and 100
  else{ 
    if(tempInCelsius >= 21){ // if the temperature is more than 21, Power on the green LED
    	digitalWrite(redLED, LOW); // red LED off
      	digitalWrite(greenLED, HIGH); // green LED on 
      	digitalWrite(blueLED, LOW); // blue LED off
    }
    // If the temperature is lower than 21C, Power on the blue LED
    else{
    	digitalWrite(redLED, LOW); // red LED off
      	digitalWrite(greenLED, LOW); // green LED off
      	digitalWrite(blueLED, HIGH); // blue LED on 
    }
  
  }
  delay(1000);//delay program by one second
}
