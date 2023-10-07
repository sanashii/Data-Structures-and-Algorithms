#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define SIZE 10

typedef struct node{
    int *element;
    int count;
}*LIST;

void shift(int *a, int *b);
void display(LIST L);
void insertFirst(LIST *L, int value);
void deleteFirst(LIST *L);
void deleteLast(LIST *L);
void insertLast(LIST *L, int value);
void insertAtPos(LIST *L, int pos, int value);
void insertSorted(LIST *L, int value);
void deleteOccur(LIST *L, int value);
bool isMember(LIST *L, int value);

int main(){
    LIST L = (LIST)malloc(sizeof(struct node)); // dynamically allocate memory for LIST type
    int *nums = (int *)malloc(sizeof(int) * SIZE); // dynamically allocated array that holds a max of 10 elements
    int val = 2;
    // we use `->` since L is a pointer to the structure that hold the element pointer variable (to the nums array) & the count variable
    L->element = nums;
    L->count = 0; // initializing the list count to be 0 through the pointer L

    for(int ctr = 0; ctr < SIZE; ctr++){ // filling the array with values
        nums[ctr] = val;
        L->count++;
        val += 2;
    }

    printf("----- DISPLAYING LIST -----");
    printf("\nOriginal List: ");
    display(L);

    printf("\n\n\n----- INSERT FIRST -----");
    printf("\nOriginal List: ");
    display(L);
    printf("\n\nList after inserting | 5 | in the beginning:\n");
    insertFirst(&L, 5);
    display(L);

    printf("\n\n\n----- DELETE FIRST -----");
    printf("\nOriginal List: ");
    display(L);
    printf("\n\nList after deleting the first element: ");
    deleteFirst(&L);
    display(L);

    printf("\n\n\n----- DELETE LAST -----");
    printf("\nOriginal List: ");
    display(L);
    printf("\n\nList after deleting the last element: ");
    deleteLast(&L);
    display(L);

    printf("\n\n\n----- INSERT FIRST ----- ");
    printf("\nOriginal List: ");
    display(L);
    printf("\n\nList after inserting | 1 | at the beginning of the list: ");
    insertFirst(&L, 1);
    display(L);

    printf("\n\n\n----- INSERT LAST ----- ");
    printf("\nOriginal List: ");
    display(L);
    printf("\n\nList after inserting | 7 | at the end of the list: ");
    insertLast(&L, 7);
    display(L);

    printf("\n\n\n----- INSERT SORTED ----");
    printf("\nOriginal List: ");
    display(L);
    printf("\n\nList after inserting | 7 | in a sorted manner: ");
    insertSorted(&L, 7);
    display(L);

    printf("\n\n\n----- DELETE ALL OCCURANCES -----");
    printf("\nOriginal List: ");
    display(L);
    printf("\n\nList after deleting all occurances oof | 7 |: ");
    deleteOccur(&L, 7);
    display(L);

    printf("\n\n\n----- IS MEMBER (1 - true ; 0 - false) -----");
    printf("\nOriginal List: ");
    display(L);
    printf("\nIs | 5 | a member of the list?: %d", isMember(&L, 5));
    printf("\nIs | 16 | a member of the list?: %d", isMember(&L, 16));


    free(nums); // free dynamically allocated memory
    free(L);

    return 0;
}

void shift(int *a, int *b){
    *a = *b;
}

void display(LIST L){
    // we only pass L & not *L since we aren't changing anything in the main function
    for(int ctr = 0; ctr < L->count; ctr++){
        printf("%d ", L->element[ctr]); // unlike V3, we use `->` instead of `.` since LIST L is a pointer to a structure & we passed `LIST L`, not `LIST *L`
    }
}

void deleteFirst(LIST *L){
    // dereferencing is needed since we are updating the variables in main and the return type is void
    // (*L) - `*` used to get the value of the pointer in main, and since `L` in this function is a pointer to the pointer `L` in main, we need to use `(* )`
    // to get the actual LIST type variable (LIST L in main)
    (*L)->element[0] = 0; 
    for(int ctr = 0; ctr < (*L)->count - 1; ctr++){
        shift(&(*L)->element[ctr], &(*L)->element[ctr + 1]); // the address of the dereferenced value would be directly pointing at the elements in nums array
    }
    (*L)->count--;
}

void deleteLast(LIST *L){
    (*L)->element[(*L)->count - 1] = 0;
    (*L)->count--;
}

void insertFirst(LIST *L, int value){
    if((*L)->count >= SIZE){
        printf("\nList is full! Reallocating the array size...\n");
        (*L)->element = realloc((*L)->element, (SIZE + 1) * sizeof(int)); // reallocating space of the array nums using the pointer to a pointer variable
        printf("\nSuccessfully realocated memory for the original array.\n");
    }

    for(int ctr = (*L)->count; ctr > 0; ctr--){
        shift(&(*L)->element[ctr], &(*L)->element[ctr - 1]);
    }
    (*L)->element[0] = value;
    (*L)->count++;
}

void insertLast(LIST *L, int value){
    if((*L)->count >= SIZE){
        printf("\nList is full! Reallocating the array size...\n");
        (*L)->element = realloc((*L)->element, (SIZE + 1) * sizeof(int));
        printf("\nSuccessfully realocated memory for the original array.\n");
    }
    (*L)->element[(*L)->count] = value;
    (*L)->count++;
}

void insertAtPos(LIST *L, int pos, int value){ //! UNUSED but works
    for(int ctr = (*L)->count; ctr >= pos; ctr--){
        shift(&(*L)->element[ctr], &(*L)->element[ctr - 1]);
    }
    (*L)->element[pos] = value;
    (*L)->count++;
}

void insertSorted(LIST *L, int value){ // different implementation from V1,2,3 since that V doesnt work for this one idk why pa 
    if((*L)->count >= SIZE){
        printf("\nList is full! Reallocating the array size...\n");
        (*L)->element = realloc((*L)->element, (SIZE + 1) * sizeof(int));
        printf("\nSuccessfully realocated memory for the original array.\n");
    }

    int pos = 0;
    while (pos < (*L)->count && (*L)->element[pos] < value) { // traverse through the list to find the index of the element that is larger than the value
        pos++;
    }

    for (int ctr = (*L)->count; ctr > pos; ctr--) {
        shift(&(*L)->element[ctr], &(*L)->element[ctr - 1]);
    }
    (*L)->element[pos] = value;
    (*L)->count++;
}

void deleteOccur(LIST *L, int value){
    for(int ctr = 0; ctr < (*L)->count; ctr++){
        if((*L)->element[ctr] == value){
            (*L)->element[ctr] = 0;
            for(int ctr1 = ctr; ctr1 < (*L)->count; ctr1++){
                shift(&(*L)->element[ctr1], &(*L)->element[ctr1 + 1]);
            }
            (*L)->count--;
        }
    }
}

bool isMember(LIST *L, int value){
    for(int ctr = 0; ctr < (*L)->count; ctr++){
        if((*L)->element[ctr] == value)
            return true;
    }
    return false;
}