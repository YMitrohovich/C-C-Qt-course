#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_POSITIONS 10

struct Item{
	int price;
	char * name;
	int count;
	//....
	int size;
	struct Item * prev;
	struct Item * next;
};


void peek(struct Item * stackHead){
	printf("%s: $ %d N: %d I: %d - CP: %p NP: %p \n",
		stackHead->name,
		stackHead->price,
		stackHead->count,
		stackHead->size,
		stackHead,
		stackHead->prev);
}


struct Item * push(struct Item * stackHead, struct Item * cur){

	if(stackHead->size < MAX_POSITIONS){		
		stackHead->prev = cur;	
		stackHead = cur;
		stackHead->next = NULL;	
		stackHead->size++;
		return stackHead;
	}
	else{
		printf("ERROR: Stack overflow!\n");	
		return NULL;
	}	
}



struct Item * pop(struct Item * stackHead){

	if(stackHead->size > 0){
		stackHead = stackHead->prev;
		stackHead->next = NULL;
		return stackHead;
	}
	else{
		printf("ERROR: Stack is empty!\n");
		return NULL;
	}	
}
int getStackSize(struct Item * stackHead){
	return stackHead->size ;
}



void initName(struct Item * curSt, char * name){
	curSt->name = name;
}

void initParamsItem(struct Item * curSt, int size){
	curSt->price = rand()%100 + 10;
	curSt->count = rand()%10 + 0;
	curSt->size = size;
}






int main(){
	srand(time(NULL));



	struct Item Items[MAX_POSITIONS];
	struct Item * stackHead = &Items[0]; 


	struct Item tmp;
	for (int i = 0; i < 3; i++) {
		initName(&Items[i],"Apple");
		initParamsItem(&Items[i], i);

		stackHead = push(stackHead, &tmp);
		peek(stackHead);
	}

	//struct Item tmp2;
	//initName(&tmp2,"32985");
	//initParamsItem(&tmp2, getStackSize(stackHead));
	
	//stackHead = push(stackHead, &tmp2);
	//peek(stackHead);

		
	return 0;
}
