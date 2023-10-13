#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 10

typedef int* SET; // making the SET dt a pointer so that our array will be in the heap for the operations to properly return the values

void initialize(SET *S);
void display(SET S);
void insert(SET *S, int elem);
bool isMember(SET S);
void delete(SET *S, int elem);
SET union(SET A, SET B);
SET intersection(SET A, SET B);
SET difference(SET A, SET B);
bool isSubset(SET A, SET B);
SET complement(SET S);

int main(){
    SET U = (SET)malloc(sizeof(int) * MAX), A, B, C;
    S[] = {3, 7, 0, 4, 9};
    initialize(&A);
    initialize(&B);
    initialize(&C);

    return 0;
}

void initialize(SET *S){
    *S = (SET)malloc(sizeof(int) * MAX);
}

void display(SET S);
void insert(SET *S, int elem);
bool isMember(SET S);
void delete(SET *S, int elem);
SET union(SET A, SET B);
SET intersection(SET A, SET B);
SET difference(SET A, SET B);
bool isSubset(SET A, SET B);
SET complement(SET S);