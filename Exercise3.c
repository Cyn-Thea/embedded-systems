#include <stdio.h>
#include <stdlib.h>
#include <time.h> // library of the function time()

#define MAX_NUMBER 2 // define the number of maximum number of guesses

int main()
{
      int random_number, guess, count = 0; 
      char c;
      srand(time(0)); // initialize the random number generator
      do{
            random_number = rand() % 100 + 1; // random number will be generated within the range of 1-100
            count = 0;
            do // run the programs continually until it reach the defined maximum number of guesses or the user guesses the correct answer
            {
                  printf("Guess a number between 1 and 100: ");
                  if (scanf("%d", &guess) != 1) // The expression make sure that the program doesn't break with  EOF
                  {
                        printf("Invalid input. Please enter a number\n");
                        while ((c = getchar()) != '\n' && c != EOF) 
                              ;
                        continue;
                  }
                  if (guess < 1 || guess > 100) // The expression make sure that the program doesn't break with input outside the range of 1-100 
                  {
                        printf("Invalid input. Please enter a number between 1 and 100\n");
                        continue;
                  }
                  count++;
                  if (guess == random_number) // handles the response when the user guesses the correct number
                  {
                        printf("You have guessed %d times and your guess is correct\n", count);
                        break;
                  }
                  else if (guess < random_number) //handles the response when the user guesses too high or too low number
                  {
                        printf("Your guess is too low\n");
                  }
                  else
                  {
                        printf("Your guess is too high\n");
                  }
            } while (count < MAX_NUMBER);
            if (guess != random_number) // handles the response when the maximum number of guesses is reached but the user is not haven't answer the correct answer.
            {
                  printf("You have reached the maximum number of guesses. The correct number was %d\n", random_number); 
            }
            printf("Do you want to play again? (y/n): "); 
            scanf(" %c", &c); //this scanf_s accept user input if they want to continue the game or exit
      } while (c == 'y'); //if the user write "y" the game will continue running
      return 0;
}
