#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct node{
    int data[MAX];
    int lastNdx;
}Heap;

Heap initHeap(Heap *h);
void heapify(Heap *h);
void insert(Heap *h, int num);
int deleteMin(Heap *h);
void heapSort(Heap *h);
void display(Heap h);

int main(){
    Heap vh = initHeap(&vh);
    int arr[] = {21, 1, 10, 7, 3, 9, 2, 5, 18, 4}, ctr;

    // * manually inserting
    // for(int ctr = 0; ctr < MAX; ctr++){
    //     insert(&vh, arr[ctr]);
    // }
    // display(vh);

    // * using heapify
    for(ctr = 0; ctr < MAX; ctr++){
        vh.data[ctr] = arr[ctr];
        vh.lastNdx++;
    }
    heapify(&vh);

    display(vh);

    // printf("\nDeleting minimum: %d", deleteMin(&vh));

    display(vh);

    heapSort(&vh);
    display(vh);

    return 0;
}

Heap initHeap(Heap *h){
    (*h).lastNdx = -1;
    return *h;
}

void heapify(Heap *h){
    int LC, RC, SC, parent, temp;
    for(parent = (h->lastNdx - 1)/2; parent >= 0; parent--){
        LC = 2 * parent + 1;
        RC = LC + 1;
        SC = (h->data[LC] <= h->data[RC]) ? LC : RC; 
        if(h->data[SC] < h->data[parent]){
            temp = h->data[SC];
            h->data[SC] = h->data[parent];
            h->data[parent] = temp;
            heapify(h);
        }
    }
}

void insert(Heap *h, int num){
    int ctr, temp;
    if(h->lastNdx < MAX){
        h->lastNdx++;
        h->data[h->lastNdx] = num;
        for(ctr = h->lastNdx; ctr > 0 && h->data[ctr] <= h->data[(ctr - 1) / 2]; ctr = (ctr - 1) / 2){ // while newly added num is < than its parent, we swap
            temp = h->data[ctr];
            h->data[ctr] = h->data[(ctr - 1) / 2];
            h->data[(ctr - 1) / 2] = temp;
        }
    }
}

int deleteMin(Heap *h){
    int min = -1, LC, RC, SC, root = 0, temp;
    if(h->lastNdx != -1){
        min = h->data[root];
        h->data[root] = h->data[h->lastNdx];
        h->lastNdx--;
        LC = (root * 2) + 1;
        RC = LC + 1;
        SC = (h->data[LC] < h->data[RC]) ? LC : RC;
        for( ; SC <= h->lastNdx && h->data[SC] <= h->data[root]; LC = (2 * root) + 1, RC = LC + 1, SC = (h->data[LC] < h->data[RC]) ? LC : RC){
            temp = h->data[SC];
            h->data[SC] = h->data[root];
            h->data[root] = temp;

            root = SC;
        }
    }

    return min;
}

void heapSort(Heap *h){
    int oldLastNdx = h->lastNdx;
    while(h->lastNdx >= 0){
        h->data[h->lastNdx] = deleteMin(h);
    }
    h->lastNdx = oldLastNdx;
}

void display(Heap h){
    printf("\nHEAP ELEMENTS: ");
    for(int ctr = 0; ctr <= h.lastNdx; ctr++){
        printf("%d -> ", h.data[ctr]);
    }
}