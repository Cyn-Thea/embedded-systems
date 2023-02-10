#include <stdio.h>  //standard input output header file
#include <time.h>   //time header file
#include <stdlib.h> //standard librarry header file
#define MAX 10      // defining MAX with value 10

int print_array(int *argc) // defining predefined function to calculate the value of address of array
{
     // int *mul; // defining mul pointer
      for (int i = 1; i <= MAX; i++)
      {                                                                              // for loop to print every value stored in the array
            printf("\nThe integer stored in %d place in the array is %d\n", i, *argc); // printinf the value stored in the array one by one
           // mul = argc;                                                              // copying the value of the argc pointer to mul pointer
           // *mul *= 2;      
                                                                    // multiplying mul by 2
            printf("The integer multiplied by 2 is %d\n\n", *argc++ *2);  
                               // printing the result
           // argc++;                                                                  // incrementing argc
      }
      return 0; // return 0 at the successful execution of the function call
}

int main(void) // main function starts with interger return type and takes no arguments
{
      int array[MAX];    // defining array of integer type with maximum value of MAX
      int size = 0;      // defining integer size and intializing it to 0
      srand(time(NULL)); // random number generator seed
      for (int i = 0; i < MAX; i++)
      {                               // for loop to fill the array with the maximum of MAX values
            array[i] = rand() % 99;   // the value of every entry in the array shouldnt be more than 99
            size += sizeof(array[i]); // calculating the total size of the array
      }
      printf("Value of address of the array is %p\n", &array[0]);
      printf("The first integer in the array is %d\n", array[0]);      // printing first value stored in the array
      printf("The last integer in the array is %d\n", array[MAX - 1]); // printing last value stored in the array
      printf("Size of an integer in bytes is %d\n", sizeof(array[0])); // printing the size of one integer stored in the array
      printf("Size of the array in bytes is %lu\n", size);              // printing the sum of the sizes of all integers stored in the array,using long unsigned to avoid warning incase we print more numbers

      int *point;         // defining pointer point of integer type
      point = array;      // assigning array to point
      print_array(point); // calling print_array function

      return 0; // returning 0 at the successful execution of the program
}