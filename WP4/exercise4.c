// Cynthia Tarwireyi, Dhanvarshinie Rajan, Kanokwan Haesatith group: 24 (2023)
// Work package 4
// Exercise 4
// Submission code: 44524

#include<stdio.h> //standard input output header file

int search_number(int number, int tab[], int size) //redefined function to seach number with the number to be searched, array, number of integers in the array as arguments
{ 
	for (int i = 0; i < size; i++) //for loop to search the number agaist every element in the array 
	{
		if (tab[i] == number) { //if the number is equal to the element in the array 
			printf("position of %d in the array is %d", number, i); //print the position
			return i; //return the position
		}
	}
	return -1; //returns -1 since the number doesnt exist
	
}

void sort(int number, int tab[]) //redefined function to sort the array, with number of elements and array as arguments
{
	int swap; //defining sway variable of integer data type 
	for (int i = 0; i < number - 1; i++) //outer forloop controls the number of passes that are needed to sort the array. Since the largest element "bubbles" up to the end of the array in each pass, we only need number-1 passes to sort the entire array.
	{
		for (int j = 0; j < number - i - 1; j++) //inner forloop to swap the adjacent larger number with smaller number,-i in the loop condition is because the last i elements of the array are already sorted, so we don't need to compare them again.
		{
			if (tab[j] > tab[j + 1]) //if the element on the right is greater than the element on the left, if statement executes
			{
				swap = tab[j]; // assign the larger value to swap
				tab[j] = tab[j + 1]; //assign smaller value to the preceeding position 
				tab[j + 1] = swap; //assign larger value to the succeeding position
			}
		}
	}
	printf("\n Sorted array:\n "); //printing the sorted array 
	for(int i = 0; i < number; i++) { //forloop to go through the element one by one
		printf("%d\n", tab[i]); //printing the element
		 
   }
}
int main() { //main function starts
	int n; //defining variable n of integer data type
	int test[] = { 1,2,34,5,67,3,23,12,13,10 }; //defining test[] array with the elements
	int size = sizeof(test) / sizeof(test[0]); //to find the number of elements in the array, we are dividing the size of the array with the size of one element in the array 
	printf("Enter a number to be searched in the array: "); //asking the user to enter the number to be searched in the array 
	scanf("%d", &n); //storing the number entered in variable n 
	search_number(n, test, size); //search_number function call 
	sort(size, test); // sort function call 
    return 0;

}