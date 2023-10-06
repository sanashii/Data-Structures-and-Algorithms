//* regular array within a structure program w/ shifting
#include <stdio.h>
#include <stdbool.h>
#define MAX 5

typedef struct{
    int arr[MAX];
    int front;
    int rear;
}Queue;

Queue initQueue(Queue Q);
void shift(int *a, int *b);
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

    return 0;
}

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
