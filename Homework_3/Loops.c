#include <stdio.h>
#include <stdbool.h>	// Adding 'stdbool.h' to make sure that boolean expression will work

int main ()

{
	int i,n,p;	// Initialize 'i', 'n' and 'p' variables

	do {	// Starting a 'do...while' loop

		for (i = 0; i < 5; i++) {		// Starting a for loop using 'i' variable within a 'do...while' loop
			printf ("i-Loop: %d\n", i); 	// Prints the 'i' variable, which means that 'for' loop is working fine
				while (n < 5) {		// Starting a 'while' loop using 'n' variable within a 'for' loop
					n++; 		// Increments 'n' by 1
					printf ("n-Loop: %d\n", n); 	// Prints the 'n' variable, which means that 'while' loop is working fine
				} 		// Ending of a 'while' loop
		} 		// Ending of a 'for' loop

		p = i = n; 	// Checks if all initialised variables are equal within a 'do...while' loop
		printf ("Total: %d\n", p);	// Prints the 'p' variable, which means that the whole combination of loops is working fine
		break;		// Breaks the loop when it reaches the end

	} while (p == true);	// 'do...while' loop checks if 'p' expression is true, so 'do...while' loop will work only once

	return 0;
}
