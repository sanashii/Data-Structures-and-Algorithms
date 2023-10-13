//! VARIATION 1
#include<stdio.h>
#include<stdbool.h>
#define MAX 20
#define EMPTY '#'
#define DELETED '-'

typedef struct{
    char arr[MAX];
    int last;
}Dict;

void initDict(Dict *D);
int Hash(char c);
void display(Dict D);
void insert(Dict *D, char elem);
void delete(Dict *D, char elem);
bool isMember(Dict D, char elem);

int main(){
    Dict D;
    initDict(&D);
    insert(&D, 'a');
    insert(&D, 't');
    insert(&D, 's');
    insert(&D, 'b');
    insert(&D, 'q');
    insert(&D, 'v');
    insert(&D, 'k');
    insert(&D, 'j');
    // insert(&D, 'a'); // testing to see if synonym insertion works -- WORKS
    display(D);

    delete(&D, 'v');
    delete(&D, 's');

    display(D);

    printf("\nisMember(a): %d", isMember(D, 'a'));
    printf("\nisMember(a): %d", isMember(D, 's'));
    
    return 0;
}

void initDict(Dict *D){
    int ctr;
    for(ctr = 0; ctr < MAX/2; ctr++){
        D->arr[ctr] = EMPTY;
    }
    D->last = (MAX/2) - 1;
}

int Hash(char c){
    return (c - '0') % 10;
}

void display(Dict D){
    int ctr, sumSL = 0;
    printf("\nELEMENT\t\tHASH VAL\tSEARCH LENGTH\n");
    for(ctr = 0; ctr <= D.last; ctr++){
        if(D.arr[ctr] != EMPTY || D.arr[ctr] != DELETED){
            sumSL += ctr - (Hash(D.arr[ctr]) + 1);
            printf("%c\t\t%d\t\t%d\n", D.arr[ctr], Hash(D.arr[ctr]), ctr - Hash(D.arr[ctr]) + 1);
        }
    }
    printf("\nAVERAGE SEARCH LENGTH: %d", sumSL/MAX);
}

void insert(Dict *D, char elem){ //! how will we know if its already full???
    int ndx = Hash(elem);
    if(D->arr[ndx] == EMPTY){ // meaning prime data index isnt occupied pa
        D->arr[ndx] = elem;
    }else{
        D->arr[++D->last] = elem;
    }
}

void delete(Dict *D, char elem){ // search at the prime data area then go to the synonyms if ever wa a find
    int ndx = Hash(elem), ctr;
    if(D->arr[ndx] == elem){
        D->arr[ndx] = DELETED;
    }else{
        for(ctr = (MAX/2) + 1; ctr < MAX && D->arr[ctr] != elem; ctr++){} // traverses through the synonym area
        if(ctr == MAX){
            printf("\nELEMENT NOT FOUND!");
        }else{ // element has been found
            D->arr[ctr] = DELETED;
            D->arr[ctr] = D->arr[D->last];
            D->last--;
        }
    }
    
}

bool isMember(Dict D, char elem){
    int ndx = Hash(elem), ctr;
    bool retVal = true;
    if(D.arr[ndx] == elem){
        retVal = true;
    }else{
        for(ctr = MAX/2; ctr < MAX && D.arr[ctr] != elem; ctr++){}
        if(ctr == MAX){
            retVal = false;
        }
    }
    return retVal;
}