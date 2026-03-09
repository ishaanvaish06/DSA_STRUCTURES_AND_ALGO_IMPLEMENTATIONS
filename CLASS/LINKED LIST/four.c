//CH.SC.U4AIE25020

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void insert_Data(struct node **head,int n)
{
    int i;
    struct node *temp=NULL,*newNode;
    for(i=1;i<=n;i++)
    {
        newNode=(struct node*)malloc(sizeof(struct node));
        newNode->data=i;
        newNode->next=NULL;
        if(*head==NULL)
        {
            *head=newNode;
            temp=*head;
        }
        else
        {
            temp->next=newNode;
            temp=newNode;
        }
    }
}
void delete_Alt(struct node **head)
{
    struct node *temp=*head,*del;
    while(temp!=NULL && temp->next!=NULL)
    {
        del=temp->next;
        temp->next=del->next;
        free(del);
        temp=temp->next;
    }
}
void display(struct node *head)
{
    while(head!=NULL)
    {
        printf("%d",head->data);
        head=head->next;
    }
}
int main()
{
    int n;
    struct node *head=NULL;
    scanf("%d",&n);
    insert_Data(&head,n);
    delete_Alt(&head);
    display(head);
    return 0;
}