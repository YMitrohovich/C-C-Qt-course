#include <stdio.h>

int n,i,l;	// Initialization of global variables for counting number of loops for each recursive function

int birthDay (int);	// Creating prototypes of recursive functions for day, month and year of the birthday
int birthMonth (int);	
int birthYear (int);

int birthDay (int day)	// Start of the recursive function with the value declared in main

{	
	if (1 <= day) {
		n++;	// Counting number of loops in this function
		printf ("Loop: %d\n", n);	// Prints the number of each loop
		return birthDay (day - 1);	// If conditional meets all requirments, it calls the same function once again until value equals 0
	}

	return n;	// Returns the total number of loops for this function
}	// End of the recursive function

int birthMonth (int month)

{	
	if (1 <= month) {
		i++;
		printf ("Loop: %d\n", i);	
		return birthMonth (month - 1);
	}

	return i;
}

int birthYear (int year)

{	
	if (1 <= year) {
		l++;
		printf ("Loop: %d\n", l);	
		return birthYear (year - 1);
	}

	return l;
}

int main ()

{
	int f,d,m,y;	// Initialization of variables for day (d), month (m), year (y) and required value (f)
	printf ("\nPlease enter the day of your birthday\n");	// Prints the text
	scanf ("%d", &f);	// Asks user to enter integer value and keeps it in variable 'f' until the next request
	
	d = birthDay (f); // Value of variable equlals the corresponding recursive function with value 'f'
	printf ("The day is: %d\n", d);	// Prints the final value of recursive function

	printf ("\nPlease enter the month of your birthday\n");
	scanf ("%d", &f);	// Variable 'f' "forgets" the last value and will keep the new value once it entered

	m = birthMonth (f);
	printf ("The month is: %d\n", m);

	printf ("\nPlease enter the year of your birthday\n");
	scanf ("%d", &f);

	y = birthYear (f);
	printf ("The year is: %d\n", y);

	printf ("\nYour birthday is: %d.%d.%d\n", d, m, y);	// Prints the whole birthday number
	printf ("Summary of the numbers is: %d\n", d + m + y);	// Counting values of all the needed variables and prints their summary

	return 0;
}
