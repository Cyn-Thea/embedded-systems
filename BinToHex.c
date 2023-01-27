// Cynthia Tarwireyi, Dhanvarshinie Rajan, Kanokwan Haesatith group: 24 (2023)
// Work package 1
// Exercise 4 part 1
// Submission code: 14424

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isBinary(int num);
void  convertToHex (long value);

int main(int argc,char *argv[]){

    long value=atoi(argv[1]);
    int result = isBinary(value);

  if (argc == 2){ // // check if correct argument was provided by the user
      
      if (strcmp(argv[1],"-h")==0){ // provide help if the user provides the parameter ‘-h’
    printf("\nTo run the program:\nEnter a binary number (0 and 1) to convert it to hexadecimal.\n\n");
   }
   else if (value == 0){  // if the user input is 0, exit the program
       printf("\nA valid binary number was not found. Program exiting.\n\n");
       return 2;
   }
   else if (result){ // if the conditions are correct, convert the binary to hexadecimal
         convertToHex(value);
    } else {
        printf("\nNot a valid binary number.\n\n");
        return 2;
    }
    }else { //  if the conversion was not successful, exit the program
         printf("\nError: Conversion was not successful!\n\n");
         return 2;
    }
  
}

void convertToHex (long value){
long hexadecimal = 0, i = 1, remainder;
     while (value != 0) // repeat loop until binaryval becomes zero.
    {
        remainder = value % 10; // get the remainder of the input value
        hexadecimal = hexadecimal + remainder * i; // multiply the remainder with i and increment the hexadecimal variable
        i = i * 2; // incremetn the value of i by 2
        value = value / 10; // replace the current binary value with the quotient obtained
    }
    printf("\nThe hexadecimal value is: 0%lX", hexadecimal);

}


// check if the string of the argument contains the correct digits, is binary

bool isBinary(int num) {

    while (num > 0) { // loop runs only when num is not 0

        if (num % 10 > 1){ // after dividing the num and if the remainder is not  0 or 1 
            return false; // it is not a binary number
        }
        else {  // but if the remainder of num is 0 or 1  (1010 % 10 = 0)
           num = num / 10;  // we divide the number by 10, so as to check every value in num (1010/10 = 100)
        }                    // use the results from this to run the loop again with (101)

    }
    return true;

}