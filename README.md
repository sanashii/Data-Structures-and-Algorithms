# Data-Structures-and-Algorithms
### REFER TO ```DSA REDEMPTION ARC``` FOLDER
Repository of my codes from my DSA class. Some of these were from my previous semester in DSA. The folder containing the hard work and grind is found in the ```DSA REDEMPTION ARC``` folder.
This documentation refers to the codes found in `DSA REDEMPTION ARC`

### QUEUE
1. main.c  -  Driver file for all the implementations
2. arrayV1Queue.h  -  Array V1 Implementation (Shifting)
- Notables:
  - we used shifting here in a loop to shift the elements up to the front after dequeuing.
```c
void dequeue(Queue *Q){
    if(!isEmpty(*Q)){
        for(int ctr = 0; ctr <= Q->rear; ctr++){
            shift(&(*Q).arr[ctr], &(*Q).arr[ctr + 1]);
        }
        Q->rear--;
    }
}
```

3. arrayV2Queue.h  -  Array V2 Implementation (Circular Array - sacrificing 1 cell)
- Notables:
  - in enqueue(), the line `(*Q)->rear = ((*Q)->rear + 1) % MAX;` increments rear and will also wrap it back to 0 when necessary because of the % MAX statement.
  - in dequeue(), `(*Q)->front = ((*Q)->front + 1) % MAX;` increments front as a way to dequeue while wrapping it too when necessary.
  - in display(), the line `ctr = (ctr + 1) % MAX;` inside the do while loop increments ctr while wrapping it when necessary.
  - in display(), the condition in the do while loop `ctr != (Q->rear + 1) % MAX` checks if ctr is != to the rear and has the `% MAX` to still get the value of rear whether its wrapped or not
```c
void enqueue(Queue *Q, int elem){
    if((*Q)->front == -1){
        (*Q)->front = 6; // randomly placing the front to start at 6
        (*Q)->rear = (*Q)->front - 1;
    }

    if((!isFull(*Q))){
        (*Q)->rear = ((*Q)->rear + 1) % MAX; // does the incrementing and wrapping of rear
        (*Q)->arr[(*Q)->rear] = elem;
    }else{
        printf("\nQUEUE IS FULL! Can no longer add element.");
    }
}

void dequeue(Queue *Q){
    if(!isEmpty(*Q)){
        (*Q)->front = ((*Q)->front + 1) % MAX;     // front increments whilst wrapping if necessary

        if((*Q)->front == ((*Q)->rear + 1) % MAX){ // checks if Queue is empty
            (*Q)->front = -1;
            (*Q)->rear = -1;
        }
    }
}

void display(Queue Q){
    printf("\nQUEUE:\t");
    if(!isEmpty(Q)){
        int ctr = Q->front;
        do{
            printf("%d\t", Q->arr[ctr]);
            ctr = (ctr + 1) % MAX; //* increments ctr whilst wrapping when necessary
        }while(ctr != (Q->rear + 1) % MAX); //* while ctr isnt == to the rear whether wrapped or not
    }
    printf("\n");
}
```

4. arrayV3Queue.h  -  Array V3 Implementation [FIXED SIZE] (Circular Array - using a ctr variable)
- Notables:
  - similar codes to enqueue() & dequeue() from `arrayV2Queue.h` except that we made use of a ctr variable instead to keep the number of elements in check, ctr variable is found in the Queue structure.
  - display() differs in a way wherein the number of iterations is compared with the Q.ctr. We used ctr in the loop as the index starting from front to rear (we still had to wrap it).
```c
void enqueue(Queue *Q, int elem){
    if(Q->front == -1){
        Q->front = 3; // randomly starts at index 3
        Q->rear = Q->front - 1;
    }
    if(!isFull(*Q)){
        Q->rear = (Q->rear + 1) % MAX;
        Q->elemptr[Q->rear] = elem;
        Q->ctr++;
    }else{
        printf("\nQUEUE IS FULL! Can no longer add elements.");
    }
}

void dequeue(Queue *Q){
    if(!isEmpty(*Q)){
        Q->front = (Q->front + 1) % MAX;
        Q->ctr--;

        if(Q->front == (Q->rear + 1) % MAX){ // checks if Queue is empty
            Q->front = -1;
            Q->rear = -1;
        }
    }
}

int front(Queue Q){
    return Q.elemptr[Q.front];
}

void display(Queue Q){
    if (!isEmpty(Q)) { //* more readable
        printf("\nQUEUE:\t");
        int iteration = 0, ctr = Q.front;
        while (iteration < Q.ctr) {
            printf("%d\t", Q.elemptr[ctr]);
            ctr = (ctr + 1) % MAX;
            iteration++;
        }
    }
    printf("\n");
}
```
<li>arrayV4Queue.h  -  Array V4 Implementation [DYNAMIC]</li>
<li>queueCA.h  -  Circular Array - sacrificing 1 cell (V1 Implementation)</li>
<li>queueLL.h  -  Doubly Linked List Implementation (Circular)</li>
<li>queueCB.h  -  Cursor Based Implementation V1 (Circular)</li>
