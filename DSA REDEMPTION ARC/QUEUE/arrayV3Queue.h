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
    return(Q.ctr == 0 || Q.front == -1 && Q.rear == -1) ? true : false;
}

bool isFull(Queue Q){
    return(Q.ctr == MAX) ? true : false;
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

void display(Queue Q){ // FIXME: this method uses traversal and queues can not be traversed
    if (!isEmpty(Q)) {
        printf("\nQUEUE:\t");
        Queue temp = initQueue(temp);
        int ctr = Q.front;
        int count = 0;

        while (count < Q.ctr) {
            printf("%d\t", Q.elemptr[ctr]);
            enqueue(&temp, Q.elemptr[ctr]);
            ctr = (ctr + 1) % MAX;
            count++;
        }

        // Now, we can restore the original queue by dequeuing from temp
        while (!isEmpty(temp)) {
            enqueue(&Q, front(temp));
            dequeue(&temp);
        }
    }

    printf("\n");
}

#endif // !QUEUE_H