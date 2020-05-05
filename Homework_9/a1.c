#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef struct Task {
	char *name;
	int time, priority, index;
	struct Task *nextTask;
} Task;

int size = 0;

Task * push (Task * taskHead);
Task * pop(Task * taskHead);
void peek (Task * taskHead);
Task * params (Task * taskHead);

int main () {
	srand (time(NULL));
	Task * taskHead;

	taskHead = push (taskHead);
	taskHead = params (taskHead);
	peek (taskHead);

	taskHead = push (taskHead);
	taskHead = params (taskHead);
	peek (taskHead);

	taskHead = pop (taskHead);
	peek (taskHead);
}

Task * params (Task * taskHead) {
	srand (time(NULL));
	char *array_name [5] = {"Clear browser history",
		"Download and install system updates",
		"Fix an issue",
		"Troubleshooting the system",
		"Delete files"};	

	taskHead->name = array_name [rand()%5];
	taskHead->time = 1 + rand()% (10 - 1 + 1);
	taskHead->priority = 1 + rand()% (3 - 1 + 1);

	return taskHead;
}

Task * push (Task * taskHead) {
	++size;
	Task *taskNew;

	taskNew = malloc(sizeof(Task));
	taskNew->index = size;

	taskHead->nextTask = taskNew;
	taskHead = taskNew;

	return taskHead;
}

Task * pop (Task * taskHead) {
	Task * temp;
	temp = taskHead;
	taskHead = taskHead->nextTask;
	temp->nextTask = NULL;
	free(temp);
	size--;

	return taskHead;
}

void peek (Task * taskHead) {
	printf ("\nTask #%d:\n\n\tName: %s\n\tPriority: %d\n\tTime required: %d sec\n\n\tNext Address: %p\n\tCurrent Address: %p\n",
		taskHead->index,
		taskHead->name,
		taskHead->priority,
		taskHead->time,
		taskHead->nextTask,
		&taskHead);
}
