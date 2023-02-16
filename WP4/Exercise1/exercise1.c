// C code
// Cynthia Tarwireyi, Dhanvarshinie Rajan, Kanokwan Haesatith group: 24 (2023)
// Work package 4
// Exercise 1
// Submission code: 44524

#define greenLED 13
#define yellowLED 12
#define whiteLED 11
#define blueLED 10
#define redLED 8
#define tempPin A1

// Initialize the temperatures ranges
const int temp1 = 0;
const int temp2 = 20;
const int temp3 = 50;
const int temp4 = 70;
const int temp5 = 100;

void setup()
{
 // Start the serial port
    Serial.begin(9600);
 // Set the led pins to output
    pinMode(greenLED, OUTPUT);// set green led to OUTPUT,which will generate an elecatrical signal.
    pinMode(yellowLED, OUTPUT);// set yellow led to OUTPUT,which will generate an elecatrical signal.
    pinMode(whiteLED, OUTPUT);// set white led to OUTPUT,which will generate an elecatrical signal.
    pinMode(blueLED, OUTPUT);// set blue led to OUTPUT,which will generate an elecatrical signal.
    pinMode(redLED, OUTPUT);// set red led to OUTPUT,which will generate an elecatrical signal.
  
  pinMode(tempPin, INPUT);//Set the temp Pin as an input, which will detect an incoming electrical signal
  
   // Set interrupt for temperature sensor,that triggers when there is a change in temp
  attachInterrupt(digitalPinToInterrupt(tempPin), TemperatureRange, CHANGE);

  // Periodically check temperature every 2 seconds
  setInterval();
}

void loop(){
//The loop is left empty to allow the 
//program to run uninterrupted.
}

void TemperatureRange()
{
  // Read the value from the temperature sensor pin
    int reading = analogRead(A1);
    // 1024 analogue if we have 5V. Hence, we do (analogReading * 5) / 1024. (ratios)
    // Convert the value into voltage by multiplying by 5 Volts
    float voltage = reading * 5.0;
    // Divide by the range of the value of temperature sensor (0-1023)
    voltage /= 1023;
    // Convert to degrees and consider the offset
    float tempInCelcius = (voltage - 0.5) * 100; // percentage max is because 10mV / 1degrees. Hence, 100 =  1/0.01. Voltage * (1 degrees / 0.01V) = Temp in celcius.
    Serial.print(tempInCelcius); Serial.println(" degrees C");
  
//if temperature lower than 0 all leds are off
if(tempInCelcius<temp1){
    digitalWrite(greenLED, LOW);//LED 1 off
    digitalWrite(yellowLED, LOW);//LED 2 off
    digitalWrite(whiteLED, LOW);//LED 3 off
    digitalWrite(blueLED, LOW);//LED 4 off
    digitalWrite(redLED, LOW);//LED 5 off
} //if temperature between 0 and 19, 1 led on
else if(tempInCelcius>=temp1&&tempInCelcius<temp2){
    digitalWrite(greenLED, HIGH);//LED 1 on
    digitalWrite(yellowLED, LOW);//LED 2 off
    digitalWrite(whiteLED, LOW);//LED 3 off
    digitalWrite(blueLED, LOW);//LED 4 off
    digitalWrite(redLED, LOW);//LED 5 off
}//if temperature between 20 and 49, 2 leds on
else if(tempInCelcius>=temp2&&tempInCelcius<temp3){
    digitalWrite(greenLED, HIGH);//LED 1 on
    digitalWrite(yellowLED, HIGH);//LED 2 on
    digitalWrite(whiteLED, LOW);//LED 3 off
    digitalWrite(blueLED, LOW);//LED 4 off
    digitalWrite(redLED, LOW);//LED 5 off
} //if temperature betwwen 50 and 69, 3 leds on
else if(tempInCelcius>=temp3&&tempInCelcius<temp4){
    digitalWrite(greenLED, HIGH);//LED 1 on
    digitalWrite(yellowLED, HIGH);//LED 2 on
    digitalWrite(whiteLED, HIGH);//LED 3 on
    digitalWrite(blueLED, LOW);//LED 4 off
    digitalWrite(redLED, LOW);//LED 5 off
}//if temperature betwwen 70 and 99, 4 leds on
else if(tempInCelcius>=temp4&&tempInCelcius<temp5){
   digitalWrite(greenLED, HIGH);//LED 1 on
    digitalWrite(yellowLED, HIGH);//LED 2 on
    digitalWrite(whiteLED, HIGH);//LED 3 on
    digitalWrite(blueLED, HIGH);//LED 4 on
    digitalWrite(redLED, LOW);//LED 5 off
}//if temperature is higher than 100, all leds are on
else {
    digitalWrite(greenLED, HIGH);//LED 1 on
    digitalWrite(yellowLED, HIGH);//LED 2 on
    digitalWrite(whiteLED, HIGH);//LED 3 on
    digitalWrite(blueLED, HIGH);//LED 4 on
    digitalWrite(redLED, HIGH);//LED 5 on
}
}

//https://www.instructables.com/id/Arduino-Timer-Interrupts/
// Function to set interrupt interval
void setInterval() {
  //set timer1 interrupt at 1Hz
  cli(); //stop interrupts
  TCCR1A = 0; // set entire TCCR0A register A to 0, to set timer to normal mode
  TCCR1B = 0; // set entire TCCR0B register B to 0, to set timer to normal mode
  TCNT1 = 0; //initialize the timer counter to 0
  // set compare match register for 1hz increments
  OCR1A = 15624;// = (16*10^6) / (1*1024) - 1 (must be <65536)
  
  TCCR1B |= (1 << WGM12); //turn on ctc mode on the register B,
  //which stops the timer when the timer reaches OCR1A (15624).
  
  TCCR1B |= (1 << CS12) | (1 << CS10);// Set CS10 and CS12 bits for 1024 prescaler
  // which divides the clock frequency by 1024 and increases the interrupt period.
 
  TIMSK1 |= (1 << OCIE1A); //enable timer1 compare interrupt
  sei(); //allow interrupts to go back to normal
}

// Interrupt service routine for interrupt interval
ISR(TIMER1_COMPA_vect) {
  // Call Temperature Range function
  TemperatureRange();
}
