//ch.sc.u4aie25020
//infix to prefix

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x){
    stack[++top] = x;
}

char pop(){
    return stack[top--];
}

int priority(char x){
    if(x=='+' || x=='-')
        return 1;
    if(x=='*' || x=='/')
        return 2;
    if(x=='^')
        return 3;
    return 0;
}

int main(){

    char infix[MAX], postfix[MAX];
    int i=0,j=0;
    char x;

    printf("Enter Infix Expression: ");
    scanf("%s",infix);

    push('#');

    while(infix[i] != '\0'){

        if(isalnum(infix[i]))
            postfix[j++] = infix[i];

        else if(infix[i] == '(')
            push(infix[i]);

        else if(infix[i] == ')'){
            while(stack[top] != '(')
                postfix[j++] = pop();
            pop();
        }

        else{
            while(priority(stack[top]) >= priority(infix[i]))
                postfix[j++] = pop();
            push(infix[i]);
        }

        i++;
    }

    while(stack[top] != '#')
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("Postfix Expression: %s",postfix);

    return 0;
}