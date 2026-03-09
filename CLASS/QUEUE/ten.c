//CH.SC.U4AIE25020
//Circular Queue Reverse
#include<stdio.h>
int queue[100];
int front=-1,rear=-1;
int n;
void enqueue(int data,int l){
    if(rear==l-1){
        printf("Queue Overflow\n");
        return;
    }
    if(front==-1)
        front=0;
    rear++;
    queue[rear]=data;
}
void reverse(){
    int i,j,temp;
    for(i=front,j=rear;i<j;i++,j--){
        temp=queue[i];
        queue[i]=queue[j];
        queue[j]=temp;
    }
}
int main(){
    int t,i;
    printf("Enter size of queue:\n");
    scanf("%d",&n);
    printf("Enter queue elements:\n");
    for(i=0;i<n;i++){
        scanf("%d",&t);
        enqueue(t,n);
    }
    printf("Queue:");
    for(i=front;i<=rear;i++)
        printf("%d ",queue[i]);
    printf("\n");
    reverse();
    printf("Reversed Queue:");
    for(i=front;i<=rear;i++)
        printf("%d ",queue[i]);
    printf("\n");
    return 0;
}