//CH.SC.U4AIE25020
//Implementation of Two Stacks in a Single Array
#include<stdio.h>
int arr[100];
int top1=-1;
int top2=100;
void push1(int x)
{
    arr[++top1]=x;
}
void push2(int x)
{
    arr[--top2]=x;
}
int pop1()
{
    return arr[top1--];
}
int pop2()
{
    return arr[top2++];
}
int main()
{
    int i,x;
    for(i=0;i<5;i++)
    {
        scanf("%d",&x);
        if(i%2==0)
            push1(x);
        else
            push2(x);
    }
    printf("Popped element from stack1 is:%d\n",pop1());
    printf("Popped element from stack2 is:%d",pop2());
}
