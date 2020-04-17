#include <stdio.h>
#include <stdlib.h>	// Used 'stdlib.h' for rand/srand function
#include <time.h>	// Used 'time.h' to get current time from PC

int arr_check (int arr[], int);		// Creating prototype of function with argument, that there will be some 'arr' array of type 'int' with size of 'int' type as well
int main ();		// Created prototype of 'main' only because I don't like warnings in terminal. Program works perfectly fine without prototyping

int arr_check (int arr[], int i)	// Function will check the content of elements of the created array in 'main'
{
	int n;		// Variable 'n' represents the order number of the array element
	printf ("\nPlease, enter the order number of the array element you would like to check\n");
	scanf ("%d", &n);	// Request of an imput

	printf ("\narr[%d] = %c (#%d in ASCII)\n", n, arr[n], arr[n]);	// Prints element order number then character, stored in the array element with the description in ASCII

	printf ("\nDo you want to check another element?\n\n");
	printf ("1. Yes\n");
	printf ("2. No\n");

	int c;		// Variable for choice selection in 'switch-case'
	scanf ("%d", &c);

	switch (c) {
		case 1:
			arr_check (arr, i);	// Calls the 'arr_check' function once again with the same value as it had before
			break;
		case 2:
			break;		// Proceeds to the next 'switch-case'
	}

	printf ("\nDo you want to create a new array?\n\n");
	printf ("1. Yes\n");
	printf ("2. No (exit the program)\n");

	scanf ("%d", &c);

	switch (c) {
		case 1:
			main ();	// Calls the 'main' function, so the program will request new input from the start
			break;
		case 2:
			system ("clear");	// Cleans all the text above from the terminal screen
			printf ("Farewell!\n");
			exit (1);	// Terminates the program
			break;
	}		
} 

int main ()	// In 'main' will be executed all requiered calculations
{
	system ("clear");	
	int i, n;	// Variable 'i' represents the order number of an array element, variable 'n' - the total size of an array 

	printf ("Please, enter the size of your array of characters\n");
	scanf ("%d", &n);	// Request from user the input of total size of an array
	int arr[n];	// Initialization of 'arr' array of 'int' type, which now has size of 'n' elements

	srand (time(NULL));
	system ("clear");

	for (i = 0; i < n; i++) {	// 'for' loop used to record some character in each element of the 'arr' array
		arr[i] = (char) 33 + rand() % (127 - 33 + 1); 		// Each array element will get some random character of value from 33 to 126 according to ASCII.*
		printf("arr[%d] = %c (#%d in ASCII)\n", i, arr[i], arr[i]);	// *It was made that way in order to record only 'normal' characters, so the terminal could display them properly
	}
	
	printf ("\n%d characters were succesfully recorded in the array!\n\n", n);

	printf ("Would you like to check the content of recorded elements?\n\n");
	printf ("1. Yes\n");
	printf ("2. No\n");

	int c;
	scanf ("%d", &c);

	switch (c) {
		case 1:
			arr_check (arr, i);	// Calls the function 'arr_check' with arguments of 'arr' and 'i'
			break;
		case 2:
			break;		// Proceeds to next 'switch-case'
	}

	printf ("\nDo you want to create a new array?\n\n");
	printf ("1. Yes\n");
	printf ("2. No (exit the program)\n");

	scanf ("%d", &c);

	switch (c) {
		case 1:
			main ();	// Calls 'main' function once again
			break;
		case 2:
			system ("clear");			
			printf ("Farewell!\n");
			exit (1);
			break;
	}	
}

