#include <stdio.h>

int main ()
{
	int a = 0;
loop:			// Creating a mark 'loop' for 'goto' to return
	a++;
	printf ("%d.\n", a);
	if (a < 100) goto loop;		// If variable 'a' doesn't equals 100, 'goto' goes to mark 'loop'

	return 0;	// If variable 'a' equals 100, 'goto' part is ignored
}
