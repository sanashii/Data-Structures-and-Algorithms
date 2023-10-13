//! VARIATION 2
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define EMPTY '#'
#define DELETED '-'
#define MAX 20

typedef struct node{
    char data;
    int link;
}Nodes;

typedef struct cell{
    Nodes node[MAX];
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

    display(D);

    delete(&D, 'v');
    delete(&D, 's');

    display(D);

    printf("\nisMember(a): %d", isMember(D, 'a'));
    printf("\nisMember(s): %d", isMember(D, 's'));

    return 0;
}

void initDict(Dict *D){
    int ctr;
    for(ctr = 0; ctr < MAX/2; ctr++){
        D->node[ctr].data = EMPTY;
    }
    D->last = (MAX/2) - 1;
}

int Hash(char c){
    return (c - '0') % 10;
}

void display(Dict D){
    int ctr;
    printf("\nKEY\tVALUES\n");
    for (ctr = 0; ctr < MAX / 2; ctr++) {
        printf(" %d\t", ctr); // prints the key/index
        if (D.node[ctr].data == EMPTY) {
            printf("EMPTY\n");
        } else {
            int ctr1 = ctr;
            while (ctr1 != -1) { // prints the synonyms if naa
                printf("%c -> ", D.node[ctr1].data);
                ctr1 = D.node[ctr1].link;
            }
            printf("NULL\n");
        }
    }
}


void insert(Dict *D, char elem){
    int ndx = Hash(elem);
    if(D->node[ndx].data == EMPTY){
        D->node[ndx].data = elem;
        D->node[ndx].link = -1;
    }else if(D->node[ndx].data == DELETED){
        D->node[ndx].data = elem;
    }else{
        D->node[++D->last].data = elem;
        D->node[D->last].link = D->node[ndx].link; // will get the next elem the key was pointing
        D->node[ndx].link = D->last;
    }
}

void delete(Dict *D, char elem){
    int ndx = Hash(elem), ctr;
    for(ctr = ndx; ctr != -1 && D->node[ctr].data != elem; ctr = D->node[ctr].link){}
    if(D->node[ctr].data == elem){
        D->node[ctr].data = DELETED;
    }else{
        printf("\nELEMENT DOES NOT EXIST!");
    }
}

bool isMember(Dict D, char elem){
    int ndx = Hash(elem), ctr;
    for(ctr = ndx; ctr != -1 && D.node[ctr].data != elem; ctr = D.node[ctr].link){}

    return (D.node[ctr].data == elem) ? true : false;
}