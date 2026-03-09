//CH.SC.U4AIE25020
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void display(struct node *start)
{
    struct node *temp=start;
    printf("Linked List:");
    while(temp!=NULL)
    {
        printf("->%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void insertAfter(struct node *start,int key,int value)
{
    struct node *temp=start;
    struct node *newNode;
    while(temp!=NULL && temp->data!=key)
        temp=temp->next;
    if(temp==NULL)
    {
        printf("Node not found!\n");
        return;
    }
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=value;
    newNode->next=temp->next;
    temp->next=newNode;
}
int main()
{
    int n,i,x,key,value;
    struct node *start=NULL,*temp=NULL,*newNode;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        newNode=(struct node*)malloc(sizeof(struct node));
        newNode->data=x;
        newNode->next=NULL;
        if(start==NULL)
        {
            start=newNode;
            temp=start;
        }
        else
        {
            temp->next=newNode;
            temp=newNode;
        }
    }
    scanf("%d",&key);
    scanf("%d",&value);
    insertAfter(start,key,value);
    display(start);
    return 0;
}