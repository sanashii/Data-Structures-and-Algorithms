#include<stdio.h>
#include<stdlib.h>

/*
4. Label(n,T)
5. Create(v1,T1,T2....,Ti)
*/

typedef struct node{
    int data;
    struct node *parent;
    struct node *left;
    struct node *right;
}*TREE;

//--- TRAVERSALS ---//
void inorderTraversal(TREE root){ // [left -> root -> right]
    if(root == NULL)
        return;
    inorderTraversal(root->left); // visits all the left nodes
    printf("%d -> ", root->data); // before printing it
    inorderTraversal(root->right); // then the right nodes dayun
}

void preorderTraversal(TREE root){ // [root -> left -> right]
    if(root == NULL)
        return; 
    printf("%d -> ", root->data); // prints the root
    preorderTraversal(root->left); // view AR of this traversal method for more understanding
    preorderTraversal(root->right);
}

void postorderTraversal(TREE root){ // [left -> right -> root]
    if(root == NULL)
        return; 
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d -> ", root->data);
}

//--- TREE OPERATIONS ---//
TREE initTree(TREE root){
    return root = NULL;
}

TREE makeNull(TREE root){
    return root = NULL;
}

TREE createNode(int value){
    TREE temp = malloc(sizeof(struct node));
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void insertNode(TREE root, TREE node){  //! NOTE: recursive calls will be done until until the stopping condition will be met, in this case, if(node == NULL) then mu balik ta sa previous recursive call
    if(node == NULL)
        return;
    
    if(node->data < root->data){
        if(root->left == NULL) {// if its NULL meaning wa pa siyay link, it will link the new node to the current root we are on
            root->left = node;
            node->parent = root;
        }
        else
            insertNode(root->left, node); // if not kay we have a recursive call wherein katong gi point sa left ptr of root, will become the new root and another AR of insertNode will exist
    }else{
        if(root->right == NULL){ // if its NULL meaning wa pa siyay link, it will link the new node to the current root we are on
            root->right = node;
            node->parent = root;
        }else
            insertNode(root->right, node); // if not kay we have a recursive call wherein katong gi point sa right pointer of root, will become the new root and another AR of insertNode will exist
    }
}

int rootOfTree(TREE root){ // returns the root of the tree
    return root->data;
}

TREE parent(TREE root, TREE n){
    if(n == root)
        return NULL;
    else
        return n->parent;
}

TREE leftMostChild(TREE root, TREE n){
    if(n == NULL)
        return NULL;
    else if(n->left == NULL)
        return n;
    else
        return leftMostChild(n, n->left); // recursive call to keep traversing to the v bottom left of that node
}

TREE rightSibling(TREE root, TREE n){
    n = parent(root, n); // n will now be pointing to its parent class
    return n->right; // and returning the right node that its parent class was pointing at
}


int main(){
    TREE root = NULL, temp;
    int arr[] = {5, 7, 1, 8, 6, 2, 4};

    for(int ctr = 0; ctr < sizeof(arr) / 4; ctr++){ // creating the tree
        temp = createNode(arr[ctr]);
        if(root == NULL) // if wa pay root then it assigns the 1st node created to be the root of the tree
            root = temp;
        else
            insertNode(root, temp);
    }

    printf("The root of the tree is: %d", rootOfTree(root->right->right));

    temp = parent(root, root->right->right); // parent of 8
    printf("\n\nThe parent of 8 is: %d", temp->data); // should be 7
    temp = parent(root, root->left); // parent of 1
    printf("\n\nThe parent of 1 is: %d", temp->data); // should be 5

    temp = leftMostChild(root, root->right);
    printf("\n\nThe leftmost child of 7 is: %d", temp->data); // should be 6

    temp = rightSibling(root, root->right->left);
    printf("\n\nThe right sibling of 6 is: %d", temp->data); // should be 8

    printf("\n\nINORDER TRAVERSAL: ");
    inorderTraversal(root);

    printf("\n\nPREORDER TRAVERSAL: ");
    preorderTraversal(root);

    printf("\n\nPOSTORDER TRAVERSAL: ");
    postorderTraversal(root);
    
    return 0;
}
