#include <stdio.h>

int main ()

{
	char a = 127; // Highest possible value for char data type
	printf ("'a' before incr. = %d\n",a); // Displays text and current value of variable "a" 
	a++; // Increments current value of variable "a" by 1, causing an overload
	printf ("'a' after incr. = %d\n",a); // Displays -128 because variable "a" was overloaded   

	return 0;
}
