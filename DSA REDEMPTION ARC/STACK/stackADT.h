#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#ifndef STACK_H
#define STACK_H
#define MAX 10


typedef struct node{ // v2 array implementation
    char data[MAX];
    int top;
}*STACK;

bool isEmpty(STACK S){ 
	bool retVal = false;
	if(S->top == -1) {
		retVal = true;
	} // naay na kulang bracket -miko
	return retVal;
}

bool isFull(STACK S){ // ixia
	bool retVal = false;
	if(S->top == MAX-1){
		printf("\nSTACK OVERFLOW!");
		retVal = true;
	}
	return retVal; // naay na kulang return -miko
}

void initialize(STACK *S){ // ixia
	*S = (STACK)malloc(sizeof(struct node));
	(*S)->top = -1;
}

void push(STACK *S, char elem){
	if(!isFull(*S)){
		(*S)->data[++(*S)->top] = elem;
	}else{
		printf("\nSTACK OVERFLOW!");
	}
}

void pop(STACK *S){ // ixia
	if(!isEmpty(*S)){
		(*S)->top--;
	}else{
		printf("\nSTACK UNDERFLOW!");
	}
}

char top(STACK S) {
	char retVal = '/';
    if (!isEmpty(S)) {
        retVal = S->data[S->top];
	}
	return retVal;
}


void displayStack(STACK S){ // na fix ra nako ang display stack -miko
	// have a temp stack, pop from orig and print then push to temp
	// after everything we pop from the temp and push to main balik
	STACK temp;
	initialize(&temp);
	char elem;
	while(!isEmpty(S)){
		elem = top(S);
		printf("%c\n", elem);
		pop(&S);
		push(&temp, elem);
	}

	while(!isEmpty(temp)){
		elem = top(temp);
		pop(&temp);
		push(&S, elem);
	}
}

#endif // !STACK_H