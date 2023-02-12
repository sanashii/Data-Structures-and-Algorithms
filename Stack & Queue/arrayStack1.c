#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 50

int stack[MAX], top = -1;

int evaluate(char expression[], int n);
int isOperand(char symbol);
int operation(char symbol);
void push(int stack[MAX], char expression);
void pop();

//! NOTE: gotta have the stopper at every ')'

int main(){
    char expression[MAX];
    int result, ctr;

    /* printf("Enter an expression: ");
    scanf("%s", expression); */
    strcpy(expression, "((3+2)*(3-1))");
    for(ctr = 0; expression[ctr] != '\0'; ctr++){}
    result = evaluate(expression, ctr);
    printf("Result: %d", result);
    return 0;
}

int evaluate(char expression[], int n){
    int ctr = 0, flag =2;
    char operator;
    do{
        do{
            if(isdigit(expression[ctr])){
                push(stack, expression[ctr]);
            }else if(isOperand(expression[ctr])){
                operator = expression[ctr];
                if(isdigit(expression[ctr + 1])){
                    push(stack, expression[ctr + 1]);
                    stack[0] = operation(operator);
                    pop();
                    ctr++;
                }
            }else{
                continue;
            }
            ctr++;
        }while(expression[ctr] != ')');
        flag++;
    }while(flag < 2);
}

void push(int stack[MAX], char expression){
    if(top > MAX){
        printf("Stack Overflow!!!");
    }
    top++;
    stack[top] = expression - 48;
}

void pop(){
    if(top < 0){
        printf("Stack Underflow!!!");
    }
    stack[top] = 0;
    top--;
}

int operation(char symbol){
    int result;
    switch(symbol){
        case '+':
            result = stack[top - 1] + stack[top];
            break;
        case '-':
            result = stack[top - 1] - stack[top];
            break;
        case '*':
            result = stack[top - 1] * stack[top];
            break;
        case '/':
            result = stack[top - 1] / stack[top];
            break;
    }

    return result;
}

int isOperand(char symbol){
    switch(symbol){
        case '+':
        case '-':
        case '*':
        case '/':
        return 1;
        
        default:
        return 0;
    }
}