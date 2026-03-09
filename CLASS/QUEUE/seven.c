//CH.SC.U4AIE25020
//Queue using Linked List

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node *f = NULL;
struct node *r = NULL;
void enqueue(int d)
{
    struct node* next;
    struct node* n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data = d;
    n->next = NULL;
    if(f==NULL)
    {
        f = n;
        r = n;
    }
    else
    {
        r->next = n;
        r = n;
    }
}
int dequeue()
{
    struct node* t;
    int x;
    if(f==NULL)
    {
        return -1;
    }
    t = f;
    x = t->data;
    f = f->next;
    free(t);
    return x;
}
void display()
{
    struct node* t;
    t = f;
    while(t!=NULL)
    {
        printf("%d\n",t->data);
        t = t->next;
    }
}
int main()
{
    int n,i,x;
    printf("Enter size of queue: ");
    scanf("%d",&n);
    printf("Enter queue elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        enqueue(x);
    }
    printf("Inserted elements in queue:\n");
    display();
    printf("Deleted element = %d\n",dequeue());
    return 0;
}