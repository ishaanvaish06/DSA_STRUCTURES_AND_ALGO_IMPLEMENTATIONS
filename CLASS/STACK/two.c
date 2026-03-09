//CH.SC.U4AIE25020
//Merging Two Stacks Using Linked List
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;

typedef struct
{
    node *top;
}mystack;

void push(int data,mystack* ms)
{
    node *temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->next=ms->top;
    ms->top=temp;
}
int pop(mystack* ms)
{
    if(ms->top==NULL)
        return -1;
    node *temp=ms->top;
    int x=temp->data;
    ms->top=temp->next;
    free(temp);
    return x;
}
void merge(mystack* ms1,mystack* ms2)
{
    node *t=ms1->top;
    if(t==NULL)
    {
        ms1->top=ms2->top;
        return;
    }
    while(t->next!=NULL)
        t=t->next;
    t->next=ms2->top;
}
void printStack(mystack* ms)
{
    node *t=ms->top;
    while(t!=NULL)
    {
        printf("%d ",t->data);
        t=t->next;
    }
}
int main()
{
    mystack s1,s2;
    int n,m,i,x;
    s1.top=NULL;
    s2.top=NULL;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        push(x,&s1);
    }
    for(i=0;i<m;i++)
    {
        scanf("%d",&x);
        push(x,&s2);
    }
    merge(&s1,&s2);
    printStack(&s1);
    return 0;
}