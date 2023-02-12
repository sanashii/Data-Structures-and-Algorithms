#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int item) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = item;
}

int pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int is_operator(char symbol) {
    switch (symbol) {
        case '+':
        case '-':
        case '*':
        case '/':
            return 1;
        default:
            return 0;
    }
}

int perform_operation(char operation, int *operand1, int *operand2) {
    if (top < 1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    *operand2 = pop();
    *operand1 = pop();

    switch (operation) {
        case '+':
            return *operand1 + *operand2;
        case '-':
            return *operand1 - *operand2;
        case '*':
            return *operand1 * *operand2;
        case '/':
            return *operand1 / *operand2;
        default:
            printf("Invalid operator: %c\n", operation);
            exit(1);
    }
}


int evaluate_expression(char expression[]) {
    int i;
    int operand1, operand2, result;
    char symbol;

    for (i = 0; expression[i] != '\0'; i++) {
        symbol = expression[i];

        if (isdigit(symbol)) {
            push(symbol - '0');
        } else if (is_operator(symbol)) {
            push(symbol);
            /*if(isdigit(expression[i + 1])){
                continue;
            } */
            result = perform_operation(symbol, &expression[i - 1], &expression[i + 1]);
            push(result);
        }
    }

    return pop();
}


int main() {
    char expression[MAX_SIZE];
    int result;

    printf("Enter an expression: ");
    scanf("%s", expression);

    result = evaluate_expression(expression);
    printf("Result: %d\n", result);

    return 0;
}
