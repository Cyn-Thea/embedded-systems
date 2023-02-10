// Cynthia Tarwireyi, Dhanvarshinie Rajan, Kanokwan Haesatith group: 24 (2023)
// Work package 3
// Exercise 6
// Submission code: B92

#include <stdio.h> //standard input output header file
#include <string.h> //string header file

#define MAX 21

void copyString(char *dest, char *src) { //predefined copyString function with two character pointers as arguments 
  int i = 0; //defining integer variable i
  while (src[i] != '\0') { //running while loop until the it encounters null character in the array 
    dest[i++] = src[i]; //copying character by character to dest from src, incrementing dest[i] because c evaluate from left to right
  }
  dest[i] = '\0'; //adding null character at the end of dest array to 
}

int main() { //main function starts
   char inputString[MAX]; //defining inputString with 21 spaces to include null character
  char copiedString[MAX]; //defining outputString with 21 spaces to include null character
  char copiedStringOne[MAX];
    scanf("%20s", inputString); //reading 20 characters from the input and storing it in inputString

    strcpy(copiedString, inputString); //using the inbuilt strcpy function to copy to destination variable to source variable
    printf("Copied string using strcpy: %s\n", copiedString); //print the copied string

    copyString(copiedStringOne, inputString); //calling copyString function 
    printf("Copied string using custom function: %s\n", copiedStringOne); //printing the result for the function call 
        return 0; //returning 0 at the successful execution of the program 

}

