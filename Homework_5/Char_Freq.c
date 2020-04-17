#include <stdio.h>
#include <stdlib.h>
#include <string.h>	// Used 'string.h.' to work with strings
#include <stdbool.h>	// Used 'stdbool.h' to work with boolean expressions

int main ()
{
	char file_string[10000];	// Initialization of the char array with capacity of 10.000 characters. Used to store information from text files
	char tab_char[256];		// Initialization of the char array of 256 characters. Used to deny repeatation of characters 
	char file_name[16];	// Initialization of the char array with capacity of 16 characters. Used to store information about the filename
	FILE *fp;

	system ("clear");
	printf("Please enter the name of the file you would like to read\n\n\a> ");
	scanf("%s", file_name);
	
	if ((fp = fopen (file_name, "r")) == NULL) {	// If the file with name 'file_name' does not exists, program prints the text bellow
		fprintf (stderr, "Unable to open the file '%s'\n", file_name);
	}

	memset (file_string, 0, 10000);	// Set the value of all the array elements to 0

	int i = 0;
	while (!feof(fp)) {	// Until the file ends, the array will record all the information from the file
		fscanf (fp, "%c", &file_string[i]);
		i++;
	}

	fclose (fp);	// Closes the file

	int c;
	for (c = 0; c < 256; c++) {	// Set the table of characters for counting frequency	
		tab_char[c] = (char) c;
	}

	char ch;
	int count, j;
	for (c = 0; c < strlen (file_string); c++) {	// Reading all the characters from the file
		count = 0;		// Variable for frequency storage

		for (j = 0; j < strlen (file_string); j++) {	// Loop for counting appearing frequency of a character
			if (file_string[c] == file_string[j]) {	// If reading of the first 'for' loop equals to second 'for' loop, it increments 'count' by 1
				count++;
			}
		}
		
		ch = file_string[c];
		if (tab_char[ch] == true) {	// 'if' conditional checks if character appeared in the loop more than once
			continue;	// Proceeds further if character passes the condition
		}

		tab_char[ch] = true;	// States that expression above is true, so program prints on the screen character and the number of times it was found in the file
		printf ("Character '%c' : %d times in the file\n", file_string[c], count);
	}
	printf ("\n%d characters were successfully found in the file '%s'!\n\a", i, file_name);
}
