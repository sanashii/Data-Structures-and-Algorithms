#include<stdio.h>

void display(int *data){
    printf("\nAddress of data: %d", data);
    printf("\nValue of *data: %d", *data);
}

int main(){
    int *num = 10;
    printf("\nAddress of num in main: %d", &num);
    display(&num);

    return 0;
}