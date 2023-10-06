#include<stdio.h>

typedef char SET;

void displayBitPattern(SET A);
void displaySet(SET A);

int main(){
    SET A = -107;

    printf("Bit pattern of %d: ", A);
    displayBitPattern(A);
    printf("\nSet A = ");
    displaySet(A);

    return 0;
}

void displayBitPattern(SET elem){
    int bits = sizeof(char) * 8, ctr;
    for(ctr = bits - 1; ctr >= 0; ctr--){
        int bit = (elem >> ctr) & 1;
        printf("%d", bit);

        if (ctr % 4 == 0)
            printf(" ");
    }
}

void displaySet(SET elem){
    int bits = sizeof(char) * 8, ctr;
    printf("[ ");
    for(ctr = bits - 1; ctr >= 0; ctr--){
        int bit = (elem >> ctr) & 1;
        if(bit == 1)
            printf("%d ", ctr);
        
    }
    printf("]");
}