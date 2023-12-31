#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#ifndef QUEUE_H
#define QUEUE_H

// O(1) run time for operations
// AND with doubly linked list, bidirectional traversal is possible

typedef struct node{
    struct node* prev;
    int data;
    struct node* next;
}*Queue;

Queue initQueue(Queue Q){
    return Q = NULL;
}

bool isEmpty(Queue Q){
    return(Q == NULL) ? true : false;
}

void enqueue(Queue *Q, int elem){
    Queue temp = (Queue)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->prev = temp;
        temp->data = elem;
        temp->next = temp;
        if(isEmpty(*Q)){
            *Q = temp;
        }else{
            (*Q)->prev->next = temp; // lets the rear node point to the new rear node for linking
            temp->next = (*Q); // lets the rear node point to the front node
            temp->prev = (*Q)->prev;
            (*Q)->prev = temp;
        }
    }
}

void dequeue(Queue *Q){
    Queue temp = *Q;
    *Q = temp->next; // *Q now points to the new front
    (*Q)->prev = temp->prev; // lets the new front point to the rear via the temp/old front
    temp->prev->next = *Q; // lets the rear point to the new front
    free(temp);
}

int front(Queue Q){
    return Q->data;
}

void display(Queue Q){
    Queue trav = Q; //pointer to node since we're just displaying
    printf("\nQUEUE:\t");
    do {
        printf("%d\t", trav->data);
        trav = trav->next;
    } while (trav != Q); // the condition require that trav (trav->next) shouldn't be pointing to Q (front) since this is a circular LL
    printf("\n");
}

#endif // !QUEUE_H