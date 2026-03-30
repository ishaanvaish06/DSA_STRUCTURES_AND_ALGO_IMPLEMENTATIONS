#include<stdio.h>
#include<stdlib.h>

int queue[100];
int front=-1;
int rear=-1;

void enque(int x) {
    if(rear==99) {
        printf("Queue is full");
        return;
    }
    queue[++rear]=x;
}
int deque() {
    if(front==rear) {
        front=rear=-1;
        printf("Queue is empty");
        return;
    }
    return queue[front++];
}
void display() {
    if(front==rear) {
        printf("Queue is empty");
        return;
    }
    while(front!=rear) {
        printf("%d -> ",queue[front++]);
    }
    printf("%d",queue[front]);
}