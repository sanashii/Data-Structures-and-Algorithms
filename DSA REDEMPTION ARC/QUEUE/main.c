#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include "arrayV1Queue.h" // Array Implementation V1 (Shifting)
//#include "arrayV2Queue.h" // Array Implementation V2 (Sol. 2 CA)
//#include "arrayV3Queue.h" // Array Implementation V3 - Fixed Array Size (Sol. 1 CA ctr variable)
//#include "arrayV4Queue.h" // Array Implementation V4 Dynamic Array
//#include "queueCA.h" // Circular Array Implementation
#include "queueLL.h" // Linked List Implementation (Circular LL)
//#include "queueCB.h" // Cursor Based Implementation V2

int main(){
    Queue Q = initQueue(Q);
    enqueue(&Q, 7);
    enqueue(&Q, 12);
    enqueue(&Q, 4);
    enqueue(&Q, 0);

    printf("Current front: %d\n", front(Q));
    display(Q);
    
    enqueue(&Q, 16);
    display(Q);
    
    enqueue(&Q, 9);
    dequeue(&Q);
    dequeue(&Q);
    
    display(Q);
    printf("Current front: %d\n", front(Q));
    
    enqueue(&Q, 5);
    display(Q);
    
    dequeue(&Q);
    display(Q);

    return 0;
}