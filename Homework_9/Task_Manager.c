#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>	// Used to enable 'sleep()' function.

// Defining text constants for menu
#define STR_H "Welcome to the 'Task Manager'!\nTo start executing the tasks, please choose the needed data type.\n\n"\
	"1. Stack.\n"\
	"2. Queue.\n"\
	"3. Exit.\n"
#define STR_E "Do you want to return to main menu?\n\n"\
	"1. Yes. (return to menu)\n"\
	"2. No. (exit the program)\n"

#define MAX_SIZE 10	// Defining max size of queue and stack.

typedef struct Task {	// Initializing 'Task' structure. After that change the name of structure to 'Task' instead of 'struct Task' via 'typedef'.
	char *name;
	int time, priority, index, size;
	struct Task *next, *prev;	// 'next' points to the next task, prev - to previous task.
} Task;

Task * s_push (Task * head);		// Creating prototypes of 'push', 'pop' and 'peek' function for 'stack' and 'queue'.
Task * s_pop (Task * head);
void q_push (Task * head, Task * new);
Task * q_pop (Task * head);
void peek (Task * head);

void stack (Task * head, int);		// Creating prototypes for 'stack and 'queue' functions.
void queue (Task * head, int);

Task * create_new (Task * head);	// Creating prototypes for auxiliary functions.
int params (Task * head, int);
int get_size (Task * head);
void run (Task * head, int);

bool stack_trigger = false;		// Boolean variables for swithcing the 'paths' in 'run' function.
bool queue_trigger = false;

int main () {
	system ("clear");
	srand (time(NULL));

	int tasks_num = 2 + rand()% (MAX_SIZE - 2 + 1);		// Generate random number of tasks (from 2 to 10).

	Task * head = NULL;

	int c;
	do {
		printf (STR_H);
		scanf ("%*c%d", &c);
		switch (c) {
			case 1 : stack (head, tasks_num); break;
			case 2 : queue (head, tasks_num); break;
			case 3 : printf ("Farewell!\n"); exit (1);
			default : printf ("Invalid selection! Please try again.\n\n"); break;
		}
	} while (c < 1 || c > 3);

	return 0;
}

void stack (Task * head, int tasks_num) {	// 'Stack' function.
	system ("clear");
	stack_trigger = true;	// 'Turn on' the stack trigger.

	for (int i = 0; i < tasks_num; i++) {	// Push tasks in stack according to generated number of total tasks.
		head = s_push (head);
	}

	char c;
	printf ("You have %d tasks.\nPress any key to start\n>", get_size (head));
	scanf ("%s", &c);

	run (head, tasks_num);		// Starts 'executing' of tasks.
}


Task * s_push (Task * head) {		// 'Push' function for 'stack'. Used singly linked list.
	if (!head) {		// If stackhead equals zero, it creates first task. Otherwise program terminates with error message.
		Task * new = malloc(sizeof(Task));	// Allocate memory for 'new' member of 'Task' structure.
		new->next = NULL;	// Assign that there is nothing after 'new'.
		new->size = 1;		// Increasing the size of stack.
			
		params (new, new->size);	// Calling the function which will assign random values to 'new'.
		return new;
	}

	else {

		if (head->size < MAX_SIZE) {	// Untill the size of stack is lower than 10.
			Task *new = malloc (sizeof(Task));
			params (new, head->size + 1);	// Calling the 'params' and increase the size of stack.

			new->next = head;	// Assign that the next element after 'new' will be the stackhead

			return new;
		}

		else {
			printf("\nERROR: Stack overflow!\n");	
			return NULL;
		}
	}		
}

Task * s_pop (Task * head) {	// 'Pop' function for 'stack'. Used singly linked list.
	if (head) {	// If there is stackhead program executes 'pop' function. Otherwise program terminates with error message.
		Task * temp = head;	// Creates temporal element which equals to the stackhead.
		free (head);		// Since temporal element is now is a copy of stackhead we delete orginal stackhead, using 'free()' function.

		Task *new;
		new = temp->next;	// Assign that 'new' element equals the next element after temporal element (aka stackhead copy). 

		return new;
	}

	else {
		printf("ERROR: Stack is empty!\n");
		return NULL;
	}
}

void queue (Task * head, int tasks_num) {	// 'Queue' function.
	system ("clear");
	queue_trigger = true;

	head = malloc (sizeof(Task));	
	head->size = 1;
	head->next = NULL;
	params (head, head->size);

	Task * head_2 = create_new(head);	// Because I couldn't implement it other way, we have to create several 'task' members manually and link each of them together.
	Task * head_3 = create_new(head_2);
	Task * head_4 = create_new(head_3);
	Task * head_5 = create_new(head_4);

	q_push (head, head_2);		// 'Push' has arguments of previous task (first argument) and the new task (second argument) to link them together.
	q_push (head_2, head_3);
	q_push (head_3, head_4);
	q_push (head_4, head_5);

	tasks_num = head_5->size;	// So the total number of tasks equals the size of the last pushed task.

	char c;
	printf ("You have %d tasks.\nPress any key to start\n>", get_size (head_5));
	scanf ("%s", &c);

	run (head, tasks_num);
}

void q_push (Task * head, Task * new) {		// 'Push' function for queue. Used doubly linked list.
	if (head->size < MAX_SIZE) {
		head->next = new;	// Assign that next element of current task is the new task.
		new->prev = head;	// And the task before new is current task. So they are now both linked.
	}

	else {
		printf("\nERROR: Queue overflow!\n");	
		exit (1);
	}
}

Task * q_pop (Task * head) {		// 'Pop' function for queue. Used singly linked list. Basically function the same is for stack.
	if (head) {
		Task * temp = head;
		free (head);

		Task * new;
		new = temp->next;

		return new;
	}

	else {
		printf("ERROR: Queue is empty!\n");
		return NULL;
	}
}

Task * create_new (Task * head) {	// Function to create new elements.
	Task * new = malloc (sizeof(Task));	
	new->next = NULL;
	params (new, head->size + 1);

	return new;
}

int params (Task * head, int size) {	// Function to assign values to the head element.
	char *array_name [] = {"Clear browser history",		// Creating the array with 5 different strings. Will be used as names for tasks.
		"Download and install system updates",
		"Fix an issue",
		"Troubleshooting the system",
		"Delete files"};	

	head->name = array_name [rand()%5];		// The name of the head element will be randomly chosen from 5 strings, created above.
	head->time = 1 + rand()% (10 - 1 + 1);		// The duration time is assigned randomly from 1 to 10.
	head->priority = 1 + rand()% (3 - 1 + 1);	// The prioirity is assigned randomly from 1 to 3. Has no real value for now.
	head->size = size;
	head->index = size;
}

int get_size (Task * head) {		// Function the returns the size of structure.
	return head->size;
}

void peek (Task * head) {	// 'Peek' function. Used to show the head element of the structure.
	if (head) {
		printf ("\nTask #%d:\n\n\tName: %s\n\tPriority: %d\n\tTime required: %d sec\n",
			head->index,
			head->name,
			head->priority,
			head->time);
	}

	else {
		printf("\nERROR: There are no elements left!\n");
		exit (1);
	}
}

void run (Task * head, int tasks_num) {		// 'Run' function. Used to 'execute' tasks from 'queue' or 'stack' structures.
	if (queue_trigger == true) {		// If this functions executes from 'queue' function program continues from here.
		while (head) {
			printf ("\n#%d task out of %d is now executing\n", head->index, tasks_num);		// Shows the index of current task and total number of tasks.
			peek (head);	// Prints all information of the head element.
			sleep (head->time);	// Pauses the program for the time, assigned in head element in 'params' function.
			head = q_pop (head);	// 'Pops' (deletes) the head element and change the head element to the next one.
			printf ("\n--- Success! ---\n");
		}

		if (!head)	// When all tasks are executed and data structure is empty program prints the message below.
			printf ("\nYou have no more tasks left in queue!\n\n");

		queue_trigger = false;	// Change the trigger back to false to avoid duplicating of run function.
	}

	if (stack_trigger == true) { // If this functions executes from 'stack' function program continues from here.
		while (head) {
			printf ("\n%d tasks remaining out of %d\n", head->index, tasks_num);
			peek (head);
			sleep (head->time);
			head = s_pop (head);
			printf ("\n--- Success! ---\n");
		}

		if (!head)
			printf ("\nYou have no more tasks left in stack!\n\n");

		stack_trigger = false;
	}

	int c;
	do {
		printf (STR_E);
		scanf ("%*c%d", &c);
		switch (c) {
			case 1 : main (); break;
			case 2 : printf ("Farewell!\n"); exit (1);
			default : printf ("Invalid selection! Please try again.\n\n"); break;
		}
	} while (c < 1 || c > 2);
}
