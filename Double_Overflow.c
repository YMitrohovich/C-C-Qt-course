#include <stdio.h>

int main ()

{
	double d = 1E+37; // 1E+37 is a maximum possible value for double data type

	printf ("old: %4.1E\n", d); // Prints the text and the number before multiplication
	d*=10; // Mutiplie by 10 to cause overflow
	printf ("new: %4.1E\n", d); // Prints 1E+38 on the screen, variable is overflowed

	return 0;
}

