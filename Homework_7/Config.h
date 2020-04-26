#define MAX_VALUE 9	// #define function allows to assign macroses or text constant. Here we assign 'MAX_VALUE' which equals 9
#define STR_H "\t\tPlease, select an option to continue.\n\n"\
	"1. Add a new contact.\n"\
	"2. Find a contact.\n"\
	"3. View all contacts.\n"\
	"4. Exit.\n"	// #define even could assign a function or a text constant throgh multiple lines like shown above. Backslash ('\') breaks a line on the next one. Last line doesn't requier backslash
#define STR_EXIT "Farewell!\n"
#define STR_ADD_FNAME "Please, enter the first name of the contact.\n\a>"
#define STR_ADD_LNAME "Please, enter the last name of the contact.\n\a>"
#define STR_ADD_NUM "Please, enter the number of the contact.\n\a>"
#define STR_ADD_END "Do you want to create new contact?\n\n"
#define STR_LST_END "Do you want to exit the Phonebook?\n\n"
#define STR_SRCH_INP "\t\tHow do you want to start search for a contact?\n\n"\
	"1. By the first name.\n"\
	"2. By the last name.\n"\
	"3. By the phone number.\n"\
	"4. Return to the menu.\n"
#define STR_SRCH_END "Do you want to search another contact?\n\n"
#define STR_YN\
	"1. Yes.\n"\
	"2. No. (return to the menu).\n"
#define STR_ERR_INV "Invalid selection, please try again.\n\n"
#define STR_ERR_FULL "--- Your Phonebook is full ---\n\n"
#define STR_ERR_REP "--- Contact with that data was already created, please try different name ---\n\n"
#define STR_ERR_EMPT "--- Your Phonebook is empty ---\n\n"
#define STR_ERR_NTF "--- Contact was not found ---\n"

void pb_add ();		// Protototypes of Phonebook I put to 'Config.h'
void pb_list ();
void pb_search ();
int pb_check ();

struct Phonebook {	// Also I store here the information about structure
	char fname [50];
	char lname [50];
	char number [50];
};
