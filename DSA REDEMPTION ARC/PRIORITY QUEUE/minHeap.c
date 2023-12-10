#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 9

typedef struct cell{
    int elem[MAX];
    int lastNdx;
}Heap;

void initHeap(Heap *H); // initialize the heap to be empty
void insert(Heap*H, int num);
void heapify(Heap *H);
int deleteMin(Heap *H);
void display(Heap H); // displays in an array like list
void heapSort(Heap *H);

int main(){
    Heap H;
    int arr[MAX] = {7,2,5,3,1,8,4,9,10};
    initHeap(&H);
    for(int ctr = 0; ctr < MAX; ctr++){
        H.elem[ctr] = arr[ctr];
    }
    H.lastNdx = MAX - 1;
    heapify(&H);
    // insert(&H, 3);
    // insert(&H, 4);
    // insert(&H, 9);
    // insert(&H, 6);
    // insert(&H, 5);
    // insert(&H, 9);
    // insert(&H, 10);
    // insert(&H, 10);
    // insert(&H, 18);
    // insert(&H, 7);

    // insert(&H, 2);

    display(H);

    printf("\nMinimum: %d\n", deleteMin(&H));
    display(H);

    printf("\n\t-------- HEAP BEFORE HEAPSORT ----------\n");
    display(H);
    printf("\n\t-------- HEAP AFTER HEAPSORT ----------\n");
    heapSort(&H);
    display(H);

    return 0;
}

void initHeap(Heap *H){
    H->lastNdx = -1;
}

void insert(Heap*H, int num){
    int ctr, temp;
    if(H->lastNdx < MAX){
        H->elem[++H->lastNdx] = num;
        for(ctr = H->lastNdx; ctr > 0 && H->elem[ctr] <= H->elem[(ctr - 1) / 2]; ctr = (ctr - 1) / 2){
            temp = H->elem[ctr];
            H->elem[ctr] = H->elem[(ctr - 1) / 2];
            H->elem[(ctr - 1) / 2] = temp;
        }
    }
}

void heapify(Heap *H){ // this can be recursive noh?
    int lowParent = (H->lastNdx - 1) / 2, LC, RC, SC, temp; //! NOTE: lowparent var is an index, not the content jd
    for( ; lowParent >= 0; lowParent--){
        LC = (2 * lowParent) + 1;
        RC = LC + 1;
        SC = (H->elem[LC] <= H->elem[RC]) ? LC : RC;
        if(H->elem[SC] < H->elem[lowParent]){
            temp = H->elem[SC];
            H->elem[SC] = H->elem[lowParent];
            H->elem[lowParent] = temp;
        }
    }
}

int deleteMin(Heap *H){
    int root, min = -1, LC, RC, SC, temp;
    if(H->lastNdx != -1){
        root = 0;
        min = H->elem[root];
        LC = (2 * root) + 1;
        RC = LC + 1;
        H->elem[root] = H->elem[H->lastNdx];
        H->lastNdx--;

        for(SC = (RC <= H->lastNdx && H->elem[LC] < H->elem[RC]) ? LC : RC; SC <= H->lastNdx && H->elem[root] >= H->elem[SC]; LC = (2 * SC) + 1, RC = LC + 1, SC = (RC <= H->lastNdx && H->elem[LC] < H->elem[RC]) ? LC : RC){
            temp = H->elem[root];
            H->elem[root] = H->elem[SC];
            H->elem[SC] = temp;
            root = SC;
        }
    }

    return min; 
}

void display(Heap H){
    if(H.lastNdx != -1){
        printf("Heap:\t");
        for(int ctr = 0; ctr <= H.lastNdx; ctr++){
            printf("%d\t", H.elem[ctr]);
        }
        printf("\n");
    }
}

void heapSort(Heap *H){
    int oldLastNdx = H->lastNdx;
    while(H->lastNdx >= 0){
        H->elem[H->lastNdx] = deleteMin(H);
    }
    H->lastNdx = oldLastNdx;
}