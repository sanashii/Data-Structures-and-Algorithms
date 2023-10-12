#include<stdio.h>
#include<stdbool.h>

typedef struct node{
    int key; // since its not linked list, the key will determine if it belongs to the same "linked list"
    int data;
    int link
}Nodes;

typedef struct cell{
    Nodes node;
    int avail;
}HashTable, *Dict;

void initDict(Dict *D, HashTable vh);
int Hash(int number);
void display(Dict D, HashTable vh);
void insert(Dict D, int num, HashTable vh);
void delete(Dict D, int num, HashTable vh);
bool isMember(Dict D, int num, HashTable vh);

int main(){

    return 0;
}


