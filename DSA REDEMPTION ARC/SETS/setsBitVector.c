#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 10

typedef int* SET; // making the SET dt a pointer so that our array will be in the heap for the operations to properly return the values

void initialize(SET *S);
void display(SET S);
void createBitSet(SET *S, int elem); // basically insertions
bool isMember(SET S);
void delete(SET *S, int elem);
SET setUnion(SET A, SET B);
SET intersection(SET A, SET B);
SET difference(SET A, SET B);
bool isSubset(SET A, SET B);
SET complement(SET S);

int main(){
    SET U, A, B, C;
    initialize(&U);
    initialize(&A);
    initialize(&B);
    initialize(&C);
    U[0] = 3;
    U[1] = 7;
    U[2] = 0;
    U[3] = 4;
    U[4] = 9;

    return 0;
}

void initialize(SET *S){
    *S = (SET)malloc(sizeof(int) * MAX);
}

void display(SET S);

void createBitSet(SET *S, int elem){ // basically insertions

} 

bool isMember(SET S);

void delete(SET *S, int elem);

SET setUnion(SET A, SET B);

SET intersection(SET A, SET B);

SET difference(SET A, SET B);

bool isSubset(SET A, SET B);

SET complement(SET S);