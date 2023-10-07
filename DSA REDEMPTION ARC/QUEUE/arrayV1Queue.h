//* regular array within a structure program w/ shifting
#include <stdio.h>
#include <stdbool.h>
#ifndef QUEUE_H
#define QUEUE_H
#define MAX 5

typedef struct{
    int arr[MAX];
    int front;
    int rear;
}Queue;


Queue initQueue(Queue Q){
    Q.front = -1;
    Q.rear = -1; // sentinel values to indicate that the queue is empty

    return Q;
}

void display(Queue Q){
    printf("QUEUE:\t");
    for(int ctr = 0; ctr <= Q.rear; ctr++){
        printf("%d\t", Q.arr[ctr]);
    }
    printf("\n");
}

void shift(int *a, int *b){
    *a = *b;
}

bool isEmpty(Queue Q){
    return(Q.front == -1 && Q.rear == -1) ? true : false;
}

bool isFull(Queue Q){
    return(Q.rear == MAX - 1) ? true : false;
}

void enqueue(Queue *Q, int elem){
    if(Q->front == -1){ // if queue is initially emtpy
        Q->front++;
    }
    if(!isFull(*Q)){ // if queue isnt full
        Q->arr[++Q->rear] = elem;
    }else{
        printf("\nQUEUE IS FULL! Can no longer add elements\n");
    }
}

void dequeue(Queue *Q){
    if(!isEmpty(*Q)){
        for(int ctr = 0; ctr <= Q->rear; ctr++){
            shift(&(*Q).arr[ctr], &(*Q).arr[ctr + 1]);
        }
        Q->rear--;
    }
}

int front(Queue Q){
    return Q.arr[Q.front];
}

#endif // !QUEUE_H
