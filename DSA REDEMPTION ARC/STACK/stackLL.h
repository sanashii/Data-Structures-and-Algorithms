#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#ifndef STACK_H
#define STACK_H
#define MAX 10

typedef struct node{
    char data;
    struct node *link;
}*STACK;


bool isEmpty(STACK S){ 
	bool retVal = false;
	if(S == NULL)
		retVal = true;
	return retVal;
}

bool isFull(STACK S){ // Not sure honestly lol
	bool retVal = false;
	return retVal;
}

void initialize(STACK *S){ 
	*S = NULL;
}

void push(STACK *S, char elem){
	if(!isFull(*S)){ // Dont think the if statement is needed since a linked list can't be full
		STACK newNode = malloc(sizeof(struct node));
		if(newNode != NULL){
			newNode->data = elem;
			newNode->link = *S;
			*S = newNode;
		}
	}else{
		printf("\nSTACK OVERFLOW!");
	}
}

void pop(STACK *S){ 
	if(!isEmpty(*S)){
		STACK temp = *S;
		*S = temp->link;
		free(temp);
	}else{
		printf("\nSTACK UNDERFLOW!");
	}
}

char top(STACK S) {
	char retVal = '/';
    if (!isEmpty(S)) 
        retVal = S->data;
    
	return retVal;
}


void displayStack(STACK S){
	// have a temp stack, push to temp then pop from the original
	// after everything we push to main and pop from temp
	STACK temp;
	initialize(&temp);
	char elem;
	while(!isEmpty(S)){
		elem = top(S);
		printf("%c\n", elem);
		push(&temp, elem);
		pop(&S);
	}

	while(!isEmpty(temp) && !isFull(S)){
		elem = top(temp);
		push(&S, elem);
		pop(&temp);
	}
	
}

#endif // !STACK_H
