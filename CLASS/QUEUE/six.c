//CH.SC.U4AIE25020
//Circular Queue Implementation
#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
typedef struct Queue
{
    int arr[SIZE];int front;int rear;
}Queue;
void enQueue(Queue* q,int value)
{
    if((q->rear+1)%SIZE==q->front)
    {
        printf("Queue is Full\n");
        return;
    }
    if(q->front==-1)
    {
        q->front=0;q->rear=0;
    }
    else
    {
        q->rear=(q->rear+1)%SIZE;
    }
    q->arr[q->rear]=value;
}
int deQueue(Queue* q)
{
    int data;
    if(q->front==-1)
    {
        return -1;
    }
    data=q->arr[q->front];
    if(q->front==q->rear)
    {
        q->front=-1;
        q->rear=-1;
    }
    else
    {
        q->front=(q->front+1)%SIZE;
    }
    return data;
}
void displayQueue(struct Queue* q)
{
    int i;
    if(q->front==-1)
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("Elements in Circular Queue are:");
    i=q->front;
    while(1)
    {
        printf("%d ",q->arr[i]);
        if(i==q->rear)
            break;
        i=(i+1)%SIZE;
    }
    printf("\n");
}
int main()
{
    Queue q;q.front=-1;q.rear=-1;int n,i,x;
    printf("Enter number of elements: ");scanf("%d",&n);
    printf("Enter elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        enQueue(&q,x);
    }
    displayQueue(&q);printf("Deleted value = %d\n",deQueue(&q));
    printf("Deleted value = %d\n",deQueue(&q));displayQueue(&q);
}