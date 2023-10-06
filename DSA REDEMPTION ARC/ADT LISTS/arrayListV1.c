#include<stdio.h>
#define MAX 5

typedef struct{
    char elem[MAX];
    int count;
}LIST;

void initList(LIST *L);
void addElement(LIST *L, char c);
void deleteOccurances(LIST *L, char c);
void shift(char *a, char *b);
void printList(LIST L);

int main(){
    LIST L;
    initList(&L);
    addElement(&L, 'I');
    addElement(&L, 'U');
    addElement(&L, 'B');
    addElement(&L, 'A');
    addElement(&L, 'B');
    printf("List before deleting the occurances of 'B':\n");
    printList(L);
    printf("\n\nList after deleting the occurances of 'B':\n");
    deleteOccurances(&L, 'B');
    printList(L);

    return 0;
}

void initList(LIST *L){
    L->count = 0;
}

void addElement(LIST *L, char c){
    if(L->count < MAX){
        L->elem[L->count] = c;
        L->count++;
    }else{
        printf("\nLIST IS FULL!");
    }
}

void deleteOccurances(LIST *L, char c){
    int ctr;
    for(ctr = 0; ctr < L->count; ctr++){
        if(L->elem[ctr] == c){
            for(int ctr1 = ctr; ctr1 < L->count; ctr1++){
                shift(&L->elem[ctr1], &L->elem[ctr1 + 1]);
            }
            L->count--;
            ctr--;
        }
    }
}

void shift(char *a, char *b){
    *a = *b;
}

void printList(LIST L){
    int ctr;
    for(ctr = 0; ctr < L.count; ctr++){
        printf("%c\n", L.elem[ctr]);
    }
}