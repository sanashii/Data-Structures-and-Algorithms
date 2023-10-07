#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct node{
    char data;
    int link;
}Nodes;

typedef struct{
    Nodes list[MAX];
    int avail;
}VirtualHeap;

typedef int LIST;

void initHeap(VirtualHeap *vh, LIST *A);

int main(){
    LIST L;
    VirtualHeap v;
    initHeap(&v, &L);
    return 0;
}

void initHeap(VirtualHeap *vh, LIST *A){
    int ctr;
    for(ctr = 0; ctr < MAX - 1; ctr++){
        vh->list[ctr].link = ctr + 1;
    }
    vh->list[ctr].link = -1;
    vh->avail = 0;
    *A = -1;
}