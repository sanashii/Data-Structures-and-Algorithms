#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#ifndef STACK_H
#define STACK_H
#define MAX 10

//! IMPLEMENTATION OF CB VERSION 4
//! given the constraint of index continuity

typedef struct node{
    char data;
    int link;
}Nodes;

typedef struct vhNode{
    Nodes node[MAX];
    int avail;
}*VirtualHeap;

typedef struct stackNode{
    VirtualHeap vh;
    int head; // hold the index of the starting node in the populated stack
    int top; // hold the index of the top node in the stack
}*STACK;

bool isEmpty(STACK S){ 
    bool retVal = false;
    if(S->head == -1){ // if STACK S isnt pointing to anything
        retVal = true;
    }
    return retVal;
}

bool isFull(STACK S){
    bool retVal = false;
    if(S->vh->avail == -1){ // if there's no more node available
        retVal = true;
    }
    return retVal;
}

void initialize(STACK *S) {
    STACK temp = (STACK)malloc(sizeof(struct stackNode));
    temp->head = -1;
    temp->top = -1;
    temp->vh = (VirtualHeap)malloc(sizeof(struct vhNode));

    int ctr;
    for (ctr = 0; ctr < MAX - 1; ctr++) {
        temp->vh->node[ctr].link = ctr + 1;
    }
    temp->vh->node[ctr].link = -1; // the very last node
    temp->vh->avail = 0;

    *S = temp;
}


int allocSpace(STACK S){
    int retndx = S->vh->avail;
    if(!isFull(S)){ // if the stack is NOT full / avail != -1
        S->vh->avail = S->vh->node[S->vh->avail].link; // gets the next avail index
    }
    return retndx;
}

void deallocSpace(STACK *S, int ndx){
    if(ndx < MAX && ndx >= 0){
        (*S)->vh->node[ndx].link = (*S)->vh->avail; // the node to be put back to avail list will have a new link pointing to the current avail (for continuity)
        (*S)->vh->avail = ndx; // then the new avail will now be the index of the node we recently placed back since they're all still linking
    }
}

void push(STACK *S, char elem){
    if(!isFull(*S)){
        int ndx = allocSpace(*S);
        (*S)->vh->node[ndx].data = elem;
        (*S)->vh->node[ndx].link = -1;
        if((*S)->head == -1){ // if it's the 1st node added to the stack
            (*S)->head = ndx;
            (*S)->top = ndx;
        }else{
            if ((*S)->top != -1) { // Check if top is valid
                (*S)->vh->node[(*S)->top].link = ndx;
            }
            (*S)->top = ndx;
        }  
    }else{
        printf("\nSTACK OVERFLOW!\n");
    }
}

void pop(STACK *S){ // uses the idealogy of deleteFirst()
    if(!isEmpty(*S)){
        deallocSpace(S, (*S)->top);
        (*S)->top--;
        (*S)->vh->node[(*S)->top].link = -1;
    }else{
        printf("\nSTACK UNDERFLOW!\n");
    }
}

char top(STACK S) {
    char retVal = '/';
    if(!isEmpty(S)){
        retVal = S->vh->node[S->top].data;
    }
    return retVal;
}


void displayStack(STACK S) { //FIXME: since it loops endlessly
    STACK temp;
	initialize(&temp);
	char elem;
	while(!isEmpty(S)){
		elem = top(S);
		printf("%c\n", elem);
		push(&temp, elem);
		pop(&S);
	}

	while(!isEmpty(temp)){
		elem = top(temp);
		push(&S, elem);
		pop(&temp);
	}
}

#endif // !STACK_H