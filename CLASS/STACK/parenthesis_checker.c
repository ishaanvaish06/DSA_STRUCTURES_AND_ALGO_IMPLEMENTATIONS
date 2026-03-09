//ch.sc.u4aie25020
//parenthesis checker (implemented using stack)

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    char items[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return (s->top == -1);
}

void push(Stack *s, char c) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = c;
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->items[(s->top)--];
}

int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')')
        return 1;
    if (open == '{' && close == '}')
        return 1;
    if (open == '[' && close == ']')
        return 1;
    return 0;
}

int checkBalanced(char expr[]) {
    Stack s;
    init(&s);

    for (int i = 0; expr[i] != '\0'; i++) {

        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            push(&s, expr[i]);
        }

        else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {

            if (isEmpty(&s))
                return 0;

            char top = pop(&s);

            if (!isMatchingPair(top, expr[i]))
                return 0;
        }
    }

    return isEmpty(&s);
}

int main() {
    char expression[100];

    printf("Enter an expression: ");
    scanf("%s", expression);

    if (checkBalanced(expression))
        printf("Parentheses are Balanced\n");
    else
        printf("Parentheses are Not Balanced\n");

    return 0;
}