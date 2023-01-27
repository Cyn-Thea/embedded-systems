#include <stdio.h>
#include <stdlib.h> //library about functions involving memory allocation, process control, conversions and others.

// The variable 'argc' stores the number of arguments passed to the program
// The variable 'argv' stores the actual arguments passed
int main(int argc, char *argv[])
{
      char text[100], ch, input, *place=argv[1]; //place variable store the passed value of the argument at position [1];
      int i, shift = atoi(place); // atoi(place) function converts the string argument place to an integer

      do{
      printf("\nEnter a message to encrypt: ");
      gets(text);                       // gets() function stores  space-separated strings input value into a character array
      for (i = 0; text[i] != '\0'; ++i) // if text is not null then encrypt it based on the shift position.
      {
            ch = text[i];
            if (ch >= 'A' && ch <= 'Z') //accept the uppercase input to encrypt
            {
                  ch = ch + shift; //shift the alphabet based on the passed shift number argument
                  if (ch > 'Z')
                  {
                        ch = ch - 'Z' + 'A' - 1;
                  }
                  text[i] = ch;// store the change in text array
            }
            else if (ch >= 'a' && ch <= 'z') //accept the lowercase input to encrypt
            {
                  ch = ch + shift;
                  if (ch > 'z')
                  {
                        ch = ch - 'z' + 'a' - 1;
                  }
                  text[i] = ch; //store the change in text array
            }    
      }
      printf("%s", text); // prints the encrypted texts back to user.
      } while ((input = getchar()) != EOF); // Exit the loop if we receive EOF ("end of file") which is ctrl+z for windows
      return 0;
}
