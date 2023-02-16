// Cynthia Tarwireyi, Dhanvarshinie Rajan, Kanokwan Haesatith group: 24 (2023)
// Work package 4
// Exercise 3
// Submission code: 44524

#include <Adafruit_NeoPixel.h>

#define NEO_PIN    7 // the pin number the NeoPixel is attached to
#define RED_LED   11 // the pin number for the LED
#define NUMPIXELS 12 // the number of neopixels in the strip
#define TEMP_PIN  A0 // the pin number for the temperature sensor

// Initialize the temperatures ranges
const int temp1 = 10;
const int temp2 = 20;
const int temp3 = 30;
const int temp4 = 40;
const int temp5 = 50;
const int temp6 = 60;
const int temp7 = 80;
const int temp8 = 100;

int litPixels = 0; //initialize the number of NeoPixels that should be lit, based on temp

// create an instance of the Adafruit_NeoPixel object, which is used 
// to control the NeoPixels.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS , NEO_PIN, NEO_GRB + NEO_KHZ800); // Create an instance of the Adafruit_NeoPixel library

void setup() { 
  Serial.begin(9600); // Start the serial communication at 9600
  pixels.begin(); // Initialize the NeoPixel strip object
 
  pinMode(TEMP_PIN, INPUT); // Set the temp Pin as an input, which will detect an incoming electrical signal
  pinMode(RED_LED, OUTPUT); // set red led to OUTPUT,which will generate an elecatrical signal.
}

// 44524
void loop() { 
 // Read the voltage from the sensor
  float voltage = analogRead(TEMP_PIN) * (5.0 / 1024.0); 
  // Convert the voltage to temperature in Celsius
  int tempInCelsius = (voltage - 0.5) * 100; 
  //print temp
  Serial.print(tempInCelsius); Serial.println(" degrees C");
  
  
  // use the temperature reading to determine 
  // the number of NeoPixels that should be lit up
  
  if (tempInCelsius < temp1) { // if temp is less than 10
    litPixels = 1; //light up 1 pixel
  } else if (tempInCelsius >= temp1 && tempInCelsius < temp2) {// if temp is between 10 and 20
    litPixels = 2; //light up 2 pixels
  } else if (tempInCelsius >= temp2 && tempInCelsius < temp3) {// if temp is between 20 and 30
    litPixels = 3;//light up 3 pixels
  } else if (tempInCelsius >= temp3 && tempInCelsius < temp4) {// if temp is between 30 and 40
    litPixels = 4;//light up 4 pixels
  } else if (tempInCelsius >= temp4 && tempInCelsius < temp5) {// if temp is between 40 and 50
    litPixels = 5;//light up 5 pixels
  } else if (tempInCelsius >= temp5 && tempInCelsius < temp6) {// if temp is between 50 and 60
    litPixels = 6;//light up 6 pixels
  } else if (tempInCelsius >= temp6 && tempInCelsius < temp7) {// if temp is between 60 and 80
    litPixels = 8; //light up 8 pixels
  } else if (tempInCelsius >= temp7 && tempInCelsius < temp8) {// if temp is between 80 and 100
    litPixels = 10;//light up 10 pixels
  } else {// if temp is higher than 100
    litPixels = 12; //light up 12 pixels
  }
   
  // loop through all the 12 NEOpixels to set the color of each 
  // NeoPixel based on the value of numPixels
  for (int i = 0; i < NUMPIXELS; i++) {
    if (i < litPixels) {
      pixels.setPixelColor(i, pixels.Color(255, 0, 0)); //Set the color of the lit NeoPixels to red
    } else {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0)); //turn off the NeoPixel
    }
      pixels.show(); // send the updated pixel color to the hardware.
  }

  // th red LED is only activated when all the pixels are lit
  if (litPixels >= 12) { 
	  digitalWrite(RED_LED, HIGH); // If all the NeoPixels are lit, turn on the LED
  } else { 
  	  digitalWrite(RED_LED, LOW); // If not all the NeoPixels are lit, turn off the LED
  }
  delay(1000); // Wait for 1 second
}