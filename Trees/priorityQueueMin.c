#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 15

typedef struct node{
    int elem[MAX];
    int lastIndex;
}HEAP;

int findSize(HEAP H);
void heapify(HEAP *Hptr);
void deleteMin(HEAP *Hptr);
void displayHeap(HEAP H);
void insert(HEAP *Hptr, int data);

int main(){
    HEAP H;
    int temp[MAX] = {-1, 3, 4, 9, 6, 5, 9, 10, 10, 18, 7}; // -1 is a sentinel value indicating that 3 is the main root atm
    memcpy(H.elem, temp, sizeof(temp));
    int size = findSize(H);
    H.lastIndex = size - 1;
    printf("-----------------------------------------------------");
    printf("\nORIGINAL HEAP: "); displayHeap(H);
    printf("\n-----------------------------------------------------");
    printf("\nHEAP AFTER HEAPIFYING: "); heapify(&H); display(H);
    printf("\n-----------------------------------------------------");
    printf("\nHEAP AFTER DELETING THE ORIGINAL MINIMUM: "); deleteMin(&H);
    printf("\nHEAP AFTER DELETING THE NEW MINIMUM: "); deleteMin(&H);
    printf("\n-----------------------------------------------------");
    printf("\nINSERTING 20: "); insert(&H, 20); display(H);
    printf("\nINSERTING 2: "); insert(&H, 2); display(H);

    return 0;
}

int findSize(HEAP H){
    int ctr;
    for(ctr = 0; ctr < sizeof(H.elem)/4 && H.elem[ctr] != 0; ctr++){}
    return ctr;
}


void heapify(HEAP *Hptr){
    // still have to figure out the logic on how to find out is the index has a child
    int ctr, flag = 1;
    while(flag){
        flag = 0;
        for(ctr = *Hptr.lastIndex; ctr > 0; ctr--){
            if(ctr * 2 <= *Hptr->lastIndex){

            }
        }
    }
}

void deleteMin(HEAP *Hptr){
    int temp = *Hptr.elem[*sizeptr - 1];
    Hptr->elem[Hptr->lastIndex] = *Hptr.elem[1];
    Hptr->lastIndex -= 1

    heapify(Hptr);
}

void displayHeap(HEAP H){
    for(int ctr = 1; ctr <= H.lastIndex; ctr++)
        printf("%d ", H.elem[ctr]);
}

void insert(HEAP *Hptr, int data){
    // after inferting kay we need to heapify
}