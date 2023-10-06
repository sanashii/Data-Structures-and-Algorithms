#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stackADT.h" // Array Implementation V2
//#include "stackLL.h" // Linked List Implementation // uncomment for LL implementation
//#include "stackCB.h" // Cursor Based Implementation V3 // uncomment for CB implementation

void insertBottom(STACK *S, char elem);

int main() {
    STACK S;
    initialize(&S);

    push(&S, 'H');
    push(&S, 'E');
    push(&S, 'L');
    push(&S, 'L');
    push(&S, 'O');

    displayStack(S);
	push(&S, 'W');

    printf("\n");
    displayStack(S);

	pop(&S);

	printf("\n");
    displayStack(S);

    insertBottom(&S, 'Z');

    printf("\n");
    displayStack(S);

    insertBottom(&S, 'X');

    printf("\n");
    displayStack(S);
    
    return 0;
}

//* works for all 3 implementations
void insertBottom(STACK *S, char elem) {
    if(!isFull(*S)) {
        if(isEmpty(*S)) { // this is where we insert the element if the stack is empty
            push(S, elem);
        } else {
            STACK temp;
			char c;
            initialize(&temp);

            while(!isEmpty(*S)) { // this is where we transfer the data to temp
				c = top(*S);
                push(&temp, c);
                pop(S);
            }

            push(S, elem); // insertion of the element

            while(!isEmpty(temp)) { // transfering back the element from temp to orginal stack
                c = top(temp);
				pop(&temp);
				push(S, c);
            }
        }
    } else {
        printf("\nSTACK OVERFLOW!\n");
    }
}