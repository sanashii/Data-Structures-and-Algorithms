#include<stdio.h>
#include<stdbool.h>
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

Queue initQueue(Queue Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue *Q, int elem);
void dequeue(Queue *Q);
int front(Queue Q);
void display(Queue Q);

int main(){
    Queue Q = initQueue(Q);
    enqueue(&Q, 7);
    enqueue(&Q, 12);
    enqueue(&Q, 4);
    enqueue(&Q, 0);
    printf("Current front: %d\n", front(Q));
    display(Q);
    enqueue(&Q, 16);
    display(Q);
    enqueue(&Q, 9);
    dequeue(&Q);
    dequeue(&Q);
    display(Q);
    printf("Current front: %d\n", front(Q));
    enqueue(&Q, 9);
    display(Q);
    dequeue(&Q);
    display(Q);
    enqueue(&Q, 1);
    enqueue(&Q, 5);
    display(Q);
    return 0;
}

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
