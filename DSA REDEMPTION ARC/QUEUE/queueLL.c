#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// O(1) run time for operations
// AND with doubly linked list, bidirectional traversal is possible

typedef struct node{
    struct node* prev;
    int data;
    struct node* next;
}*Queue;

Queue initQueue(Queue Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue *Q, int elem);
void dequeue(Queue *Q);
int front(Queue Q);
void display(Queue Q);

int main(){
    Queue Q = initQueue(Q);

    return 0;
}

Queue initQueue(Queue Q){
    return Q = NULL;
}

bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue *Q, int elem);
void dequeue(Queue *Q);
int front(Queue Q);
void display(Queue Q);