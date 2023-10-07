// use V3 w/ circular orientation using Sol. 1 (using a ctr to track rotations) w/ a fixed dynamically allocated array for circular orientation
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#ifndef QUEUE_H
#define QUEUE_H
#define MAX 10

typedef{
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

bool isEmpty(Queue Q){
    
}
bool isFull(Queue Q);
void enqueue(Queue *Q, int elem);
void dequeue(Queue *Q);
int front(Queue Q);
void display(Queue Q);


#endif // !QUEUE_H