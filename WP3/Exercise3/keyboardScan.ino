// Cynthia Tarwireyi, Dhanvarshinie Rajan, Kanokwan Haesatith group: 24 (2023)
// Work package 3
// Exercise 3.2 
// Submission code: B92

const int row1 = 11; // digital pin for row 1
const int row2 = 10; // digital pin for row 2
const int row3 = 9;  // digital pin for row 3
const int row4 = 8; // digital pin for row 4

const int col1 = 6;	// digital pin for column 1
const int col2 = 5; // digital pin for column 2
const int col3 = 4; // digital pin for column 3
const int col4 = 3; // digital pin for column 4

const int numberOfRows = 4;
const int numberOfColumns = 4;

// Initialize Matrix depicting the keypad and every key's position 
char keys[numberOfRows][numberOfColumns] =
    {{'1', '2', '3', 'A'},
     {'4', '5', '6', 'B'},
     {'7', '8', '9', 'C'},
     {'*', '0', '#', 'D'}};

// Assign row pin values to an array
int rowPins[numberOfRows] = {row1, row2, row3, row4};

// Assign column pin values to an array
int colPins[numberOfColumns] = {col1, col2, col3, col4};

void setup()
{
  // loop through the 4 rows pins and set them  to OUTPUT,
  // which will generate an elecatrical signal.
  for (int i=0; i<numberOfColumns; i++){
    pinMode(rowPins[i], OUTPUT);
    }
  
 // loop through the 4 coloumn pins and set them  to OUTPUT,
  // which will generate an elecatrical signal.
  for (int i=0; i<numberOfRows; i++){
    pinMode(colPins[i], INPUT);
     }
    // Establish serial communication
    Serial.begin(9600);
}


void loop()
{
    // Loop through the rows of the keypad
    for (int i = 0; i < numberOfRows; i++)
    {
        // Set the row to low
        digitalWrite(rowPins[i], LOW);
        // Loop through the columns of a particular row
        for (int j = 0; j < numberOfColumns; j++)
        {
            // If we detect no voltage from a particular column
            if (digitalRead(colPins[j]) == LOW)
            {
                // Print the key value thats being pressed
                Serial.println(keys[i][j]);
                // Delay the program the length of DELAY
                delay(1000);
            }
        }
        // Set the row to high
        digitalWrite(rowPins[i], HIGH);
    };
}
