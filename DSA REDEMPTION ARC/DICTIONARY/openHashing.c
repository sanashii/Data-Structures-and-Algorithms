#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 10

typedef struct node{
    int data;
    struct node *link;
}*List;

typedef List Dict[MAX];

void initDict(Dict *D);
int Hash(int number);
void display(Dict D);
void insert(Dict *D, int num);
void delete(Dict *D, int num);
bool isMember(Dict D, int num);


int main(){
    Dict D;
    initDict(&D);
    int arr[] = {0, 13, 20, 28, 30, 33, 45, 48, 108}, ctr;
    for(ctr = 0; ctr < sizeof(arr) / 4; ctr++){
        insert(&D, arr[ctr]);
    }
    display(D);
    printf("\nisMember(11): %d", isMember(D, 11));
    printf("\nisMember(108): %d", isMember(D, 108));
    delete(&D, 20);
    delete(&D, 100);
    display(D);
}

void initDict(Dict *D){
    int ctr;
    for(ctr = 0; ctr < MAX; ctr++){
        (*D)[ctr] = NULL;
    }
}

int Hash(int num){
    return num % 10;
}

void display(Dict D){
    int ctr;
    List trav;
    for(ctr = 0; ctr < MAX; ctr++){
        printf("\nKey: %d\t->", ctr);
        for(trav = D[ctr]; trav != NULL; trav = trav->link){
            printf("\t%d\t->", trav->data);
        }
    }
    printf("\n");
}

void insert(Dict *D, int num){
    int ndx = Hash(num);
    List *trav, temp = (List)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->data = num;
        temp->link = NULL;
        for(trav = &(*D)[ndx]; *trav != NULL; trav = &(*trav)->link){}
        *trav = temp;
    }
}

void delete(Dict *D, int num){
    int ndx = Hash(num);
    List *trav, temp;
    for(trav = &(*D)[ndx]; *trav != NULL && (*trav)->data != num; trav = &(*trav)->link){}
    if(*trav == NULL){
        printf("\nELEMENT %d DOES NOT EXIST!\n", num);
    }else{
        temp = *trav;
        *trav = temp->link;
        free(temp);
    }
}

bool isMember(Dict D, int num){
    int ndx = Hash(num);
    List trav;
    for(trav = D[ndx]; trav != NULL && trav->data != num; trav = trav->link){}

    return(trav != NULL) ? true : false;
}
