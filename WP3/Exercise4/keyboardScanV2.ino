// Cynthia Tarwireyi, Dhanvarshinie Rajan, Kanokwan Haesatith group: 24 (2023)
// Work package 3
// Exercise 4
// Submission code: B92

#include <Keypad.h> //includes the Keypad library, which is necessary to use the Keypad class.

/*  declare the constants ROWS and COLS to store the number of rows and columns in the keypad, respectively. ROWS is set to 4 and COLS is set to 4.  */
const byte ROWS = 4; 
const byte COLS = 4; 

/*
declare a two-dimensional array of characters, hexaKeys, which stores the characters to be displayed on the keypad
*/

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

//These two lines declare arrays rowPins and colPins to store the pin numbers of the rows and columns of the keypad, respectively.
byte rowPins[ROWS] = {11, 10, 9, 8};  
byte colPins[COLS] = {7, 6, 5, 4}; 

//creates an instance of the Keypad class customKeypad using the constructor and sets the properties of the custom keypad.
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), 
                             rowPins, 
                             colPins, 
                             ROWS, 
                             COLS); 

void setup()
{
  Serial.begin(9600); // initialize the serial communication with a baud rate of 9600.
}

void loop()
{
  char customKey = customKeypad.getKey();// declare a variable "customKey", that stored the value of "customKeypad.getKey()"
  //This "customKeypad.getKey()" function  returns the value of the button that is currently being pressed.
  
  if (customKey != 0){ // checks if the value of customKey is not equal to 0, means that a button is currently being pressed.
    Serial.println(customKey); //If the button is  pressed,print the value of customKey to the serial port.
  }
  
}