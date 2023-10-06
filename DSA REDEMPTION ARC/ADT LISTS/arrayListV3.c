#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct{
    int *elemptr;
    int count;
}ArrayList;

ArrayList initList(ArrayList L);

int main(){
    ArrayList L = initList(L);

    return 0;
}

ArrayList initList(ArrayList L){
    L.count = 0;
    L.elemptr = (int)calloc(MAX, sizeof(int));

    return L;
}