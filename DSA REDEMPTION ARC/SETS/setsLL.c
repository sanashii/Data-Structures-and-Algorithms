// 2 variations for array -- (1) w/ ctr field & (2) regular array w/ index 0 storing the number of active elements which start at index 1 
// initialize
// display
// insert
// isMember
// delete
// union (given 2 sets)
// intersection (given 2 sets)
// difference (given 2 sets)
// isSubset (given 2 sets)
// complement (for bit-vector & computer word only)

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
// no MAX since its linked list (?)

typedef struct cell{
    int data;
    struct cell * link;
}*SET;

SET initSet(SET S);
void displaySet(SET S);
void insertFirst(SET *S, int elem);
bool isMember(SET S, int elem);
void delete(SET *S, int elem);
SET setUnion(SET A, SET B); // return SET C which points to the union set found in the heap -- unsorted
SET setIntersection(SET A, SET B); // return SET C which points to the intersection set found in the heap
SET setDifference(SET A, SET B); // return SET C which points to the set of the set difference of A and B
bool isSubset(SET A, SET B); // returns TRUE if B is a subset of A

int main(){
    SET U = initSet(U), A = initSet(A), B = initSet(B), C = initSet(C); // set operations to be done on sets A and B, C is the catcher for the results
    // populating universal set and checking functions
    insertFirst(&U, 2);
    insertFirst(&U, 7);
    insertFirst(&U, 6);
    insertFirst(&U, 9);
    insertFirst(&U, 4);
    insertFirst(&U, 8);
    insertFirst(&U, 1);
    printf("SET U:\t");
    displaySet(U);
    printf("\nisMember(3): %d", isMember(U, 3));
    printf("\nisMember(1): %d", isMember(U, 1));
    delete(&U, 5);
    delete(&U, 9);
    printf("\nSET U:\t");
    displaySet(U);

    // Set Operations on SET A & B
    insertFirst(&A, 8);
    insertFirst(&A, 3);
    insertFirst(&A, 4);
    insertFirst(&A, 0);

    insertFirst(&B, 4);
    insertFirst(&B, 2);
    insertFirst(&B, 1);
    insertFirst(&B, 2);
    insertFirst(&B, 9);
    insertFirst(&B, 0);

    printf("\n\nSET A:\t");
    displaySet(A);
    printf("\nSET B:\t");
    displaySet(B);

    C = setUnion(A, B);
    printf("\nA UNION B:\t");
    displaySet(C);
    C = NULL; // setting C back to NULL to reuse it for another operation
    C = setIntersection(A, B);
    printf("\nA INTERSECTION B:\t");
    displaySet(C);
    C = NULL;
    C = setDifference(A, B);
    printf("\nA - B:\t");
    displaySet(C);
    printf("\nisSubset(A, B): %d", isSubset(A, B)); // false
    printf("\nisSubset(A, C): %d", isSubset(A, C)); // true

    return 0;
}

SET initSet(SET S){
    S = NULL;
    return S;
}

void displaySet(SET S){
    for(SET trav = S; trav != NULL; trav = trav->link){
        printf("%d\t", trav->data);
    }
}

void insertFirst(SET *S, int elem){
    SET temp = (SET)malloc(sizeof(struct cell));
    temp->data = elem;
    temp->link = NULL;
    if(*S == NULL){
        *S = temp;
    }else{
        temp->link = *S;
        *S = temp;
    }
}

bool isMember(SET S, int elem){
    SET trav;
    for(trav = S; trav != NULL && trav->data != elem; trav = trav->link){}
    return(trav != NULL) ? true : false;
}

void delete(SET *S, int elem){
    SET *trav;
    for(trav = S; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->link){}
    if(*trav != NULL){
        SET temp = *trav;
        *trav = temp->link;
        free(temp);
    }else{
        printf("\nELEMENT '%d' DOES NOT EXIST!\n", elem);
    }
}

SET setUnion(SET A, SET B){ // return SET C which points to the union set found in the heap -- unsorted
    SET C = initSet(C), aptr = A, bptr = B, *cptr = &C;
    while(aptr != NULL && bptr != NULL){
        // copy small elements from either A or B and place to C
        *cptr = (SET)malloc(sizeof(struct cell));
        if(aptr->data < bptr->data){
            (*cptr)->data = aptr->data;
            aptr = aptr->link;
        }else{
            if(aptr->data == bptr->data){
                aptr = aptr->link;
            }
            (*cptr)->data = bptr->data;
            bptr = bptr->link;
        }
        cptr = &(*cptr)->link;
    }
    // copy remaining elements
    if(bptr != NULL){
        aptr = bptr;
    }
    while(aptr != NULL){
        *cptr = (SET)malloc(sizeof(struct cell));
        (*cptr)->data = aptr->data;
        aptr = aptr->link;
        cptr = &(*cptr)->link;
    }
    *cptr = NULL;

    return C;
}

SET setIntersection(SET A, SET B) { 
// not efficient but works since it starts with aptr's 1st elem then traverses bptr before moving aptr to the next then traversing bptr again
    SET C = initSet(C), aptr, bptr, *cptr = &C;
    for(aptr = A; aptr != NULL; aptr = aptr->link){
        for(bptr = B; bptr != NULL && bptr->data != aptr->data; bptr = bptr->link){} 
        //* improved by letting bptr stop if it has found a match & 
        //* no need for traversing up to the end even if nay match
        if(bptr != NULL){ 
            *cptr = (SET)malloc(sizeof(struct cell));
            (*cptr)->data = aptr->data;
            (*cptr)->link = NULL;
            cptr = &(*cptr)->link;
        }
    }
    *cptr = NULL;

    return C;
}

SET setDifference(SET A, SET B){  // return SET C which points to the set of the set difference of A and B (is in A but not in B)
    SET C = initSet(C), aptr, bptr, *cptr = &C;
    for(aptr = A; aptr != NULL; aptr = aptr->link){
        for(bptr = B; bptr != NULL && bptr->data != aptr->data; bptr = bptr->link){}
        if(bptr == NULL){
            *cptr = (SET)malloc(sizeof(struct cell));
            (*cptr)->data = aptr->data;
            (*cptr)->link = NULL;
            cptr = &(*cptr)->link; //! NOTE: remember to make it NULL otherwise the display wont work
        }
    }
    return C;
}

bool isSubset(SET A, SET B){ // returns TRUE if B is a subset of A
    bool retVal = true;
    SET C = initSet(C), aptr, bptr, *cptr = &C;
    for(bptr = B; bptr != NULL; bptr = bptr->link){
        for(aptr = A; aptr != NULL && aptr->data != bptr->data; aptr = aptr->link){}
        if(aptr == NULL){
            retVal = false;
        }
    }
    return retVal;
} 