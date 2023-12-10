#include<stdio.h>
#include<stdbool.h>
#define MAX 10

typedef struct node{
    int key; // since its not linked list, the key will determine if it belongs to the same "linked list"
    int data;
    int link
}Nodes;

typedef struct cell{
    Nodes node[MAX];
    int avail;
}HashTable, *Dict;

void initDict(Dict *D, HashTable *vh);
int Hash(int number);
void display(Dict D, HashTable vh);
void insert(Dict *D, int num, HashTable *vh);
void delete(Dict *D, int num, HashTable *vh);
bool isMember(Dict D, int num, HashTable vh);

int main(){
    Dict D;
    HashTable h;
    initDict(&D, &h);

    return 0;
}

void initDict(Dict *D, HashTable *vh){
    *D = -1;
    for(int ctr = 0; ctr < MAX - 1; ctr++){
        vh->node[ctr].link = ctr;
    }
    vh->node[ctr].link = -1;
    vh->avail = 0;
}

int Hash(int num){
    return num % 10;
}

void display(Dict D, HashTable vh);
void insert(Dict D, int num, HashTable vh);
void delete(Dict D, int num, HashTable vh);
bool isMember(Dict D, int num, HashTable vh);

