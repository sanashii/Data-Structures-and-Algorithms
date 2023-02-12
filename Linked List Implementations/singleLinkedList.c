#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}*LIST, nodetype;

int main(){
    LIST cur, temp, head = (LIST)malloc(sizeof(nodetype));
    head = NULL;
    temp = head;
    temp = (LIST)malloc(sizeof(nodetype));
    temp->data = 5;
    temp->next = NULL;
    head = temp;
    cur = head;
    temp = (LIST)malloc(sizeof(nodetype));
    temp->data = 2;
    temp->next = NULL;
    cur = temp;
    temp = (LIST)malloc(sizeof(nodetype));
    temp->data = 7;
    temp->next = NULL;
    cur = head;

    printf("Contents of the linked list: ");
    while(cur != NULL){
        printf("%d ", cur->data);
        cur = cur->next;
    }
    return 0;
}