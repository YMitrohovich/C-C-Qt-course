#include <stdio.h>
#include <stdlib.h>
#include <string.h>	// Used 'string.h.' to work with strings

int main ()
{
	system ("clear");

	char file_string[100000];	// Initialization of the char array with capacity of 100.000 characters. Used to store information from text files
	char file_name[50];	// Initialization of the char array with capacity of 50 characters. Used to store information about the filename
	FILE *fp;
Input:			// Mark for 'goto' function. Mark is ignored by the program until 'goto' adresses to it.
	printf("Please enter the name of the file you would like to read\n\a> ");
	scanf("%s", file_name);
	
	if ((fp = fopen (file_name, "r")) == NULL) {	// If the file with name 'file_name' does not exists, program prints the text bellow and proceeds to mark 'Input'
		fprintf (stderr, "Unable to open the file '%s'\n", file_name);
		goto Input;	// 'goto' sends user to mark 'Input' if it meets the conditions. It is the last time I used it, I promise :) 
	}

	memset (file_string, 0, 100000);	// Set the value of all the array elements to 0

	int i = 0;
	while (!feof(fp)) {	// Until the file ends, the array will record all the information from the file
		fscanf (fp, "%c", &file_string[i]);
		i++;
	}

	for (int n = 0; n < i; n++) {	// 'for' loop prints all the characters stored in the array
		printf ("%c", (int) file_string [n]);
	}

	fseek (fp, 0, 2);	// 'fseek' function 'scans' the file 'fp' from the begining (0) to the very end (2)
	int size = ftell (fp);	// 'ftell' function returns the number of bytes according to the records of 'fseek'

	fclose (fp);	// Close the file

	printf ("\nThe size of '%s' is : %d bytes\n\a", file_name, size);	// Prints the name and size of the file	
}
