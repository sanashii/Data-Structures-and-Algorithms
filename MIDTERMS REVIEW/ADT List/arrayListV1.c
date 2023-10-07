#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 10

typedef struct node{ // V1 -- this version is a list structure that consists of the array and the count of the elements
    int nums[SIZE];
    int count;
}LIST;

void printList(LIST L);
void removeElement(int index, LIST *L);
void shift(int *a, int *b);
void insertLast(int value, LIST *L);
void insertAtLocation(int value, int location, LIST *L);
void insertSorted(int value, LIST *L);
void deleteFirst(LIST *L);
void deleteLast(LIST *L);
void deleteOccur(LIST *L, int value);
bool isMember(LIST L, int value);

int main(){
    LIST L;
    L.count = 0; // initializing the list to be empty
    for(int ctr = 0; ctr < SIZE - 1; ctr++){ // filling the list with values
        L.nums[ctr] = ctr + 1;
        L.count++;
    }
    printf("----- ORIGINAL LIST -----");
    printList(L);

    printf("\n\n----- LIST AFTER REMOVING ELEMENT @ INDEX 2 -----");
    removeElement(2, &L);
    printList(L);

    printf("\n\n----- LIST AFTER APPENDING @ SPECIFIC LOCATION -----");
    insertAtLocation(17, 4, &L);
    printList(L);

    printf("\n\n----- LIST AFTER DELETING FIRST ELEMENT -----");
    deleteFirst(&L);
    printList(L);

    printf("\n\n----- LIST AFTER DELETING LAST ELEMENT -----");
    deleteLast(&L);
    printList(L);

    printf("\n\n----- LIST AFTER APPENDING AT THE END OF THE LIST -----");
    insertLast(17, &L);
    printList(L);

    printf("\n\n----- LIST MEMBER CHECK (0 - false ; 1 - true) -----");
    bool check = isMember(L, 10);
    printf("\nIs 10 a member of the list?: %d", check);
    check = isMember(L, 2);
    printf("\nIs 2 a member of the list?: %d", check);

    printf("\n\n----- LIST AFTER DELETING ALL OCCURANCES OF A NUMBER -----");
    printf("\nORIGINAL LIST: ");
    for(int ctr = 0; ctr < L.count; ctr++){
        printf("%d ", L.nums[ctr]);
    }
    printf("\n");
    deleteOccur(&L, 17);
    printList(L);

    printf("\n\n------ LIST AFTER INSERT SORTED OPERATION -----");
    printf("\nValue to be inserted: 5");
    insertSorted(5, &L);
    printList(L);
    

    return 0;
}

void shift(int *a, int *b){
    *a = *b;
}

void printList(LIST L){
    printf("\nLIST CONTENTS AFTER OPERATION: ");
    for(int ctr = 0; ctr < L.count; ctr++){
        printf("%d ", L.nums[ctr]);
    }
    printf("\n");
}

void removeElement(int index, LIST *L){
    for(int ctr = index; ctr < L->count; ctr++){
        shift(&L->nums[ctr], &L->nums[ctr + 1]);
    }
    L->count--;
}

void insertLast(int value, LIST *L){
    L->nums[L->count] = value;
    L->count++;
}

void insertAtLocation(int value, int location, LIST *L){
    for(int ctr = L->count; ctr > location; ctr--){
       shift(&L->nums[ctr], &L->nums[ctr - 1]);
    }
    L->nums[location] = value;
    L->count++;
}

void deleteFirst(LIST *L){
    for(int ctr = 0; ctr < L->count; ctr++){
        shift(&L->nums[ctr], &L->nums[ctr + 1]);
    }
    L->count--;
}

void deleteLast(LIST *L){
    L->nums[L->count] = 0; // making it zero para deleted jd siya or like way value
    L->count--;
}

bool isMember(LIST L, int value){
    for(int ctr = 0; ctr < L.count; ctr++){
        if(L.nums[ctr] == value){
            return true;
        }
    }
    return false;
}

void deleteOccur(LIST *L, int value){
    int ctr1 = 0;
    for(int ctr = 0; ctr < L->count; ctr++){
        if(L->nums[ctr] == value){
            for(ctr1 = ctr; ctr1 < L->count; ctr1++){
                shift(&L->nums[ctr1], &L->nums[ctr1 + 1]);
            }
            L->count--;
        }
    }
}

void insertSorted(int value, LIST *L){ 
    for(int ctr = L->count; ctr > 0; ctr--){
        if(value <= L->nums[ctr] || value >= L->nums[ctr - 1] || value <= L->nums[ctr] && value >= L->nums[ctr - 1]){
            insertAtLocation(value, ctr, L);
            break;
        }
    }
}