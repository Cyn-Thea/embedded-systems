#include <stdio.h>

int main(){
int number;

while(number > 0 || number < 6){  // loop runs only if a user inputs a number between 1 and 5

printf("\nWant to see fun facts about numebr 1 to 5? Enter a number between 1 and 5: ");    
scanf("%d",&number);   // prompt user input

 if (number == 1) // if number == 1 print this statement, and repeat loop
        {
            printf("\nThe old Greeks didn’t believe One to be a number by any means. A number, said Euclid, is a “total of units”, so numbers started at Two.\n");
        } 
        
         else if (number == 2) // if number == 2 print this statement, and repeat loop
        {
            printf("\nTwo is viewed as fortunate in China. The Chinese public says “beneficial things come two by two.”\n");
        }
        else if (number == 3) // if number == 3 , print this statement, and repeat loop
        {
            printf("\nThe ancient Greek philosopher, Pythagoras, postulated the number 3 as the perfect number, the number of harmony, wisdom, and understanding. It was also the number of times – past, present, future; birth, life, death; beginning, middle, end – it was the number of the divine.\n");
        }
        else if (number == 4)  // if number == 4 , print this statement, and repeat loop
        {
            printf("\nThe number four is the smallest composite number.\n");
        }
        else if (number == 5) // if number == 5 , print this statementand, and repeat loop
        {
            printf("\nThe prefix penta means five. For example, a pentagon is a five-sided shape, and a pentagram is a five-sided star!.\n");
        }
         else  // but if the number is not between 1 and 5, exit the program
  {
    printf("\nYou entered wrong number or character. Game over\n");
    return 1;
  }
}

}