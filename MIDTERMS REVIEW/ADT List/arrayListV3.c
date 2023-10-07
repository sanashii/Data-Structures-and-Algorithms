#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define SIZE 10

typedef struct node{
    int *element;
    int count;
}LIST;

void shift(int *a, int *b);
void display(LIST L);
void deleteFirst(LIST *L);
void deleteLast(LIST *L);
void insertFirst(LIST *L, int value);
void insertLast(LIST *L, int value);
void insertAtPos(LIST *L, int value, int pos);
void insertSorted(LIST *L, int value);
void deleteOccur(LIST *L, int value);
bool isMember(LIST L, int value);

int main(){
    LIST L;
    L.count = 0; //! always initialize list to be empty at first jd
    int *nums = (int *)malloc(sizeof(int) * SIZE); // dynamically allocated array that holds a max of 10 elements
    int val = 10;
    for(int ctr = 0; ctr < SIZE - 1; ctr++){ // filling the array with values
        nums[ctr] = val;
        L.count++;
        val += 10;
    }
    L.element = nums; // letting the array pointer of L point to the array

    printf("----- ORIGINAL LIST -----");
    printf("\nOriginal List: ");
    display(L);

    printf("\n\n\n----- DELETING FIRST ELEMENT -----");
    printf("\nOriginal List: ");
    display(L);
    printf("\n\nList after deleting the first element: ");
    deleteFirst(&L);
    display(L);

    printf("\n\n\n----- DELETING LAST ELEMENT -----");
    printf("\nOriginal List: ");
    display(L);
    printf("\n\nList after deleting the last element: ");
    deleteLast(&L);
    display(L);

    printf("\n\n\n----- INSERT FIRST -----");
    printf("\nOriginal List: ");
    display(L);
    printf("\n\nList after inserting | 7 | in the beginning: ");
    insertFirst(&L, 7);
    display(L);

    printf("\n\n\n----- INSERT LAST -----");
    printf("\nOriginal List: ");;
    display(L);
    printf("\nList after inserting | 7 | at the end: ");
    insertLast(&L, 7);
    display(L);

    printf("\n\n\n----- INSERT SORTED -----");
    printf("\nOriginal List: ");;
    display(L);
    printf("\nList after inserting | 15 | in the list (sorted): ");
    insertSorted(&L, 15);
    display(L);

    printf("\n\n\n----- DELETING ALL OCCURANCES -----");
    printf("\nOriginal List: ");;
    display(L);
    printf("\nList after deleting the ocurances of | 7 |: ");
    deleteOccur(&L, 7);
    display(L);

    printf("\n\n\n----- IS MEMBER (1 - True ; 0 -False) -----");
    printf("\nOriginal List: ");
    display(L);
    printf("\n\nIs 15 a member of the list?: %d", isMember(L, 15));
    printf("\nIs 2 a memebr of the list?: %d", isMember(L, 2));

    free(nums);
    return 0;
}

void shift(int *a, int *b){
    *a = *b;
}

void display(LIST L){
    for(int ctr = 0; ctr < L.count; ctr++){
        printf("%d ", L.element[ctr]);
    }
}

void deleteFirst(LIST *L){
    L->element[0] = 0;
    for(int ctr = 0; ctr < L->count - 1; ctr++){
        shift(&L->element[ctr], &L->element[ctr + 1]);
    }
    L->element[L->count - 1] = 0; // set the empty to 0 since wa na siyay gamit
    L->count--;
}

void deleteLast(LIST *L){
    L->element[L->count - 1] = 0;
    L->count--;
}

void insertFirst(LIST *L, int value){
    if(L->count > SIZE){
        printf("\nList is full! Can no longer add elements.\nMemory reallocation is needed.");
        return;
    }
    for(int ctr = L->count; ctr > 0; ctr--){
        shift(&L->element[ctr], &L->element[ctr - 1]);
    }
    L->element[0] = value;
    L->count++;
}

void insertLast(LIST *L, int value){
    if(L->count > SIZE){
        printf("\nList is full! Can no longer add elements.\nMemory reallocation is needed.");
        return;
    }
    L->element[L->count] = value;
    L->count++;
}

void insertAtPos(LIST *L, int value, int pos){ //! UNUSED but works
     if(L->count > SIZE){
        printf("\nList is full! Can no longer add elements.\nMemory reallocation is needed.");
        return;
    }
    for(int ctr = L->count; ctr >= pos; ctr--){
        shift(&L->element[ctr], &L->element[ctr - 1]);
    }
    L->element[pos] = value;
    L->count++;
}

void insertSorted(LIST *L, int value){ // different implementation
    int pos = 0;
    while(pos < L->count && L->element[pos] < value){
        pos++;
    }
    for(int ctr = L->count; ctr >=pos; ctr--){
        shift(&L->element[ctr], &L->element[ctr - 1]);
    }

    L->element[pos] = value;
    L->count++;
}

void deleteOccur(LIST *L, int value){
    for(int ctr = 0; ctr < L->count; ctr++){
        if(L->element[ctr] == value){
            L->element[ctr] = 0;
            for(int ctr1 = ctr; ctr1 < L->count; ctr1++){
                shift(&L->element[ctr1], &L->element[ctr1 + 1]);
            }
            L->count--;
        }
    }
}

bool isMember(LIST L, int value){
    for(int ctr = 0; ctr < L.count; ctr++){
        if(L.element[ctr] == value){
            return true;
        }
    }
    return false;
}