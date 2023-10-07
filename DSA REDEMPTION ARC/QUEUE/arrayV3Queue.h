// use V3 w/ circular orientation using Sol. 1 (using a ctr to track rotations) w/ a fixed dynamically allocated array for circular orientation
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#ifndef QUEUE_H
#define QUEUE_H
#define MAX 10

typedef struct{
    int *elemptr;
    int front;
    int rear;
    int ctr;
}Queue;

Queue initQueue(Queue Q){
    Q.elemptr = (int*)malloc(MAX*sizeof(int));
    Q.front = -1;
    Q.rear = -1;
    Q.ctr = 0;
    return Q;
}

bool isEmpty(Queue Q){ // using a ctr variable
    return(Q.ctr == 0) ? true : false;
}

bool isFull(Queue Q){
    return(Q.ctr == MAX - 1) ? true : false;
}

void enqueue(Queue *Q, int elem){
    if(Q->front == -1){
        Q->front = 3; // randomly starts at index 3
        Q->rear = Q->front - 1;
    }
    if(!isFull(*Q)){
        Q->rear = (Q->rear + 1) % MAX;
        Q->elemptr[Q->rear] = elem;
        Q->ctr++;
    }else{
        printf("\nQUEUE IS FULL! Can no longer add elements.");
    }
}

void dequeue(Queue *Q){
    if(!isEmpty(*Q)){
        Q->front = (Q->front + 1) % MAX;
        Q->ctr--;

        if(Q->front == (Q->rear + 1) % MAX){ // checks if Queue is empty
            Q->front = -1;
            Q->rear = -1;
        }
    }
}

int front(Queue Q){
    return Q.elemptr[Q.front];
}

void display(Queue Q){
    // if(!isEmpty(Q)){ //! old code -- works but can be confusing sometimes and too complex
    //     printf("\nQUEUE:\t");
    //     int iteration = 0;
    //     for(int ctr = Q.front; ctr != (Q.rear + 1) % MAX && iteration <= Q.ctr; ctr = (ctr + 1) % MAX, iteration++){
    //         printf("%d\t", Q.elemptr[ctr]);
    //     }
    // }
    if (!isEmpty(Q)) { //* more readable
        printf("\nQUEUE:\t");
        int iteration = 0, ctr = Q.front;
        while (iteration < Q.ctr) {
            printf("%d\t", Q.elemptr[ctr]);
            ctr = (ctr + 1) % MAX;
            iteration++;
        }
    }
    printf("\n");
}


#endif // !QUEUE_H