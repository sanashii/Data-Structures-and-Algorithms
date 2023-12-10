#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}*Tree, Node;

void initTree(Tree *t);
Tree createNode(int num);
void insertNode(Tree *t, Tree node);
void inorderTraversal(Tree t);
void preorderTraversal(Tree t);
void postorderTraversal(Tree t);

int main(){
    Tree t;
    initTree(&t);
    insertNode(&t, createNode(10));
    insertNode(&t, createNode(2));
    insertNode(&t, createNode(5));
    insertNode(&t, createNode(12));
    insertNode(&t, createNode(21));
    insertNode(&t, createNode(9));
    insertNode(&t, createNode(16));
    insertNode(&t, createNode(3));
    insertNode(&t, createNode(1));
    
    printf("\n--- INORDER TRAVERSAL ---\n");
    inorderTraversal(t);

    printf("\n--- PREORDER TRAVERSAL ---\n");
    preorderTraversal(t);

    printf("\n--- POSTORDER TRAVERSAL ---\n");
    postorderTraversal(t);

    return 0;
}

void initTree(Tree *t){
    *t = NULL;
}

Tree createNode(int num){
    Tree temp = (Tree)malloc(sizeof(struct node));
    temp->data = num;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void insertNode(Tree *t, Tree node){
    if(node == NULL){
        return; //! STOPPING CONDITION FOR RECURSIVE CALL
    }
    if(*t == NULL){
        *t = node;
    }
    
    if(*t != NULL && node->data < (*t)->data){
        if((*t)->left == NULL){ // * if wa pay sulod iyang left subtree
            (*t)->left = node;
        }else{
            insertNode(&(*t)->left, node);
        }
    }else if(*t != NULL && node->data > (*t)->data){ 
        if((*t)->right == NULL){ // * if wa pay sulod ang right subtree
            (*t)->right = node;
        }else{
            insertNode(&(*t)->right, node);
        }
    }
}

void inorderTraversal(Tree t){
    if(t == NULL)
        return;
    inorderTraversal(t->left);
    printf("%d -> ", t->data);
    inorderTraversal(t->right);
}

void preorderTraversal(Tree t){
    if(t == NULL)
        return;
    printf("%d -> ", t->data);
    preorderTraversal(t->left);
    preorderTraversal(t->right);
}

void postorderTraversal(Tree t){
    if(t == NULL)
        return;
    postorderTraversal(t->left);
    postorderTraversal(t->right);
    printf("%d -> ", t->data);
}