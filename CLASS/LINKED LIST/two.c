#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void sortedInsert(struct Node **head_ref,struct Node *new_node)
{
    struct Node *current;
    if(*head_ref==NULL || (*head_ref)->data>=new_node->data)
    {
        new_node->next=*head_ref;
        *head_ref=new_node;
    }
    else
    {
        current=*head_ref;
        while(current->next!=NULL && current->next->data<new_node->data)
            current=current->next;
        new_node->next=current->next;
        current->next=new_node;
    }
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
int main()
{
    int n,i,x;
    struct Node *head=NULL;
    struct Node *newNode;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        newNode=(struct Node*)malloc(sizeof(struct Node));
        newNode->data=x;
        newNode->next=NULL;
        sortedInsert(&head,newNode);
    }
    display(head);
    return 0;
}