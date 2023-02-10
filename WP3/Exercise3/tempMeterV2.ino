// Cynthia Tarwireyi, Dhanvarshinie Rajan, Kanokwan Haesatith group: 24 (2023)
// Work package 3
// Exercise 3.1
// Submission code: B92

#define greenLED 13
#define redLED 12
#define blueLED 11
#define tempPin A0

void setup()
{
  Serial.begin(9600); //initialize the serial
  pinMode(greenLED, OUTPUT); // green as the output pin, which will generate an electrical signal.
  pinMode(redLED, OUTPUT); // red as the output pin, which will generate an electrical signal.
  pinMode(blueLED, OUTPUT); // blue as the output pin, which will generate an electrical signal.
 // pinMode(10, OUTPUT);
  
  pinMode(tempPin, INPUT);
  pinMode(A1, INPUT);
  // Initate the serial port
    Serial.begin(9600);
  
}

void loop()
{
  //getting the voltage reading from the value on the temperature sensor pin
 int reading = analogRead(tempPin); 
  
  // converting the reading to voltage by multiplying by 5v
 float voltage = reading * 5.0;
  //1024 analogue if we have 5V.
 voltage /= 1023.03; 
  
  //printing the voltage
 Serial.print(voltage); Serial.println(" volts");
 
 // Calculating  temperature in celcius
  float tempInCelsius = (voltage - 0.5) * 100 ;
  
  Serial.print(tempInCelsius); Serial.println(" degrees C");
  
  // Read the data from the photoresistor
    int lightReading = analogRead(A1);
 // Serial.print(lightReading);
    // Map the data on a scale from 0% to 100%
   lightReading = map(lightReading, 54, 974, 0, 100);
    // Print the light persentage to serial
   analogWrite(10, lightReading);// write the mapped value to digital pin 10

  Serial.print(lightReading); Serial.println(" Light intensity");
  
  
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