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
    if(isEmpty(*Q)){
        Q->front = -1;
        Q->rear = -1;
    }else{
        for(int ctr = 0; ctr <= Q->rear; ctr++){
            shift(&(*Q).arr[ctr], &(*Q).arr[ctr + 1]);
        }
        Q->rear--;
    }
}

int front(Queue Q){
    return Q.arr[Q.front];
}

void display(Queue Q){
    Queue temp = initQueue(temp);
    if(isEmpty(Q)){
        printf("\nQUEUE IS EMPTY!");
    }else{
        printf("\nQUEUE:\t");
        while(Q.rear >= 0){ // display by using front then dequeue from orig queue and place it in the temp
            printf("%d\t", front(Q));
            enqueue(&temp, front(Q));
            dequeue(&Q);
        }
        while(temp.rear >= 0){ // after displaying all elements from orig queue, we enqueue them back from temp then dequeue
            enqueue(&Q, front(temp));
            dequeue(&temp);
        }
    }
    printf("\n");
}

#endif // !QUEUE_H
