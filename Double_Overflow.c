#include <stdio.h>

int main ()

{
	double d = 1E+37; // 1E+37 is a maximum possible value for double data type
	printf ("old: %4.1E\n", d); // Prints the text and the number before multiplication
<<<<<<< HEAD

=======
	
>>>>>>> a0e403c76c70bf9f8229a05a2e7a14b3939ad734
	d*=10; // Mutiplie by 10 to cause overflow
	printf ("new: %4.1E\n", d); // Prints 1E+38 on the screen, which means that variable is overflowed

	return 0;
}

