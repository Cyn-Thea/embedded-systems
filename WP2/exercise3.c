// Cynthia Tarwireyi, Dhanvarshinie Rajan, Kanokwan Haesatith group: 24 (2023)
// Work package 2
// Exercise 3
// Submission code: 6162

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

#define FILE_NAME "database.bin" // name of the binary file
 
// -----typedefs ------- 
typedef struct { 
        char firstname[20]; 
        char famname[20]; 
        char pers_number[13]; // yyyymmddnnnc 
} PERSON; 
 
 // Function declaration

void write_new_file(PERSON *inrecord);  // Creates a file and writes the first record
void printfile(void);  // Prints out all persons in the file    
void search_by_firstname(char *name); // Prints out the person if in list
void search_by_lastname(char *name);  // Prints out the person if in list
void append_file(PERSON *inrecord);  // appends a new person to the file 
 

// fuction definition 

void write_new_file(PERSON *inrecord) {

    FILE* filePointer; // Assings the filepointer
    PERSON ppost;  // Person struct to store the data being written

    inrecord = &ppost;
    
// use strncpy to  copy up to n characters from the string in the 
// dummy data and store it in the database as a new person
// if the length of strut variable is less than the specified size, 
//in this case (20 for first name and family name and 13 for ssn) 
// the remainder of inrecord will be padded with null bytes.
    strncpy(inrecord->firstname, "Nicklas", 20); 
    strncpy(inrecord->famname, "Bergstrom", 20);
    strncpy(inrecord->pers_number, "8912085543", 13);
    
    filePointer = fopen(FILE_NAME, "wb+");// use the function fopen to open database.bin file in write mode.  
                            // If the file doesnt exist on the system, then it is created and then opened. 
                        // but, If a file is already exists on the system, it is directly opened and overriden.
    
    if ( filePointer == NULL){ // if for some reason the file cannot be opened
    printf("Error: file cannot be opened\n");
    exit(1);
  }
    // Writes the dummyrecord to the file or replaces old file if file already exists
    fwrite(inrecord, sizeof(PERSON), 1, filePointer); // fwrite will write data of size PERSON, one time, to the file 
                                                      // and store it in the inrecord memeory address
    fclose(filePointer); //close the file to terminate the contents and links to the file to prevent accidental damage to the file
    
}

void printfile() {
    
    FILE* filePtr;  // Assigns the file pointer
    PERSON ppost;  // Person struct to store data being read
    int size;  // the size of the file
    
    filePtr= fopen(FILE_NAME, "rb"); // open database.bin file in read mode
    
    if ( filePtr == NULL){ // if file doesnt exist, print error message and exist the program
    printf("Error: file does not exist\n");
    exit(1);
    }

 //if the file exists
    while (fread(&ppost, sizeof(ppost), 1, filePtr)!=0)  { // loop through the database to read the people one by one while the database is not empty
    // read the file  once, that is of size ppost and store them in the block of memory ppost
    printf("%s %s: %s\n",ppost.firstname, ppost.famname, ppost.pers_number); // prints all the contents of the file
    }  
    fclose(filePtr);//close the file to terminate the contents and links to the file to prevent accidental damage to the file
}
    
     //adding more records at the end of a binary file
void append_file(PERSON *inrecord) {
   
    FILE* filePtr;  // Assings file pointer
    PERSON ppost;   // Person struct to store data being added
    char firstName[20];
    char surname[20];
    char pers_number[13];  //personal number string
    inrecord = &ppost;                            
    
    filePtr = fopen(FILE_NAME, "ab");  // Opens database.bin file in append mode

    if ( filePtr == NULL){ // if the file does not exist, print error message and exist the program
    printf("Error: file does not exist\n");
    exit(1);
  }
   // prompt user input. data will be added at the end of the file as a new person
    printf("Enter first name: \n");
    scanf("%s", firstName); 
    strcpy(inrecord->firstname, firstName); //copies the firstname written by user and stores it in the file under firstname
    printf("Enter family name: \n");
    scanf("%s", surname);
    strcpy(inrecord->famname, surname); //copies the lastname  written by user and stores it in the file under lastname
    printf("Enter personal number: \n");
    scanf("%s", pers_number);
    strcpy(inrecord->pers_number, pers_number);//copies the pers_number written by user and stores it in the file under pers_number

    fwrite(inrecord, sizeof(PERSON), 1, filePtr);// Adds the new person to the file by writing data that is
                                  //of size PERSON, once, to the file and store the data in the inrecord memeory address
    
    printf("Name: %s %s \nPerson Number: %s \nHas been successfully saved to the database\n", inrecord->firstname, inrecord->famname, inrecord->pers_number ); 
   
    fclose(filePtr);//close the file to terminate the contents and links to the file to prevent accidental damage to the file
}

void search_by_firstname(char* name) {

    FILE* filePtr; // Assings file pointer
    PERSON ppost; // Person struct to store data being read
    bool found;

    filePtr = fopen(FILE_NAME, "rb");  // Opens database.bin file in read mode

   if (filePtr == NULL){ // if the file dos not exist, print error message and exist the program
    printf("Error: file does not exist\n");
    exit(1);
  }
    while (fread(&ppost, sizeof(ppost), 1, filePtr)!=0) { // Loops through all the entries in the file
        
    if (strcasecmp(name, ppost.firstname) == 0) { //compares the 2 strings and If the firstname or matches the search it will print that person

        printf("First name: %s \nLast name: %s \nPersonal Number: %s\n",ppost.firstname, ppost.famname, ppost.pers_number); 
        found = true; // change boolean state to found
        } 
    }

    if(found == false){ // if the first name is not found , print this error message
        printf("This person does not exist.\n");
    }
    
    fclose(filePtr); // closes the file
    
   }

void search_by_lastname(char* name) {

    FILE* filePtr; // Assings file pointer
    PERSON ppost; // Person struct to store data being read
    bool found;

    filePtr = fopen(FILE_NAME, "rb");  //opens database.bin file in read mode
   if ( filePtr == NULL){ // if the file dos not exist, print error message and exist the program
    printf("Error: file does not exist\n");
    exit(1);
  }
    while (fread(&ppost, sizeof(ppost), 1, filePtr)) { // Loops through all the entries in the file
        
    if (strcasecmp(name, ppost.famname) == 0) { //compares the 2 strings and If the family name or matches the search it will print that person

        printf("First name: %s \nLast name: %s \nPersonal Number: %s\n",ppost.firstname, ppost.famname, ppost.pers_number); 
        found = true; // change boolean state to found
        } 
    }

    if(found == false){ // if the family name does not exist, print this error message
        printf("This person does not exist.\n");
    }
    
    fclose(filePtr); // closes the file
                                                                              
   }


int main(void){ 
    
    
    PERSON ppost;         // Temp person for putting in to the file
    bool exit = false;    // Bool to determine if loop continues or not
    int choice;           // int to determine what the user wants the program to do

    while(!exit) { // Indefinite loop until user exits it
        
        // Menu options
        printf("\nPlease Select one of the following options!\n"); 
        printf("1 Create a new and delete the old file.\n");
        printf("2 Add a new person to the file.\n");
        printf("3 Search for a person in the file. \n");
        printf("4 Print out all in the file.\n");
        printf("5 Exit the program.\n");
    
        scanf("%d", &choice); // Takes user input

        if(choice == 1) { // Creates a new file with dummy data

        
            write_new_file(&ppost); // Creates a new file
        }
        
         else if(choice == 2) { // Appends a new person to the file
            append_file(&ppost); // Forwards the person to the append function
          }

        else if(choice == 3) { // Searches for a person in the file
             printf("Do you want to search by 1.first name or 2.family name?: \n");
             int search;
             scanf("%d", &search);

          if (search == 1){
               char name[20];
               printf("Type the name of the person you want to find\n");
               scanf("%s", name); // Userinput for the name they want to search
               search_by_firstname(name);
            } else if (search == 2){
                 printf("Please enter a family name to search: \n");
                 char lastName[20];
                 scanf("%s", lastName);
                 search_by_lastname(lastName);
             } else {
                 printf("Error: Inalid option. Choose between 1 and 2!\n");
             }

        }

       else if(choice == 4) { // Prints all persons in the file
            printfile();
            }

       else { // Exits the program
            printf("Program terminated\n");
            exit = true; // Sets the loop to false and ends the program
        }
    }

    return(0);     
}  

// gcc exercise3.c -o exercise3 && ./exercise3