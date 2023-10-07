#define SIZE 10

typedef struct list {
    int count;
    char array[10];
} LIST;
	
void functionInitialize (LIST *A);

void main () {
    LIST L;
    functionInitialize (&L);
}

void functionInitialize (LIST *A) {
	LIST *Lptr = &A;
    A->count = 0;
}
