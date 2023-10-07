enqueue(&Q, 9);
    dequeue(&Q);
    dequeue(&Q);
    display(Q);
    printf("Current front: %d\n", front(Q));
    enqueue(&Q, 9);
    display(Q);
    dequeue(&Q);
    display(Q);