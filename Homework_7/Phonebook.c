/* **Phonebook saves all the contacts in 'Contacts.txt!**
	Features:
	- Program prevents the input of letters and other characters, except numbers, in 'switch-cases'.
	- Program prevents to create more then 1 contact with identical information.
	- Prints an error message if you try search or list contacts in empty Phonebook.
	- Prints an error message if search function doesn't find anyting.
	- Program prevets to create infinite number of contacts.
	- Allows to search by first name, last name and phonenumber.
	- Usage of a header file with text constants. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>		// Used 'string.h' to work with string comparison.
#include <stdbool.h>		// Used 'stdbool.h' to work with boolean expressions.
#include <unistd.h>		// Used 'unistd.h' to use 'sleep()'.

#include "Config.h"		// Created a header, that store text information and some variables.

bool condition = false;		// Initialiazed boolean variable 'condition' to trigger some actions.
bool condition_start = false;	// Initialized boolean variable 'condition_start' to identify start of the program.
int count = 0;			// Initialized variable 'count' to control number of created contacts.

struct Phonebook client [MAX_VALUE];	// Initialized object 'client' of the structure 'Phonebook' with value '10'.

int main ()
{

	if (condition_start == false)	// Check function will be executed only at the start of the program.
		pb_check ();
		condition_start = true;		// After that 'pb_check' will be called only next time user turns on the program.

	system ("clear");

	int input;
	do {
		printf (STR_H);
		scanf ("%*c %d", &input);	// TODO **FIX SCANF** /'%*c' means that 'scanf' will ignore any characters except numbers. Letters can cause infinite loop.
		switch (input) {
			case 1: pb_add ();
			case 2: pb_search ();
			case 3: pb_list ();
			case 4: system ("clear"); printf (STR_EXIT); exit (1);	// 'STR_EXIT' represents the text, defined in 'Config.h'. '%s' is not required.
 			default: system ("clear"); printf (STR_ERR_INV);
		}
	} while (input < 1 || input > 4);
}

void pb_add ()		// Addition of a new contact.
{
	system ("clear");

	if (count > MAX_VALUE) {	// If number of created contacts equals MAX_VALUE, program will deny a creation of a new contact.
		printf (STR_ERR_FULL);
		sleep (2);		// 'sleep(2)' pauses the execution of the program for 2 sec. Then resumes.

		int input;
		do {	
			printf (STR_LST_END);
			printf (STR_YN);
			scanf ("%*c %d", &input);
			switch (input) {
				case 1: system ("clear"); printf (STR_EXIT); exit (1);
				case 2: main ();
				default: system ("clear"); printf (STR_ERR_INV);
			}
		} while (input < 1 || input > 2);
	}
		 
	else {
		printf (STR_ADD_FNAME);
		scanf ("%s", client[count].fname);	// Requires the input of a string which will be stored in structure object. 'count' is a number of current contact.

		printf (STR_ADD_LNAME);
		scanf ("%s", client[count].lname);

		printf (STR_ADD_NUM);
		scanf ("%s", client[count].number);

		for (int n = 0; n < count; n++) {
			/* In this loop program checks if inputs above equal to any other contact exiciting in Phonebook. If they all 100% match to contact created before, program will deny the creation
				of a new contact with the same name and print an error message. */
			if (strcmp (client[n].lname, client[count].lname) == 0 && strcmp (client[n].fname, client[count].fname) == 0 && strcmp (client[n].number, client[count].number) == 0) {
				printf (STR_ERR_REP);
				sleep (3);
				pb_add ();
			}
			else
				continue;
		}

		system ("clear");
		printf ("Contact '%s %s' (%s) was successfully saved in the phonebook!\n\n", client[count].fname, client[count].lname, client[count].number);

		FILE *fp;
		if ((fp = fopen ("Contacts.txt", "a")) == NULL);	// Opens 'Contacts.txt' and will add information in the end of the file.
			fprintf (stderr, "Unable to open the file\n");

		fprintf (fp, "%s %s %s\n", client[count].fname, client[count].lname, client[count].number);	// Saves information in text file.

		fclose (fp); 

		count++;		// After contact was created and saved it changes 'count' by 1, so the next contact will be new.
		condition = true;	// 'condition' changes to 'true' so it now enables to use search and list options, because the first contact was created.
	}

	int input;
	do  {	
		printf (STR_ADD_END);
		printf (STR_YN);

		scanf ("%*c %d", &input);
		switch (input) {
			case 1: pb_add ();
			case 2: main ();
			default: system ("clear"); printf (STR_ERR_INV);
		}
	} while (input < 1 || input > 2);
}

void pb_list ()		// Listing of all contact function.
{
	system ("clear");

	if (condition == false)		// If 'condition' remains 'false' it will display only error message, because Phonebook is 'empty'.
		printf (STR_ERR_EMPT);

	else {				// If 'condition' is 'true' it will print all the created contacts.
		printf ("Printing the list of contacts:\n\n");

		for (int i = 0; i < count; i++)
			printf ("(%d)\n\tFirst Name: %s\n\tLast Name: %s\n\tPhone number: %s\n", i+1, client[i].fname, client[i].lname, client[i].number);

		printf ("\n");
	}

	int input;
	do {	
		printf (STR_LST_END);
		printf (STR_YN);

		scanf ("%*c %d", &input);
		switch (input) {
			case 1: system ("clear"); printf (STR_EXIT); exit (1);
			case 2: main ();
			default: system ("clear"); printf (STR_ERR_INV);
		}
	} while (input < 1 || input > 2);
}

void pb_search ()	// Search contact function.
{
	system ("clear");

	int x, n;		// 'x' for input, 'n' - for the loop, used to search created contacts.
	bool search_status = false;		// 'search_status' is responsible for displaying error message, that search failed and program found nothing.
	char tmp_fname [20], tmp_lname [20], tmp_number [20];		// Creating temporal char arrays. Used to compare temporal and created information.

	if (condition == false) {
		printf (STR_ERR_EMPT);
		search_status = true;
	}

	else {		// All the search menu allows you yo search contact by first name, last name and phone number.
		do {
			printf (STR_SRCH_INP);
			scanf ("%*c %d", &x);
			if (x < 1 || x > 4) {
				system ("clear");
				printf (STR_ERR_INV);
			}
		} while (x < 1 || x > 4);

		if (x == 1) {	// Search by the first name.
			system ("clear");

			printf (STR_ADD_FNAME);
			scanf ("%s", tmp_fname);	// Requiers to enter the name you aware of.

			for (n = 0; n < count; n++) {	// Starts the loop and check through all created contacts.
				if (strcmp (tmp_fname, client[n].fname) == 0) {		// If a temporal name equals to the crated one program will print all the contacts with that name.
					printf ("(%d)\n\tFirst Name: %s\n\tLast Name: %s\n\tPhone number: %s\n", n+1, client[n].fname, client[n].lname, client[n].number);
					search_status = true;	// Changes status to 'true', so the user avoids the error message.
				}
			}

			if (search_status == false)	// If 'search_status' remains unchanged program prints the error message that contact with the inputed name was not found.
				printf (STR_ERR_NTF);

			printf ("\n");
		}

		if (x == 2) {	// Search by the last name.
			system ("clear");

			printf (STR_ADD_LNAME);
			scanf ("%s", tmp_lname);

			for (n = 0; n < count; n++) {
				if (strcmp (tmp_lname, client[n].lname) == 0) {
					printf ("(%d)\n\tFirst Name: %s\n\tLast Name: %s\n\tPhone number: %s\n", n+1, client[n].fname, client[n].lname, client[n].number);
					search_status = true;
				}
			}

			if (search_status == false)
				printf (STR_ERR_NTF);

			printf ("\n");
		}

		if (x == 3) {	// Search by the number.
			system ("clear");

			printf (STR_ADD_NUM);
			scanf ("%s", tmp_number);

			for (n = 0; n < count; n++) {
				if (strcmp (tmp_number, client[n].number) == 0) {
					printf ("(%d)\n\tFirst Name: %s\n\tLast Name: %s\n\tPhone number: %s\n", n+1, client[n].fname, client[n].lname, client[n].number);
					search_status = true;
				}
			}

			if (search_status == false)
				printf (STR_ERR_NTF);

			printf ("\n");
		}

		if (x == 4)	// Return to the menu
			main ();
	}

	int input;
	do {	
		printf (STR_SRCH_END);
		printf (STR_YN);

		scanf ("%*c %d", &input);
		switch (input) {
			case 1: pb_search ();
			case 2: main ();
			default: system ("clear"); printf (STR_ERR_INV);
		}
	} while (input < 1 || input > 2);
}

int pb_check ()
{
	FILE *fp;
	if ((fp = fopen ("Contacts.txt", "r+")) == NULL)	// Opens 'Contacts.txt' in the read-only mode.
		fp = fopen ("Contacts.txt", "w");		// If program cannot open the file, it creates file and after that reads it only

	fseek (fp, 0, SEEK_END);	// Searches the end of the .txt file and write this information in 'file_size' variable.
	int file_size = ftell (fp);
	rewind (fp);	// When 'file_size' is recorded a size of a file, 'rewind()' returns all changes in default.

	int string_num = 1;	// 'Number' of a string in the file.
	int i;

	if (file_size == 0) {	// If the text file is empty, prints the message for 1 sec.
		system ("clear");
		printf ("--- File is empty ---\n");
		sleep (1);
	}

	else {	
		for (i = 0; !feof(fp); i++) {		// We need record strings from the file to the needed array of a structure. From 1 to 3.
			if (string_num %3 == 1)		// So if the current string is first on the line, it goes to 'client[i].fname'.
				fscanf (fp, "%s", client[i].fname);
				string_num++;		// Proceeds to the next word.

			if (string_num %3 == 2) 	//if the current string is second on the line, it goes to 'client[i].lname'.
				fscanf (fp, "%s", client[i].lname);
				string_num++;

			if (string_num %3 == 0)		//if the current string is third on the line, it goes to 'client[i].number'.
				fscanf (fp, "%s", client[i].number);
				string_num++;

			condition = true;		// When all the operations above are execucted, loop changes the array element and start the loop all over again until the file ends.
		}

		count = i-1;	// Because during the loop also recods empty space at the end of the file, program decrements value of 'i' by 1 and transmits gathered value to 'count'.
	}	

	fclose (fp);
}
