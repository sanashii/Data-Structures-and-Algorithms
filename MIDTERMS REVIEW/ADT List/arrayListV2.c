#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 10

typedef struct node{ // V2 -- a list pointer pointing to the structure where the array and list count is located
    int nums[SIZE];
    int count;
}*LIST;

void shift(int *a, int *b);
void display(LIST L);
void deleteFirst(LIST L);
void deleteLast(LIST L);
void insertFirst(LIST L, int value);
void insertLast(LIST L, int value);
void insertAtPos(LIST L, int pos, int value);
void deleteOccurances(LIST L, int value);
void insertSorted(LIST L, int value);
bool isMember(LIST L, int value);

int main(){
    LIST L = (LIST)malloc(sizeof(struct node)); // L is a pointer to the structer which contains the array and the count variable
    int ctr, ctr1 = 5;
    L->count = 0; // initializing the list to be empty
    for(ctr = 0; ctr < SIZE - 1; ctr++){
        L->nums[ctr] = ctr1;
        L->count++;
        ctr1 += 5;
    }

    printf("----- ORIGINAL LIST -----\n");
    display(L);

    printf("\n\n\n----- DELETE FIRST -----");
    printf("\nOriginal List: ");
    display(L);
    printf("\nList after deleting first element: ");
    deleteFirst(L);
    display(L);

    printf("\n\n\n----- DELETE LAST -----");
    printf("\nOriginal List: ");
    display(L);
    printf("\nList after deleting last element: ");
    deleteLast(L);
    display(L);

    printf("\n\n\n----- INSERT FIRST -----");
    printf("\nOriginal List: ");
    display(L);
    printf("\nList after inserting 7 at the beginning: ");
    insertFirst(L, 7);
    display(L);

    printf("\n\n\n----- INSERT LAST -----");
    printf("\nOriginal List: ");
    display(L);
    printf("\nList after inserting 77 at the end: ");
    insertLast(L, 77);
    display(L);

    printf("\n\n\n----- INSERT @ POSITION -----");
    printf("\nOriginal List: ");
    display(L);
    printf("\nList after adding 25 at index 3: ");
    insertAtPos(L, 3, 25);
    display(L);

    printf("\n\n\n----- DELETE ALL OCCURANCES -----");
    printf("\nOriginal List: ");
    display(L);
    printf("\nList after deleting all the occurances of 25: ");
    deleteOccurances(L, 25);
    display(L);

    printf("\n\n\n----- INSERT SORTED -----");
    printf("\nOriginal List: ");
    display(L);
    printf("\nList after inserting number 8: ");
    insertSorted(L, 8);
    display(L);

    printf("\n\n\n----- IS MEMBER (1 - true ; 0 - false) -----");
    printf("\nOriginal List: ");
    display(L);
    printf("\nIs the value of 2 a member of the list?: %d", isMember(L, 2));
    printf("\nIs the value of 10 a member of the list?: %d", isMember(L, 10));

    free(L);
    return 0;
}

void shift(int *a, int *b){
    *a = *b;
}

void display(LIST L){
    for(int ctr = 0; ctr < L->count; ctr++){
        printf("%d ", L->nums[ctr]);
    }
}

void deleteFirst(LIST L){
    for(int ctr = 0; ctr < L->count; ctr++){
        shift(&L->nums[ctr], &L->nums[ctr + 1]);
    }
    L->count--;
}

void deleteLast(LIST L){
    L->nums[L->count - 1] = 0;
    L->count--;
}

void insertFirst(LIST L, int value){
    if(L->count > SIZE){ // checking to see if you can add more elements to the list
        printf("\nList is full! Can no longer add more elements.");
        return;
    }

    for(int ctr = L->count; ctr > 0; ctr--){
        shift(&L->nums[ctr], &L->nums[ctr - 1]);
    }
    L->count++;
    L->nums[0] = value;
}

void insertLast(LIST L, int value){
    if(L->count > SIZE){ // checking to see if you can add more elements to the list
        printf("\nList is full! Can no longer add more elements.");
        return;
    }

    L->nums[L->count] = value;
    L->count++;
}

void insertAtPos(LIST L, int pos, int value){
    if(L->count > SIZE){
        printf("\nList is full! Can no longer add elements into the list.");
        return;
    }

    for(int ctr = L->count; ctr > pos; ctr--){
        shift(&L->nums[ctr], &L->nums[ctr - 1]);
    }
    L->nums[pos] = value;
    L->count++;
}

void deleteOccurances(LIST L, int value){
    for(int ctr = 0; ctr < L->count; ctr++){
        if(L->nums[ctr] == value){
            for(int ctr1 = ctr; ctr1 < L->count; ctr1++){
                shift(&L->nums[ctr1], &L->nums[ctr1 + 1]);
            }
            L->count--;
        }
    }
}

void insertSorted(LIST L, int value){
    if(L->count > SIZE){ // checking to see if you can add more elements to the list
        printf("\nList is full! Can no longer add more elements.");
        return;
    }
    for(int ctr = 0; ctr < L->count; ctr++){
        if(value > L->nums[ctr] || value < L->nums[ctr + 1] || value > L->nums[ctr] && value < L->nums[ctr + 1]){
            insertAtPos(L, ctr + 1, value);
        }
    }
    L->count++;
}

bool isMember(LIST L, int value){
    for(int ctr = 0; ctr < L->count - 1; ctr++){
        if(L->nums[ctr] == value){
            return true;
        }
    }

    return false;
}
