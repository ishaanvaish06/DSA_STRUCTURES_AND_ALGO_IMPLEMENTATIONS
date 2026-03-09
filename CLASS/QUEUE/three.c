//CH.SC.U4AIE25020
//Queue Dequeue Printing
#include<stdio.h>
int queue[100];
int front=0,rear=-1,i;
void enqueue(int data)
{
    rear++;
    queue[rear]=data;
}
void dequeue()
{
    if(front<=rear)
    {
        front++;
    }
}
int main()
{
    int n,data;
    printf("Enter the size of queue: ");
    scanf("%d",&n);
    printf("Enter the elements of queue:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&data);
        enqueue(data);
    }
    printf("Dequeuing elements:\n");
    while(front<rear)
    {
        dequeue();
        for(i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
    return 0;
}