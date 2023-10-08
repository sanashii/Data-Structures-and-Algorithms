#include<stdio.h>
#include<stdbool.h>
#ifndef QUEUE_H
#define QUEUE_H
#define MAX 10

typedef struct node{
    int data;
    int link;
}Nodes;
typedef struct heap{
    Nodes node[MAX];
    int avail;
    int front;
    int rear;
}VirtualHeap, *Queue;

Queue initQueue(Queue Q){
    Q = (Queue)malloc(sizeof(VirtualHeap));
    Q->front = -1;
    Q->rear = -1;
    int ctr;
    for(ctr = 0; ctr < MAX - 1; ctr++){
        Q->node[ctr].link = ctr + 1;
    }
    Q->node[ctr].link = -1;
    Q->avail = 0;

    return Q;
}

bool isEmpty(Queue Q){
    return(Q->front == -1 && Q->rear == -1) ? true : false;
}

bool isFull(Queue Q){
    return(Q->avail == -1) ? true : false;
}

int allocSpace(Queue Q){ // used in enqueue
    int retAvail = Q->avail;
    Q->avail = Q->node[Q->avail].link;
    return retAvail;
}

void deallocSpace(Queue *Q, int ndx){ // used in dequeue
    if(ndx < MAX && ndx >= 0){
        (*Q)->node[ndx].link = (*Q)->avail; // the node to be put back to avail will link to the current avail
        (*Q)->avail = ndx; // then the ndx will now be the new avail
    }
}

void enqueue(Queue *Q, int elem){
    if((*Q)->front == -1){
        (*Q)->front = allocSpace(*Q); // we give the front a new value of the avail index;
        (*Q)->rear = (*Q)->front;
        (*Q)->node[(*Q)->front].data = elem;
        (*Q)->node[(*Q)->front].link = -1;
    }else{
        if(!isFull(*Q)){
            int temp = allocSpace(*Q);
            (*Q)->node[(*Q)->rear].link = temp; // (old)rear will get the new index for the new rear
            (*Q)->rear = temp; // before assigning rear with the new index value
            (*Q)->node[(*Q)->rear].data = elem;
            (*Q)->node[(*Q)->rear].link = -1;
        }
    }
}

void dequeue(Queue *Q){
    if(!isEmpty(*Q)){
        int temp = (*Q)->node[(*Q)->front].link; // gets the link of the old front
        deallocSpace(Q, (*Q)->front); // returns old front to the avail list
        (*Q)->front = temp; // assigns front to the next node it was originally pointing to
    }
}

int front(Queue Q){
   return Q->node[Q->front].data;
}

void display(Queue Q){
    if(!isEmpty(Q)){
        int ctr = Q->front;
        printf("\nQUEUE:\t");
        while(ctr != -1){ // while we havent reached the end of the queue
            printf("%d\t", Q->node[ctr].data);
            ctr = Q->node[ctr].link;
        }
        printf("\n");
    }else{
        printf("\nQUEUE IS EMPTY!\n");
    }
}

#endif // !QUEUE_H