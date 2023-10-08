#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#ifndef QUEUE_H
#define QUEUE_H
#define MAX 10

typedef struct node{
    int *elemptr;
    int front;
    int rear;
    int ctr;
}*Queue;

Queue initQueue(Queue Q){
    Q = (Queue)malloc(sizeof(struct node));
    if(Q != NULL){
        Q->elemptr = (int*)malloc(sizeof(int) * MAX);
        Q->front = -1;
        Q->rear = -1;
        Q->ctr = 0;
    }

    return Q;
}

bool isEmpty(Queue Q){ // using a ctr variable
    return(Q->ctr == 0) ? true : false;
}

bool isFull(Queue Q){ // base it off of ctr not MAX since the array is dynamic and will readjust based on ctr
    return(Q->rear == Q->ctr) ? true : false;
}

void enqueue(Queue *Q, int elem){
    if((*Q)->front == -1){
        (*Q)->front++;
    }
    
    if(!isFull(*Q)){   
        (*Q)->ctr++;
    }else{
        (*Q)->ctr *= 2;
        (*Q)->elemptr = (int*)realloc((*Q)->elemptr, (*Q)->ctr);
    }

    (*Q)->elemptr[++(*Q)->rear] = elem;
}

void dequeue(Queue *Q){
    if(!isEmpty(*Q)){
        (*Q)->front++;

        if(isEmpty(*Q)){
            (*Q)->front = -1;
            (*Q)->rear = -1;
        }

        if((*Q)->ctr <= (*Q)->ctr / 2 && (*Q)->ctr > MAX){ // 1st condition checks if the current # of elements is 50% off of the allocated memory
            (*Q)->ctr /= 2;
            (*Q)->elemptr = (int*)realloc((*Q)->elemptr, (*Q)->ctr);
        }
    }
}

int front(Queue Q){
    return Q->elemptr[Q->front];
}

void display(Queue Q){
    int ctr;
    printf("\nQUEUE:\t");
    for(ctr = Q->front; ctr < Q->ctr; ctr++){
        printf("%d\t", Q->elemptr[ctr]);
    }
    printf("\n");
}

#endif // !QUEUE_H   