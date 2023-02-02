// Cynthia Tarwireyi, Dhanvarshinie Rajan, Kanokwan Haesatith group: 24 (2023)
// Work package 2
// Exercise 4.1
// Submission code: 6162
#include <stdio.h>
#include <stdlib.h>

/*
- when the program is executed, argc argument counts the number of argument passed in the command line
- while the argv is an array of pointers to the char type 
*/
int main(int argc, char *argv[])
{
      if (argc != 2) // checks if the program receive exactly only 1 argument or else end it.
      {
            printf("One argument expected.");
            return 1;
      }

      //this function checks if the every inputs in the passed argument is a hexadecimal number. if not exit the program.
      int i;
      for (i = 0; argv[1][i] != '\0'; i++)
      {
            char c = argv[1][i];
            if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')))
            {
                  printf("Invalid inputs.\n");
                  return 1;
            }
      }

      /*
      - the strtol() function is used to return integer value of a string, here it is converting the passed argv[1] string to an integer.
      - the second argument NULL means no characters need to be left after the conversion.
      - the third argument 16 means that the string is hexadecimal number.
      - then it stores the return integer value in an unsigned char type variable "byte"
      */
      unsigned char byte = (unsigned char)strtol(argv[1], NULL, 16);

      /*
      the following lines use the value of bits in variable "byte", then perform the binary AND and right shift operations to get the individual bits value of
      of the result value to each unsigned char variables (engine_on, gear_pos, key_pos,break1, brake2)
      - 0x80, 0x70, 0x02, and 0x01 are hexadecimal (base 16), 0x80 = 0b10000000,0x70 = 0b01110000,0x02 = 0b00000010,0x01 = 0b00000001
      */
      unsigned char engine_on = (byte & 0x80) >> 7; // (byte & 0x80) to extract bit no7(Most significant Bit) as 0x80 is 128, shift operator will shifts the bits of the result value by 7 places. the same goes for the following lines.
      unsigned char gear_pos = (byte & 0x70) >> 4; // extract 7 bits, in the range 0-4
      unsigned char key_pos = (byte & 0x0C) >> 2; //extract  2 bits, in range of 0-2
      unsigned char brake1 = (byte & 0x01); //extract 1 bits ranging number 0-1
      unsigned char brake2 = (byte & 0x01); // extract 1 bits as well, 0x01 is lowest  significant bit 

      //then the program later prints out the stored values back to the user.

      printf("Name | Value\n-----------------------------\n");
      printf("engine_on: %d\n", engine_on);
      printf("gear_pos: %d\n", gear_pos);
      printf("key_pos: %d\n", key_pos);
      printf("brake1: %d\n", brake1);
      printf("brake2: %d\n", brake2);

      return 0;
}