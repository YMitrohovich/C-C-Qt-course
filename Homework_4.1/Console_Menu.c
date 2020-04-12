#include <stdio.h>
#include <stdlib.h>	// Used 'stdlib.h' to use system ('clear')

int main ()

{
	system ("clear"); 	// Clears all the previous text from the terminal screen
	int n,a,b,c;

	printf ("Welome to calculator. Please, enter two numbers to continue\n");
	scanf ("%d %d",&a,&b);	// Request to enter 2 numbers in a row. First number equals 'a', second number - 'b'

	do {	// Repeats 'switch-case' until user selects option '7'

		printf ("\nPlease select a required operation\n\n");	// Prints the text and options to the menu
		printf ("1. Addition.\n");
		printf ("2. Subtraction.\n");
		printf ("3. Multiplication.\n");
		printf ("4. Division.\n");
		printf ("5. Change numbers.\n");
		printf ("6. Help.\n");
		printf ("7. Exit\n");

		scanf ("%d", &c);	// Requests an input to select 1 of 7 options

		switch (c) {	// 'switch-case' creates options to select.
			case 1:
				system ("clear");
				c = a + b;
				printf ("Result: %d + %d = %d\n", a, b, c);
				break;
			case 2:
				system ("clear");
				c = a - b;
				printf ("Result: %d - %d = %d\n", a, b, c);
				break;
			case 3:
				system ("clear");
				c = a * b;
				printf ("Result: %d * %d = %d\n", a, b, c);
				break;
			case 4:
				system ("clear");
				c = a / b;
				printf ("Result: %d / %d = %d\n", a, b, c);
				break;
			case 5: 
				system ("clear");
				printf ("Please, enter two numbers to continue\n");
				scanf ("%d %d",&a,&b);
				break;
			case 6:
				system ("clear");
				printf ("Option '1': a + b.\nOption '2': a - b.\nOption '3': a * b.\nOption '4': a / b.\nOption '5' allows to change numbers\nOption '7' terminates the program\n");
				break;
			case 7:
				system ("clear");
				printf ("Farewell!\n");
				exit (1);	// Terminates the program
				break;
		}

	} while (c != 7);
}
