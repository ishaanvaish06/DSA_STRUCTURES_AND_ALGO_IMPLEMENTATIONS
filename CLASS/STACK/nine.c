//CH.SC.U4AIE25020
//Implementation of Stack Using a Single Queue
#include<stdio.h>
int q[1000];
int front=0,rear=0;
void push(int val)
{
    int i,size=rear-front;
    q[rear++]=val;
    for(i=0;i<size;i++)
    {
        q[rear++]=q[front++];
    }
}
void pop()
{
    front++;
}
int top()
{
    return q[front];
}
int main()
{
    int n,m,i,x;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        push(x);
    }
    printf("top of element %d\n",top());
    for(i=0;i<m;i++)
        pop();
    printf("top of element %d",top());
    return 0;
}
