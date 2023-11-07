#include<stdio.h>
#include<stdlib.h>
#define MAX 15

typedef struct cell{
    int elem[MAX];
    int lastNdx;
}Heap;

void initHeap(Heap *H); // initialize the heap to be empty
void insert(Heap*H, int num);
int deleteMin(Heap *H);
void display(Heap H); // displays in an array like list
void heapSort(Heap *H);

int main(){
    Heap H;
    initHeap(&H);
    insert(&H, 3);
    insert(&H, 4);
    insert(&H, 9);
    insert(&H, 6);
    insert(&H, 5);
    insert(&H, 9);
    insert(&H, 10);
    insert(&H, 10);
    insert(&H, 18);
    insert(&H, 7);

    insert(&H, 2);

    display(H);

    // printf("\nMinimum: %d\n", deleteMin(&H));
    // display(H);

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

// int deleteMin(Heap *H){
//     int min = -1, ctr, temp;
//     if(H->lastNdx != -1){
//         min = H->elem[0];
//         H->elem[0] = H->elem[H->lastNdx];
//         H->lastNdx--;
//         for(ctr = 0; ctr <= H->lastNdx && H->elem[ctr] > H->elem[(ctr * 2) + 1]; ){
//             int child = (ctr * 2) + 1;
//             if(H->elem[child + 1] < H->elem[child]){
//                 child++;
//             }
//             temp = H->elem[ctr];
//             H->elem[ctr] = H->elem[child];
//             H->elem[child] = temp;

//             ctr = child;
//         }
//     }
//     return min;
// }

int deleteMin(Heap *H) {
    int retVal = -1;
    if(H->lastNdx != -1){
        int min = H->elem[0], parent = 0, LC, RC, SC, temp;
        retVal = min;
        H->elem[0] = H->elem[H->lastNdx];
        H->lastNdx--;
        for(LC = (parent * 2) + 1, SC = LC; LC <= H->lastNdx && H->elem[parent] >= H->elem[SC]; LC = (parent * 2) + 1){ // SC is initially = LC
            RC = LC + 1;
            SC = (RC <= H->lastNdx && H->elem[RC] < H->elem[LC]) ? RC : LC;
            temp = H->elem[parent];
            H->elem[parent] = H->elem[SC];
            H->elem[SC] = temp;
            parent = SC;
        }
    }
    
    return retVal;
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