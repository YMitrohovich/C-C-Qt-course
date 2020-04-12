#include <stdio.h>
#include <stdlib.h>	// Used 'stdlib.h' to use system ('clear')
#include <time.h>	// Used 'time.h' to generate random numbers

int gn_menu ();		// Creating prototypes to do evaluations
int gn_intro ();
int game_new ();
int game_win (int, int);
int game_low (int, int);
int game_high (int, int);
int game_eval (int, int);

int gn_menu ()		// Main menu of the game
{
	int c;		// Variable for selecting menu options
	system ("clear");		// Clears all the text above from terminal screen 

	do {		// Repeats 'switch-case' until user selects option '1'
		printf ("\n------------------------------MAIN MENU--------------------------\n\n");
		printf ("		Please select any option to continue.\n\n");
		printf ("1. Start.\n");
		printf ("2. Help.\n");
		printf ("3. Exit.\n");
		printf ("\n-------------------------------------------------------------------\n");

		scanf ("%d", &c);	// Requests an input to select 1 of 3 options

		switch (c) {		// 'swithc-case' creates options for the menu
			case 1:
				system ("clear");
				gn_intro ();	// Starts an intro of the game
				break;
			case 2:
				system ("clear");
				printf ("\nIf you want to start the game, press '1'.\nIf you want to close the program, press '3'.\n");
				break;
			case 3: 
				system ("clear");
				printf ("Farewell!\n");
				exit (1);	// Terminates the program
				break;
		}
	} while (c != 1); 
}

int gn_intro ()		// Introduction of the game
{
	system ("clear");	
	
	printf ("\n------------------------------------------------------------------------------------------------------------------\n");
	printf ("\n	Welcome to the 'Guess Number' game! In this game you have to guess the number the program have chosen.\n");
	printf ("			Only numbers from 0 to 10 are accepted. If you guess right - you win.\n\n");
	printf ("					     Press any key to continue.\n");
	printf ("\n------------------------------------------------------------------------------------------------------------------\n");
	
	getchar ();
	
		if (getchar ()) {	// Doesn't go any further until user presses some button
			game_new ();	// Start of new game
		}
}

int game_new ()		// New game function that creates variables. 'i' - with random value from 0 to 10 and 'n' - user's input
{
	system ("clear");	

	srand (time (NULL));		// States the PC's current time as a basement for further calculations	

	int i,n;
	i = rand()%10;	// Assign a random value from 0 to 10 to variable 'i'

	do {		// Requests user to enter some number from 0 to 10. If input lower or higher program asks for input once again

		printf ("\n------------------------------------------------------------------------------------------------------------------\n");
		printf ("\n		   	  		The program have already chosen the number.\n");
		printf ("			Do you know what number is that? Remember, only numbers from 0 to 10 are allowed.\n\n");
		printf ("					        Enter a number to continue.\n");
		printf ("\n------------------------------------------------------------------------------------------------------------------\n");

		scanf ("%d", &n);

		if (n < 0 || n > 10) {
			
			system ("clear");
			printf ("Only numbers from 0 to 10 are allowed\n");
		}

	} while (n < 0 || n > 10);

	game_eval (i,n);	// Start of evaluation function with assigned values of 'i' and 'n'
}

int game_win (int i, int n)	// 'i = n' screen. Asks user if he wants to play again or return to the main menu
{
	system ("clear");
			
	int c;

	printf ("\n------------------------------------------------------------------------------------------------------------------\n");
	printf ("\n		   	  	Congratulation! You are correct, the number was %d.\n\n", i);
	printf ("					    Do you want to try again?\n\n");
	printf ("1. Yes (start new game)\n");
	printf ("2. No (return to menu)\n"); 
	printf ("\n------------------------------------------------------------------------------------------------------------------\n");
		
	scanf ("%d", &c);

		switch (c) {

			case 1: 
					game_new ();	// Starts new game
			case 2:
					gn_menu ();	// Returns to main menu
		}
}

int game_low (int i, int n) 	// 'i < n' sreen. Asks user to enter lower number than before
{						
	system ("clear");

	printf ("\n------------------------------------------------------------------------------------------------------------------\n");
	printf ("\n		   	  		The number is lower than yours.\n\n");
	printf ("					  Enter number lower than %d.\n", n);
	printf ("\n------------------------------------------------------------------------------------------------------------------\n");

	scanf ("%d", &n);

	game_eval (i,n);	// After getting new input, starts evaluation function once again but with new value			
}


int game_high (int i, int n) 	// 'i > n' screen. Asks to enter higher number than before
{
	system ("clear");

	printf ("\n------------------------------------------------------------------------------------------------------------------\n");
	printf ("\n		   	  		The number is higher than yours.\n\n");
	printf ("					  Enter number higher than %d.\n", n);
	printf ("\n------------------------------------------------------------------------------------------------------------------\n");

	scanf ("%d", &n);
	
	game_eval (i,n);
}
	
int game_eval (int i, int n)	// Evaluation function. Compares variables 'i' and 'n' and send them to the corresponding function depending on their values until 'i' equals 'n'
{
	if (i == n) {
		game_win (i,n);
	}

	if (i > n) {
		game_high (i,n);
	}

	if (i < n) {
		game_low (i,n);
	}
}

int main ()
{
	gn_menu ();
}
