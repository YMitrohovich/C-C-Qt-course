#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int i,c;	// Variable 'i' will be used to transform numbers into characters, 'c' will be used to accept value for switch-case

	do {	// Start of 'do...while' loop, which will help us to run switch case multiple times if necessary

		printf ("Please, press 1,2 or 3\n");	// First prints text
		scanf ("%d", &c);	// Then asks user to enter a number

		switch (c) {	// Start of the switch-case

			case 1:		// First case will be executed if you type '1'
				i = (char) 111; // int 'i' becomes char with value 111 (letter 'o' according to ASCII)
				printf ("The first letter of the number is: %c\n", i); 		// Prints the letter 'o' with the text
				break; 	// End of a loop
			case 2:		// Second case will be executed if you type '2'
				i = (char) 116;	// 'i' becomes char with value 116 (letter 't' according to ASCII)
				printf ("The first letter of the number is: %c\n", i);		// Prints the letter 't' with the text
				break;
			case 3:		// Third case will be executed if you type '3'
				i = (char) 116;	// The same as case '2'
				printf ("The first letters of the number are: %c\n", i);	// The same as in case '2'
				break;
			default :	// Default case will be executed if value 'c' is not equal to '1', '2' or '3'
				printf ("Invalid number, please try again\n\n");
				break;

		}	// End of the switch-case
	} while (c < 1 || c > 3);	// 'do...while' loop could be executed multiple times if value of 'c' matches required condition
}
