#include <stdio.h> //header file
#include<stdlib.h> //stdlib file is included because rand() function is used to generate the table of random numbers
#include <time.h>

#define MAX 100 // Defines the maximum number of the values in the table 
#define MAXNUMBER 20 // Defines the maximum value of random numbers 

int table[MAX], n ; //defining "table" array of integers with MAX(100) of spaces
int frequency[MAXNUMBER];  //defining an "frequency" array with MAXNUMBER(20) spaces

// ------ Function declarations   ----------  

// This function generates a set of random numbers 
// and fills the table with these numbers 

void create_random(int *tab );

// This function takes the *tab of random numbers
// and creates a table with the frequency counts for these numbers 
void count_frequency(int *tab, int *freq );

// This function takes the frequency count table
// and draws a histogram of the values in that frequency table
void draw_histogram(int *freq );

// ------ Function definitions ----------

// Fills the table with randomly generated numbers 

void create_random(int *tab){
// Sets the starting seed based on time for each iteration
 srand (time(NULL) );
    for(int i= 0; i< MAX; i++){ // Loop to generate 100 random numbers
       int random = rand ()% MAXNUMBER; // random number should be between 0 - 19
       tab[i] = random; // Assign the generated number to tab
       printf("%d\n", random);
    }    
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

// ------ Main   -------------------------- 

// The main entry point for the program 

int main() {  
    
    int* tab = table; //defining the pointer tab to table
    int* freq = frequency; //defining the pointer freq to frequency
    create_random(table);//function call to generate the table of random number
    count_frequency(tab, freq); //function call to count the frequency 
    draw_histogram(freq);
    return 0;
}