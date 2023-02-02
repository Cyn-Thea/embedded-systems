// Cynthia Tarwireyi, Dhanvarshinie Rajan, Kanokwan Haesatith group: 24 (2023)
// Work package 2
// Exercise 4.1
// Submission code: 6162
#include <stdio.h> //include standard library for scanf, printf

enum DIRECTION //define an enumerated typed DIRECTION and its values(N,E,S,W)
{
      N,
      E,
      S,
      W
};


typedef struct //define a new type ROBOT and its structure(x,y coordinates and the direction)
{
      int xpos;
      int ypos;
      enum DIRECTION dir;
} ROBOT;



void move(ROBOT *robot) 
/*
- move() function that receive pointer to argument ROBOT. 
- this function will move the robot one step at a time to the direction it already in.
*/
{
      switch (robot->dir)//(swish statement based on the current direction of the robot)
      {
      case N:
            robot->ypos += 1;
            break;
      case E:
            robot->xpos += 1;
            break;
      case S:
            robot->ypos -= 1;
            break;
      case W:
            robot->xpos -= 1;
            break;
      }
}



void turn(ROBOT *robot)
/*
- this turn() function receive pointer to the argument ROBOT.
- when executed, the robot will turn 90 clockwise to the opposite direction of it current direction.
*/
{
      switch (robot->dir)// swish statement based on the current direction of the robot.
      {
      case N:
            robot->dir = E;
            break;
      case E:
            robot->dir = S;
            break;
      case S:
            robot->dir = W;
            break;
      case W:
            robot->dir = N;
            break;
      }
}



int main()
{
      ROBOT robot = {0, 0, N}; //initialize the robot with starting postion 0,0 in the north direction.
      char inputs[1000]; // initialize array of size 1000 that will store the input from user
      int i;
      char exit = 'x';

      while (1)// program runs in a while infinite loop until it's stopped by break; statement
      {
            printf("Enter new starting position (x, y):");
            scanf("%d, %d", &robot.xpos, &robot.ypos); // this scanf read the new position entered by user.
            if (robot.xpos > 99 || robot.xpos < 0 || robot.ypos > 99 || robot.ypos < 0) // this statement makes sure that the range of x,y is in between 0-99
            {
                  printf("Invalid inputs, x and y must be between 0 and 99\n");
                  break;
            }
            printf("Enter instructions (m for move, t for turn):");
            scanf("%s", inputs); // prompt the user for instructions for the robots movement.

            for (i = 0; inputs[i] != '\0'; i++) 
            /*
            - the for loop here wil iterate through the each character in the inputs array
            - i = 0 sets the value of i to zero, != '\0' checks that if input[i] is not null then the loop will continue i++.  
            */
            {
                  switch (inputs[i]) //switch statement based on the input[i] value whether it is m or t or neither.
                  //if m executes move() function, t executes turn() function,and prints out invalid if it's neither.
                  {
                  case 'm':
                        move(&robot);
                        break;
                  case 't':
                        turn(&robot);
                        break;
                  default:
                        printf("Invalid input\n");
                        break;
                  }
            }

            //here the program will print out the final position of the robot after executed all the inputs array and its direction.
            printf("Final position: (%d, %d, ", robot.xpos, robot.ypos);
            switch (robot.dir)
            {
            case N:
                  printf("N)\n");
                  break;
            case E:
                  printf("E)\n");
                  break;
            case S:
                  printf("S)\n");
                  break;
            case W:
                  printf("W)\n");
                  break;
            }

            // ask the user if they want to continue the program or end the program by exit it by entering x to end the loop.
            printf("Enter 'x' to exit or any other character to continue:\n");
            scanf(" %c", &exit);
            if (exit == 'x')
            {
                  break;
            }
      }

      return 0;
}
