#include <stdio.h>
#include <stdlib.h>

int stack[100];
int top=-1;
void push(int x) {
    if (top==99) {
        printf("Stack Overflow");
        return;
    }
    stack[++top]=x;
}
int pop() {
    if (top==-1) {
        printf("Stack Underflow");
        return -1;
    }
    return stack[top--];
}

int display() {
    if (top==-1) {
        printf("Stack Underflow");
        return;
    }
    return stack[top];
}