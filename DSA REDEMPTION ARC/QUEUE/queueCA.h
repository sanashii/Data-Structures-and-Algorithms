#include<stdio.h>
#include<stdbool.h>
#ifndef QUEUE_H
#define QUEUE_H
#define MAX 5

// Q.rear == Q.front - 2 means its full (front ahead by 2 cells from rear) we can use a ctr but we're sacrificing a cell here lng
// Q.rear == Q.front - 1 means its empty (front ahead by 1 cell from rear)
//! NOTE: x % MAX is used to wrap around the array (circular orientation) so that if ever rear or front already reaches MAX, 
//!      it'll go back down to zero up until the condition whether its full or empty coems to play

typedef struct{
    int arr[MAX];
    int front;
    int rear;
}Queue;

Queue initQueue(Queue Q){
    Q.front = -1; 
    Q.rear = -1; 

    return Q;
}

bool isEmpty(Queue Q){
    return(Q.rear == Q.front - 1) ? true : false;
}

bool isFull(Queue Q){
    return(Q.rear % MAX == Q.front - 2) ? true : false; // will work for in order or wrapped Q.rear
}

void enqueue(Queue *Q, int elem){ 
    if(Q->front == -1){
        Q->front = 2; // assuming we're placing it in the 5th index 
        Q->rear = Q->front - 1;
    }
    
    if(!isFull(*Q)){
      Q->rear = (Q->rear + 1) % MAX;
      Q->arr[Q->rear] = elem;
    }else{
        printf("\nQUEUE IS FULL! Can no longer add element.");
    }
}

void dequeue(Queue *Q) { 
    if (!isEmpty(*Q)) {
        Q->front = (Q->front + 1) % MAX; // dequeue - basically does Q.front++ & % MAX will do the wrapping idf necessary na

        // check if the queue becomes empty after dequeueing.
        if (Q->front == (Q->rear + 1) % MAX) {
            Q->front = -1;
            Q->rear = -1;
        }
    }
}

int front(Queue Q){
    return Q.arr[Q.front];
}

void display(Queue Q) {
    printf("\nQUEUE:\t");
    if (!isEmpty(Q)) {
        int ctr = Q.front;
        do {
            printf("%d\t", Q.arr[ctr]);
            ctr = (ctr + 1) % MAX;
        } while (ctr != (Q.rear + 1) % MAX);
    }

    printf("\n");
}

#endif // !QUEUE_H
