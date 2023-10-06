#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct node{
    int elem[10];
    int count;
}*ArrayList;

void initList(ArrayList *L);

int main(){
    ArrayList L;
    initList(&L);

    return 0;
}

ArrayList initList(ArrayList L){
    ArrayList temp = (ArrayList)malloc(sizeof(struct node));
    L = temp;
    L->count = 0;
    return L;     
}