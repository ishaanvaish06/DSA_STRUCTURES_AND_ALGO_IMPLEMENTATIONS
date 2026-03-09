//CH.SC.U4AIEA25020
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void insertStart(struct Node **head,int data)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=*head;
    if(*head!=NULL)
        (*head)->prev=newNode;
    *head=newNode;
}

void display(struct Node *head)
{
    struct Node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

struct Node* reverse(struct Node *head)
{
    struct Node *temp=NULL;
    struct Node *current=head;
    while(current!=NULL)
    {
        temp=current->prev;
        current->prev=current->next;
        current->next=temp;
        current=current->prev;
    }
    if(temp!=NULL)
        head=temp->prev;
    return head;
}

int main()
{
    int n,i,x;
    struct Node *head=NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        insertStart(&head,x);
    }
    display(head);
    head=reverse(head);
    display(head);
    return 0;
}