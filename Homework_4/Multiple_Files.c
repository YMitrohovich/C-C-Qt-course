#include <stdio.h>
#include <stdlib.h>	// Used 'stdlib.h' library use 'srand' function
#include <time.h>	// Used 'time.h' library to have access to time on the PC

int newFile (int);	// Creating a prototype of the function which will be responsible for creating files

int newFile (int n)
{
	srand (time (NULL));	// This function sets current time on PC as a base which would help us to create truly random numbers each time it's required

	char name [20];		// Creating an array to be able to create multiple files with different names
	FILE *fp;		// Creating file with the pointer, named 'fp'

	for (int f = 1; f <= n; f++) {		// Starting the first 'for' loop which will be creating multiple files according to value 'n'
		sprintf (name, "file_%d", f);	// 'sprintf' used to make an output to the 'name' array, which could help us create different names for files
		fp = fopen (name, "w+");	// Opens 'fp' file with the name specified in 'name' array with mode 'w+' (read and write)
		fprintf (fp, "1000 randomly generated numbers\n\n"); // 'fprintf' prints the text inside the file 

		for (int i = 1; i <= 1000; i++) {		//  Starting the second'for' loop which creates 1000 randomly generated numbers
			fprintf (fp, "%d: %d\n", i, rand()%100);	// Prints inside the text file first the order number (1 of 1000 according to the value 'i') and then random number from 0 to 100
		}	// Ending the second 'for' loop

		fclose (fp);	// Closing the fp file
		printf	("File %d was created\n", f);		// Prints the text with the number of text file that was created
	}		// Ending the first 'for' loop

	return 0;
}

int main ()
{
	int n;		// Creating a varible which will store the number of files needed to be created
	printf ("\nPlease, enter the number of files you would like to create\n");
	scanf ("%d", &n);	// Entering the number of files we would like to create
	
	newFile (n);	// Calling the 'newFile' function which will create us multiple files according to value 'n'

	return 0;
}
