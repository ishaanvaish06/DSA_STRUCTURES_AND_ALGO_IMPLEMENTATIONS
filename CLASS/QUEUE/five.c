//CH.SC.U4AIE25020
//Queue-5: insert element in queue
#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int data) {
    int i;
    if (rear == MAX - 1) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = data;
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("Enqueuing %d\n", data);
}

void disp() {
    int i;
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    for (i = front; i <= rear; i++) {
        printf("%d", queue[i]);
    }
    printf("\n");
}

int main() {
    int size, i;
    scanf("%d", &size);
    for (i = 0; i < size; i++) {
        int data;
        scanf("%d", &data);
        enqueue(data);
    }
    disp();
    return 0;
}