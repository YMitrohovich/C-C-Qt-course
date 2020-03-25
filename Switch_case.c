#include <stdio.h>

void main ()	// No particular reason for void, just don't want to type return

{	
    printf ("Please, press 1,2 or 3\n");	// First prints text
    char c = getchar();	// Then asks you to type number 1,2 or 3
    int i;	// Variable will be used to transfmorm numbers into characters
    
        switch (c) {	// Start of the switch-case
            case '1':	// First case will be executed if you type '1'
                i = (char) 111; // int 'i' becomes char with value 111 (letter 'o' according to ASCII)
                printf ("The first letter of the number is: %c\n", i); // Prints the letter 'o' with the text
                break; // End of a loop
            case '2':	// Second case will be executed if you type '2'
                i = (char) 116;	// 'i' becomes char with value 116 (letter 't' according to ASCII)
                printf ("The first letter of the number is: %c\n", i);	// Prints the letter 't' with the text
                break;
            case '3':	// Third case will be executed if you type '3'
                i = (char) 116;	// The same as case '2'
                printf ("The first letters of the number are: %c\n", i);	// The same as in case '2'
                break;
            default:	// Default case will be executed if you type other numbers or letters
                printf ("Unknown character. Please, try again\n");	// Prints the text
                break;
        }	// End of a switch-case
}
