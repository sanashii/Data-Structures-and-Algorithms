#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node* right;
}*TREE;

TREE createNode(int value);
void insertNode(TREE *root, int value);
void inorderDisplay(TREE root);
void postorderDisplay(TREE root);

int main(){
    int arr[] = {5, 7, 1, 8, 6, 2, 4};
    TREE root = NULL;
    for(int ctr = 0; ctr < sizeof(arr) /4; ctr++)
        insertNode(&root, arr[ctr]);
    printf("Inorder Display: ");
    inorderDisplay(root);
    printf("\n");
    printf("Postorder Display: ");
    postorderDisplay(root);
    return 0;
}

TREE createNode(int value){
    TREE tempNode = (TREE)malloc(sizeof(struct node));
    tempNode->data = value;
    tempNode->left = NULL;
    tempNode->right = NULL;

    return tempNode;
}

void insertNode(TREE *root, int value){
    if(*root == NULL){
        *root = createNode(value);
        return;
    }
    if(value < (*root)->data)
        insertNode(&(*root)->left, value);
    else
        insertNode(&(*root)->right, value);
}

void inorderDisplay(TREE root){
    if(root == NULL)
        return;
    inorderDisplay(root->left);
    printf("%d ->", root->data);
    inorderDisplay(root->right);
}

void postorderDisplay(TREE root){
    if(root == NULL)
        return;
    postorderDisplay(root->left);
    postorderDisplay(root->right);
    printf("%d ->", root->data);
}