// use V2 w/ circular orientation using Sol. 2 (sacrificing 1 cell)
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#ifndef QUEUE_H
#define QUEUE_H
#define MAX 10

typedef struct node{
    int arr[MAX];
    int front;
    int rear;
}*Queue;

Queue initQueue(Queue Q){
    Queue temp = (Queue)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->front = -1;
        temp->rear = -1;
        Q = temp;
    }
    return Q;
}

bool isEmpty(Queue Q){
    return(Q->rear == Q->front - 1) ? true : false;
}

bool isFull(Queue Q){
    return(Q->rear % MAX == Q->front - 2) ? true : false; //* REMINDER: dont forget to wrap Q.rear!!
}

void enqueue(Queue *Q, int elem){
    if((*Q)->front == -1){
        (*Q)->front = 6; // randomly placing the front to start at 6
        (*Q)->rear = (*Q)->front - 1;
    }

    if((!isFull(*Q))){
        (*Q)->rear = ((*Q)->rear + 1) % MAX; // does the incrementing and wrapping of rear
        (*Q)->arr[(*Q)->rear] = elem;
    }else{
        printf("\nQUEUE IS FULL! Can no longer add element.");
    }
}

void dequeue(Queue *Q){
    if(!isEmpty(*Q)){
        (*Q)->front = ((*Q)->front + 1) % MAX;     // front increments whilst wrapping if necessary

        if((*Q)->front == ((*Q)->rear + 1) % MAX){ // checks if Queue is empty
            (*Q)->front = -1;
            (*Q)->rear = -1;
        }
    }
}

int front(Queue Q){
    return Q->arr[Q->front];
}

void display(Queue Q){
    printf("\nQUEUE:\t");
    if(!isEmpty(Q)){
        int ctr = Q->front;
        do{
            printf("%d\t", Q->arr[ctr]);
            ctr = (ctr + 1) % MAX; //* increments ctr whilst wrapping when necessary
        }while(ctr != (Q->rear + 1) % MAX); //* while ctr isnt == to the rear whether wrapped or not
    }
    printf("\n");
}

#endif // !QUEUE_H