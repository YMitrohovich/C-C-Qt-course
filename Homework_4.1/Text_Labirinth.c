#include <stdio.h>
#include <stdlib.h>	// Used 'stdlib.h' to use system ('clear')

int lab_intro ();	// Creating prototypes for menu, rooms, actions and etc.
int lab_menu ();
int room_hall ();
int room_red ();
int room_red_1 ();
int room_blue ();
int room_WC ();
int room_WC_1 ();
int room_book ();
int room_book_1 ();
int room_book_2 ();
int room_book_3 ();
int room_white ();
int room_white_1 ();
int room_exit ();

int room_exit ()	// Exit from the labirinth (final room)
{
	system ("clear");	// Clears all the text above from the terminal screen
	int c;	// Variable for selecting options
	
	printf ("\n-----------------------------------------------------------------------------------------------------------------------\n\n");	// Prints text and options
	printf ("					Congratulations!!!\n\n");
	printf ("				 You managed to find the exit!.\n");
	printf ("				        You are the best!\n");
	printf ("				       What do you choose?\n\n");
	printf ("1. Exit like a hero\n");
	printf ("\n-----------------------------------------------------------------------------------------------------------------------\n");

	scanf ("%d", &c);	// Requests an input to select an option
	
	switch (c) {	// 'switch-case' creates options to select. Basically it is switching between 'rooms' (functions)
			case 1:
				system ("clear");
				lab_menu ();	// Goes to main menu
				break;
	}
}

int room_white_1 ()	// Passcode 'interface'. Correct passcode is '5930' with 1 input.
{
	system ("clear");
	int c;

	printf ("\n-----------------------------------------------------------------------------------------------------------------------\n\n");
	printf ("					   You've decided to enter the passcode!\n\n");
	printf ("			It seems to be a standard numeric locker. It requires 4 numbers from 0 to 9.\n");
	printf ("					       (Enter 4 numbers in 1 input)\n");
	printf ("\n-----------------------------------------------------------------------------------------------------------------------\n");

	scanf ("%d", &c);

	if (c == 5930) {
		room_exit ();	// If user's input matches 'c', he proceedes ...
	}
	else {
		room_white ();	// If not, he returns in the previous room
	}
}

int room_white ()	// the White room menu
{
	system ("clear");
	int c;
	
	printf ("\n-----------------------------------------------------------------------------------------------------------------------\n");
	printf ("					   You've decided to approach the white door!\n\n");
	printf ("				You tried to open the door, but the door appeared to be closed.\n");
	printf ("			     On the right side you see something that looks like combination lock.\n");
	printf ("				   You can try to open the door if you know the combination.\n");
	printf ("					             What do you choose?\n\n");
	printf ("1. Try to enter the passcode.\n");
	printf ("2. Return to the long corridor.\n");
	printf ("3. Exit\n");
	printf ("\n-----------------------------------------------------------------------------------------------------------------------\n");

	scanf ("%d", &c);
	
	switch (c) {
			case 1:
				system ("clear");
				room_white_1 ();	// Goes to passcode interface
				break;
			case 2:
				system ("clear");
				room_blue ();	// Returns to the corridor
				break;
			case 3:
				system ("clear");
				lab_menu ();
				break;
	}
}

int room_book_1 ()	// Additional action in library. Location of third hint
{
	system ("clear");
	int c;
	
	printf ("\n---------------------------------------------------------------------------------------------------------------------------------------\n");
	printf ("					You've decided to look through some books on the floor!\n\n");
	printf ("	Well, it's not exactly books, there are diaries and journals. Among these journals you see a small paper with a number on it.\n");
	printf ("				      		      It is number '3'. (3/4)\n");
	printf ("					    	    	What do you choose?\n\n");
	printf ("1. Return\n");
	printf ("2. Exit\n");
	printf ("\n---------------------------------------------------------------------------------------------------------------------------------------\n");

	scanf ("%d", &c);
	
	switch (c) {
			case 1:
				system ("clear");
				room_book ();	// Returns to the library
				break;

			case 2:
				system ("clear");
				lab_menu ();
				break;
	}	
}

int room_book_2 ()	// Additional action in library. Empty location
{
	system ("clear");
	int c;
	
	printf ("\n-------------------------------------------------------------------------------------------------------------------------\n");
	printf ("				You've decided to check bookshelves on the left side of the room!\n\n");
	printf ("			   It took you some time to check every corner but you found nothing special.\n");
	printf ("					    	      What do you choose?\n\n");
	printf ("1. Return\n");
	printf ("2. Exit\n");
	printf ("\n-------------------------------------------------------------------------------------------------------------------------\n");

	scanf ("%d", &c);
	
	switch (c) {
			case 1:
				system ("clear");
				room_book ();
				break;

			case 2:
				system ("clear");
				lab_menu ();
				break;
	}	
}

int room_book_3 ()	// Additional action in library. Location of fourth hint
{
	system ("clear");
	int c;
	
	printf ("\n-------------------------------------------------------------------------------------------------------------------------\n");
	printf ("				You've decided to check bookshelves on the right side of the room!\n\n");
	printf ("	    You started to check the books and noticed that in this section most of them about mathematics...except one.\n");
	printf ("				   You opened that book and see a number drawn on the front page.\n"); 
	printf ("					    	  It is number '0'. (4/4)\n");
	printf ("					    	     What do you choose?\n\n");
	printf ("1. Return\n");
	printf ("2. Exit\n");
	printf ("\n-------------------------------------------------------------------------------------------------------------------------\n");

	scanf ("%d", &c);
	
	switch (c) {
			case 1:
				system ("clear");
				room_book ();
				break;

			case 2:
				system ("clear");
				lab_menu ();
				break;
	}	
}

int room_book ()	// Library
{
	system ("clear");
	int c;
	
	printf ("\n-----------------------------------------------------------------------------------------------------------------------\n");
	printf ("				        You've opened the door with book sign!\n\n");
	printf ("	      You've opened the door and see a large library with countless number of books ahead of you.\n");
	printf ("			     It will take an eternity to read them all. We can try though.\n");
	printf ("		   Here must be something interesting, no doubt about it...but where you should start.\n");
	printf ("					          What do you choose?\n\n");
	printf ("1. Look through some books on the floor.\n");
	printf ("2. Check the bookshelves on the left.\n");
	printf ("3. Check the bookshelves on the right.\n"); 
	printf ("4. Return to the long corridor.\n");
	printf ("5. Exit\n");
	printf ("\n-----------------------------------------------------------------------------------------------------------------------\n");

	scanf ("%d", &c);
	
	switch (c) {
			case 1:
				system ("clear");
				room_book_1 ();
				break;
			case 2:
				system ("clear");
				room_book_2 ();
				break;
			case 3:
				system ("clear");
				room_book_3 ();
				break;
			case 4:
				system ("clear");
				room_blue ();	// Returns to the corridor
				break;
			case 5:
				system ("clear");
				lab_menu ();
				break;
	}
}

int room_WC ()	// 'WC'
{
	system ("clear");
	int c;
	
	printf ("\n-----------------------------------------------------------------------------------------------------------------------\n");
	printf ("					   You've opened the door with 'WC' sign!\n\n");
	printf ("	It's just a regular restroom with toilet, sink, mirror and white walls. What did you expect? Las Vegas casino?\n");
	printf ("		Anyway, you notice that there is something strange with the mirror. Maybe it worth checking out.\n");
	printf ("					          What do you choose?\n\n");
	printf ("1. Take a closer look at the mirror.\n");
	printf ("2. Return to the long corridor.\n");
	printf ("3. Exit\n");
	printf ("\n-----------------------------------------------------------------------------------------------------------------------\n");

	scanf ("%d", &c);
	
	switch (c) {
			case 1:
				system ("clear");
				room_WC_1 ();	// Additional action in 'WC'
				break;
			case 2:
				system ("clear");
				room_blue ();	// Returns to the corridor	
				break;
			case 3:
				system ("clear");
				lab_menu ();
				break;
	}
}

int room_WC_1 ()	// Additional action in 'WC'. Location of the second hint
{
	system ("clear");
	int c;
	
	printf ("\n-------------------------------------------------------------------------------------------------------------------------\n");
	printf ("					You've decided to take a closer look at the mirror.\n\n");
	printf ("	     It's a big mirror with white frames. In the lower corner you notice that something is written there.\n");
	printf ("					    	    It is number '9'. (2/4)\n");
	printf ("					    	      What do you choose?\n\n");
	printf ("1. Return\n");
	printf ("2. Exit\n");
	printf ("\n-------------------------------------------------------------------------------------------------------------------------\n");

	scanf ("%d", &c);
	
	switch (c) {
			case 1:
				system ("clear");
				room_WC ();	// Returns to 'WC'
				break;

			case 2:
				system ("clear");
				lab_menu ();
				break;
	}	
}

int room_blue ()	// Corridor with three options where to go
{
	system ("clear");
	int c;
	
	printf ("\n---------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf ("							You've openned the blue door!\n\n");
	printf ("	There is a long corridor with walls painted in blue. On the walls you can see a lot of drawings of people and places you don't know.\n");
	printf ("				From here you can see 3 doors: door with 'WC' sign, door with book sign and old white door.\n");
	printf ("							     What do you choose?\n\n");
	printf ("1. Open the door with 'WC' sign.\n");
	printf ("2. Open the door with book sign.\n");
	printf ("3. Open the white door.\n");
	printf ("4. Return to the hall room.\n");
	printf ("5. Exit.\n");
	printf ("\n---------------------------------------------------------------------------------------------------------------------------------------------------\n");

	scanf ("%d", &c);
	
	switch (c) {
			case 1:
				system ("clear");
				room_WC ();	// Goes to 'WC'
				break;
			case 2:
				system ("clear");
				room_book ();	// Goes to the library
				break;
			case 3: 
				system ("clear");
				room_white ();	// Goes to the exit
				break;
			case 4:
				system ("clear");
				room_hall ();	// Goes to the starting location
			case 5:
				system ("clear");
				lab_menu ();
				break;
	}				
}

int room_hall () // Starting location with 2 options where to go
{
	system ("clear");
	int c;
	
	printf ("\n--------------------------------------------------------------------------------------\n\n");
	printf (" 	You are now standing in a large hall with multiple windows around you.\n");
	printf ("		   Ahead of you are 2 doors: red door and blue door.\n");
	printf (" 			       What do you choose?\n\n");
	printf ("1. Open the red door.\n");
	printf ("2. Open the blue door.\n");
	printf ("3. I am too old for this (leave through the front door).\n");
	printf ("4. Exit\n");
	printf ("\n--------------------------------------------------------------------------------------\n");

	scanf ("%d", &c);

	switch (c) {
			case 1:
				system ("clear");
				room_red ();	// Goes to the storage room
				break;
			case 2:
				system ("clear");
				room_blue ();	// Goes to the corridor
				break;
			case 3: 
				system ("clear");
				printf ("Farewell, loser!\n");	// Funny (not) joke that terminates the program
				exit (1);	// Terminates the program
				break;
			case 4:
				system ("clear");
				lab_menu ();
				break;
	}
}

int room_red ()	// Storage room
{
	system ("clear");
	int c;
	
	printf ("\n--------------------------------------------------------------------------------------------------------\n");
	printf ("					     You've opened the red door!\n\n");
	printf ("	      You are now standing in a small dark room with red walls that seemed to be a storage room.\n");
	printf ("			You can stay here and look around. Maybe you find something interesting.\n");
	printf ("					         What do you choose?\n\n");
	printf ("1. Look around.\n");
	printf ("2. Return to the hall room.\n");
	printf ("3. Exit\n");
	printf ("\n--------------------------------------------------------------------------------------------------------\n");

	scanf ("%d", &c);
	
	switch (c) {
			case 1:
				system ("clear");
				room_red_1 ();	// Additional action in storage room
				break;
			case 2:
				system ("clear");
				room_hall ();
				break;
			case 3:
				system ("clear");
				lab_menu ();
				break;
	}

}

int room_red_1 ()	// Additional action. Location of the first hint
{
	system ("clear");
	int c;
	
	printf ("\n-------------------------------------------------------------------------------------------------------------------------\n");
	printf ("					You've decided to look around for a while!\n\n");
	printf ("	You see a lot of boxes, bags ... nothing intresting. But when you turn around you see a small paper on the door.\n");
	printf ("					        There is number '5'. (1/4)\n");
	printf ("					    	   What do you choose?\n\n");
	printf ("1. Return\n");
	printf ("2. Exit\n");
	printf ("\n-------------------------------------------------------------------------------------------------------------------------\n");

	scanf ("%d", &c);
	
	switch (c) {
			case 1:
				system ("clear");
				room_red ();
				break;

			case 2:
				system ("clear");
				lab_menu ();
				break;
	}	
}

int lab_menu ()	// Main menu of the game
{
	system ("clear");
	int c;

	do {	// Repeats the 'switch-case' until user selects option '1'
		printf ("\n--------------------MAIN MENU-----------------------\n");
		printf ("\n   Please select a needed option to continue\n\n");
		printf ("1. Start\n");
		printf ("2. Help\n");
		printf ("3. Exit\n");
		printf ("\n----------------------------------------------------\n");

		scanf ("%d", &c);

		switch (c) {
			case 1:
				system ("clear");
				lab_intro ();	// Launches an intro
				break;
			case 2:
				system ("clear");
				printf ("\nIf you want to start the game, press '1'.\nIf you want to close the program, press '3'.\n");
				break;			
			case 3: 
				system ("clear");
				printf ("Farewell!\n");
				exit (1);
				break;
		}
	} while (c != 1); 
}

int lab_intro ()	// Introduction to the game
{
	system ("clear");	
	
	printf ("\n--------------------------------------------------------------------------------------------------------------\n");
	printf ("\n	     Welcome to the labirinth game! In this game you have to find an exit from the labirinth.\n");
	printf ("					   But the exit is locked.\n");
	printf ("	In order to open the door you have to find 4 numbers which are the pieces of passcode for the exit\n");
	printf ("				and enter them in the correct order to open the door.\n");
	printf ("					   Good luck and have fun!\n\n");
	printf ("				          Press any key to continue.\n");
	printf ("\n--------------------------------------------------------------------------------------------------------------\n");
	
	getchar ();
	
		if (getchar ()) {	// Starts the game only if user presses any button
			room_hall ();
		}
}

int main ()
{
	lab_menu ();
}
