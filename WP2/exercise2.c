// Cynthia Tarwireyi, Dhanvarshinie Rajan, Kanokwan Haesatith group: 24 (2023)
// Work package 2
// Exercise 2
// Submission code: 6162

#include <stdio.h>  //standard input output header file
#include <stdlib.h> //standard library header file for malloc,free and srand function used in the program 
#include <time.h>   //time header file for the use of time function in the program 

//#### Constants ##### 
#define MAX 5   

// ##### typedefs          #### 
typedef struct q {  //typedef is used to create an alias REGTYPE for defining similar structure with one integer and two pointers whenever needed
    int number;     //defining integer number
    struct q* next; //defining pointer next to another structure of type q
    struct q* prev; //defining pointer previous to another structure of type q
} REGTYPE;          //alias for structure q

// ##### Function declarations   ##### 

REGTYPE* random_list(void); //function declaration random_list of structure q which accepts no arguments
REGTYPE* add_first(REGTYPE *temp, int data); //function declaration add_first of structure q which accepts two values, a pointer to a structure REGTYPE and an integer data


//###### Main program ####### 
int main(int argc, char* argv[]) // main funtion takes two arguments, integer type argc and a char type pointer to argv
{
    int nr = 0; //initializing nr = 0

    REGTYPE* act_post, * head = NULL; //declaring two pointers act_post and head of type REGTYPE, head is initialiazed to null

    srand(time(0));  //   srand is a function used to generate random numbers, here time(0) is passed as an argument thus ensuring random numbers everytime the program is run
    head = random_list(); //head is assigned the result of the function call random_list()
    act_post = head; //assigning act_post the value of head
    while (act_post != NULL) { //while loop run till act_post is not equal to null
        printf("\n Post nr %d : %d", nr++, act_post->number);//prints nr and number field of act_post and then increments nr 
        act_post = act_post->next;//  assigns the next element in the list to act_post
    }
    printf("\n");
    printf("Printing linked list after adding one value at the entry");
    
    
    head= add_first(head,nr); //assinging the result of function call add_first()
    act_post = head; //assigning the value of head to act_post
    nr = 0; //assigns value 0 to nr
    while (act_post != NULL) { //while loop run till act_post is not equal to null
        printf("\n Post nr %d : %d", nr++, act_post->number);//prints nr and number field of act_post and then increments nr 
        act_post = act_post->next;//  assigns the next element in the list to act_post
    }

    // --- Free the allocated memory  --- 

    while ((act_post = head) != NULL) { //while loop runs as long as act_post is not equal to numm 
        head = act_post->next; //signs the value of head to next value of act_post
        free(act_post); //freeing the memory of act_post using the in-built free function 
    }

    return 0; //return of 0 indicates successful completion of program 
}

// ====     End of main   ====================================== 
//function definition
REGTYPE* random_list(void) { //random_list function with no argument and the return type is a ppointer to the REGTYPE data structure
    int nr, i = 0; //defining integer nr and i, initializing i to 0
    REGTYPE *top, *old, *item; //declaring REGTYPE pointers top, old,item
    nr = rand() % 100; //nr is assigned a random number with a max value of 100 
    item = (REGTYPE*)malloc(sizeof(REGTYPE)); //Memory is allocated for the first REGTYPE structure using malloc 
    item->number = nr; //the random number stored in nr is assigned to the number field of first REGTYPE structure
    item->next = NULL; //next and prev pointers of the structure are set to NULL.
    item->prev = NULL;
    top = item; //The first REGTYPE structure is stored as both the top and old elements.
    old = item;
    for (i = 1; i < MAX; i++) { //function then enters a loop, repeating MAX times, and generates MAX-1 random numbers
        nr = rand() % 100; //new random number is generated and stores in nr
        item = (REGTYPE*)malloc(sizeof(REGTYPE)); //Memory is allocated for a new REGTYPE structure using malloc.
        item->number = nr; // The number field of the new structure is set to the newly generated random number.
        item->next = NULL; //The next pointer of the new structure is set to NULL
        item->prev = old; // The prev pointer is set to the current old structure.
        old->next = item; //The next pointer of the old structure is set to the newly created structure


        old = item; //the old structure is updated to the new structure.
    }
    return top; // top element of the linked list is returned as the result of the function.
}

REGTYPE* add_first(REGTYPE* temp, int data) { //function takes in two arguments: a pointer to the current first element of the list temp, and the value data that should be stored in the new first element.
    REGTYPE* new_first; //declares a new REGTYPE structure to the beginning of a linked list
    new_first = (REGTYPE*)malloc(sizeof(REGTYPE)); //allocates memory for the new REGTYPE structure using malloc.
    new_first->number = data; //Stores the value data in the number field of the newly created structure.
    new_first->prev = NULL; //Sets the prev pointer of the new structure to NULL to indicate that it is the first element in the list.
    new_first->next = temp; //Sets the next pointer of the new structure to the current first element of the list temp.
    temp->prev = new_first; //Sets the prev pointer of the current first element of the list temp to the new first element.
    return new_first; //Returns a pointer to the new first element of the list
}