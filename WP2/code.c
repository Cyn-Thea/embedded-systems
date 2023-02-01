#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {

  // unsigned char is a character datatype ranges from 0 to 255.
  unsigned char result = 0;

  // assigning the 5 arguments to the correct variable names and 
  // converting the arguments to int using the atoi function
  int engine_on = atoi(argv[1]);
  int gear_pos = atoi(argv[2]);
  int key_pos = atoi(argv[3]);
  int brake1 = atoi(argv[4]);
  int brake2 = atoi(argv[5]);



  if (argc != 6) { // if the arguments by user are not == 5, show error message
    printf("Error: Invalid number of arguments\n");
    return 1;
  }

// if the arguments passed by the user are out of range, throw error message
    else if (engine_on < 0 || engine_on > 1 || gear_pos < 0 || gear_pos > 4 || key_pos < 0 || key_pos > 2 || brake1 < 0 || brake1 > 1 || brake2 < 0 || brake2 > 1) {
    printf("Error: Invalid argument values\n");
    return 1;
  }
 
else 
  result = result + engine_on * pow(2, 7); // engine_on is the MSB, so we shift it to end by 7
  result = result + gear_pos * pow(2, 4); // shift gear_pos by 4
  result = result + key_pos * pow(2, 2);  // shift gear_pos by 2
  result = result + brake1 * pow(2, 1);  // shift gear_pos by 1
  result = result + brake2 * pow(2, 0);  // brake2 is the LSB, and doesnt need to be shifted

  printf("%X\n", result);
  
  return 0;
}

// gcc code.c -o code && ./code 1 2 2 1 1
