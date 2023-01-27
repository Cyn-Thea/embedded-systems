// Cynthia Tarwireyi, Dhanvarshinie Rajan, Kanokwan Haesatith group: 24 (2023)
// Work package 1
// Exercise 4 part 2
// Submission code: 14424

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_NUMBER 2147483647

int byte(int arg);
void decToBin(int n);
bool isValidInt(char *num);

int main(int argc, char *argv[]) {

  long value = atoi(argv[1]);
  int result = isValidInt(argv[1]);

  if (value < MAX_NUMBER){ // nested if statement:: if the input value is less than the max number (2147483647) run the following ...
  
  if (argc == 2){ // check if one argument was provided by the user

  if (result){ // if the isValidInt function returns true, meaning the input value is a positive integer conver the decimal value to binary.
     decToBin(value);
  }
   else if (strcmp(argv[1], "-h") == 0) //  provide help if the user provides the parameter ‘-h’
      {
            printf("\nTo run the program: \nEnter a positive decimal number to convert it to a decimal\n\n");
      }
      else { //  if the conversion was not successful
      printf("\nError: conversion was not successful\n\n");
      return 2; }
      } else{ //
        printf("\nError: Invalid arguments. Enter '-h' for help\n\n");
        return 2;
       }
     }
        else { // if the input value is greater than 2147483647, quit the program
        printf("\nError: Value is too large. \nEnter a positive value between 0 and 2147483646\n\n");
        return 2;

      }
       }

//Because any number is stored as binary in the computer, we can use bitwise operators to calculate the size
// https://stackoverflow.com/questions/2274428/how-to-determine-how-many-bytes-an-integer-needs
int byte(int number) {
  int n = 0; 
  while (number != 0) 
  {        
    number >>= 8; // bitshift the number by 8 bits to the right which is dividing it by 2, 8 times
    n++;       // increment the number of bytes required
    //printf("%d\n", n * 8);  
  }
   return n * 8; // return the amount of bits
 
}


// Because any number is stored as binary in the computer, we can use bitwise operators to  
 // find binary representation of the number by checking every bit of the number 
 void decToBin(int n){
  // get the bits size of the integer
  int size = byte(n);
    for (int i = size-1; i >= 0; i--) { // Run a for loop from left to right in the number
        // calculate bit mask to check whether the current bit value of num is set or not (if its 1 or 0)
        int mask = (1 << i);
        // print 1 if the ith bit of num is set(=1) 
        if (n & mask)
           printf("1");
        // print 0 if ith bit of num is not set(0)
        else 
           printf("0");
    }
}   

// check if the string of the argument contains the correct digits

bool isValidInt(char *num) {
  while (*num != '\0')
  {
    if (!isdigit(*num)) { // isdigit to check if the passed character is a digit or not. 
                         // It returns 1 if it's a digit else it returns 0.          
      return false;  // return when not a number
    }
    num++; // go to the next character
  }
  return true;  // return true when input is a positive integer
}