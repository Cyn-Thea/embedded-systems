#include <stdio.h> //header file
#include<stdlib.h> //stdlib file is included because rand() function is used to generate the table of random numbers
#define MAX 100 // Defines the maximum number of the values in the table 
#define MAXNUMBER 20 // Defines the maximum value of random numbers 
int table[MAX]; //defining "table" array of integers with MAX(100) of spaces
int frequency[MAXNUMBER]; //defining an "frequency" array with MAXNUMBER(20) spaces
// ------ Function declarations   ----------  

// This function generates a set of random numbers 
// and fills the table with these numbers 
void create_random()
{

    int i;
    for (i = 0; i < MAX; i++) { //for loop to create the table of random numbers
        table[i] = rand() % MAXNUMBER; //using the rand() in-built function to auto-generate the numbers
    }
    printf("Array of random integers: "); //printing the array of numbers created 
    for (i = 0; i < MAX; i++) {
        printf("%d ", table[i]);
    }
    printf("\n"); //printing new line 
}

// This function takes the table of random numbers 
// and creates a table with the frequency counts for these numbers 
void count_frequency(int *tab, int *freq) {
    int i;
    for (i = 0; i <= MAXNUMBER; i++) { 
        *(freq + i) = 0;
    }
    for (i = 0; i < MAX; i++) {
        *(freq + *(tab + i)) += 1;
    }

}

// This function takes the frequency count table 
// and draws a histogram of the values in that frequency table 
void draw_histogram(int* freq) {
    int i;
    for (i = 0; i <= MAXNUMBER; i++) {
        if (*(freq + i) > 0) {
            printf("%d  ", i);
            int j;
            for (j = 0; j < *(freq + i); j++) {
                printf("x");
            }
            printf("\n");
        }
    }
}


int main() {

    
// ------ Main   -------------------------- 

// The main entry point for the program 
    

    int* tab = table; //defining the pointer tab to table
    int* freq = frequency; //defining the pointer freq to frequency
    create_random(); //function call to generate the table of random number
    count_frequency(tab, freq); //function call to count the frequency 
    draw_histogram(freq);
    return 0;
}