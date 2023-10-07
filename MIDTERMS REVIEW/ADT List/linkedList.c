#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define MAX 10

//! pointer to node - dislay() & selectionSort()
//! pointer to pointer to node - insertFirst(), insertPos(), & delete()

typedef struct node{
    int data;
    struct node *link;
}*LIST;

void display(LIST L);
void deleteFirst(LIST *L);
void deleteLast(LIST *L);
void insertFirst(LIST *L, int value);
void insertLast(LIST *L, int value);
void insertAtPos(LIST *L, int loc, int value);
// insertSorted
// deleteOccur
// isMember

int main(){
    LIST L, cur;
    L = NULL;

    printf("----- DISPLAYING LL -----");
    printf("\nOriginal Linked List: ");
    display(L);

    printf("\n\n\n----- INSERT LAST -----");
    printf("\nOriginal List: ");
    display(L);
    int value = 2;
    for(int ctr = 0; ctr < MAX; ctr++){
        insertLast(&L, value);
        value += 2;
    }
    printf("\n\nList after inserting elements at the end: ");
    display(L);

    printf("\n\n\n----- DELETE FIRST -----");
    printf("\nOriginal List: ");
    display(L);
    printf("\n\nList after deleting first node: ");
    deleteFirst(&L);
    display(L);

    printf("\n\n\n----- INSERT FIRST -----");
    printf("\nOriginal List: ");
    display(L);
    printf("\n\nList after inserting | 7 | in the beginning of the list: ");
    insertFirst(&L, 7);
    display(L);

    printf("\n\n\n----- DELETE LAST -----");
    printf("\nOriginal List: ");
    display(L);
    printf("\n\nList after deleting last node: ");
    deleteLast(&L);
    display(L);

    printf("\n\n\n----- INSERT AT POSITION -----");
    printf("\nOriginal List: ");
    display(L);
    printf("\n\nList after inserting | 14 | at location 5: ");
    insertAtPos(&L, 5, 14);
    display(L);

    return 0;
}

void display(LIST L){
    if(L == NULL){
        printf("List is empty!");
        return;
    }
    LIST cur = L;
    while(cur->link != NULL){
        printf("%d -> ", cur->data);
        cur = cur->link;
    }
}

/*void insertLast(LIST *L, int value){ //! using the pointer to a node traversal for this one
    LIST temp = (LIST)malloc(sizeof(struct node)), trav = *L; // trav is a pointer to a node in this scenario
    temp->data = value;
    temp->link = NULL;
	if (*L == NULL) { // so *L is basically dereferencing the value passed into this function which means that *L == main L 
        *L = temp; // we use *L to make changes to L in main, so now main L points to the temp node we created here
        return;
    }else{
        // trav now points to the node main L is pointing to and traverses through the LL to find the latest node added
		for(trav = *L; trav->link != NULL; trav = trav->link) {} 
        // inig find niya sa node that has link == NULL, that link will now point to the temp node therefore, adding the node at the end of the list
        trav->link = temp;
	}
} */

void insertLast(LIST *L, int value){ //! using the pointer to a pointer to a node traversal for this one
    LIST temp = (LIST)malloc(sizeof(struct node)), *trav = L; // trav is a pointer pointing to the pointer L
    temp->data = value;
    temp->link = NULL;
    if (*L == NULL) { // so *L is basically dereferencing the value passed into this function which means that *L == main L 
        *L = temp; // we use *L to make changes to L in main, so now main L points to the temp node we created here
        return;
    }else{
        for( ; *trav != NULL; trav = &((*trav)->link)) {} //trav = &((*trav)->link) makes trav point to the link variable in the node, not the node itself
        // inig find niya sa node that has link == NULL, *trav or in other words the current main end node will now point to  temp
        *trav = temp;
    }
}

void deleteFirst(LIST *L){
    LIST temp = (*L)->link; // temp points to the next node L was pointing to
    *L = temp; // dereferencing - assigning the main L to point to temp which was the next node it was originally pointing at
}

void insertFirst(LIST *L, int value){
    LIST temp = (LIST)malloc(sizeof(struct node));
    temp->data = value;
    temp->link = *L; // we let the new node point to the first node L is pointing to, which is why we dereferenced L
    *L = temp; // now we use *L to let it point to the new node (temp) and still maintain the linked list
}

void deleteLast(LIST *L){
    if (*L == NULL) { // checking is the lsit is empty
        return;
    }
    if ((*L)->link == NULL) { // checking is the list only has 1 node
        free(*L);
        *L = NULL;
        return;
    }
    LIST *trav = L, temp = *L; // here, *trav is pointing to main L and temp is pointing to the 1st node that main L (i.e. *L) is pointing to
    for( ; temp->link != NULL; temp = temp->link, trav = &(*trav)->link){} // traverse through the list to find the node with a NULL pointer using temp while moving the PPN trav
    // PPN *trav will now be pointing to the node pointer that was pointing to ehe node with the NULL link and making *trav link NULL to mark that it is the new end of the list
    *trav = (*trav)->link = NULL; 
    free(temp); // we free temp / the old last node to make the new last node (*trav) officially the end of the list jd
}

void insertAtPos(LIST *L, int loc, int value){
    if (*L == NULL) {
        *L = temp;
        return;
    }
    if(loc == 1){ // special case if you're inserting at the head
        insertFirst(L, value);
        return;
    }
    LIST temp = (LIST)malloc(sizeof(struct node)), *trav = L; // again, *trav is pointing to main L
    temp->data = value;
    for(int ctr = 0; (*trav)->link != NULL && ctr < loc; ctr++, trav = &(*trav)->link){} //! REMEMBER: &(*trav)->link is basically a pointer to the link variable in a node in main
    temp->link = *trav;
    (*trav)->link = temp;
}