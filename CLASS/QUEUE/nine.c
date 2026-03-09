//CH.SC.U4AIE25020
//Circular Queue using Linked List
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node *f=NULL;
struct node *r=NULL;
void enqueue(int d){
    struct node* next;
    struct node* n;
    n=(struct node*)malloc(sizeof(struct node));
    n->data=d;
    n->next=NULL;
    if(f==NULL){
        f=n;
        r=n;
        r->next=f;
    }
    else{
        r->next=n;
        r=n;
        r->next=f;
    }
}
void dequeue(){
    struct node* t;
    if(f==NULL)
        return;
    if(f==r){
        t=f;
        f=NULL;
        r=NULL;
        free(t);
    }
    else{
        t=f;
        f=f->next;
        r->next=f;
        free(t);
    }
}
void display(){
    struct node* t;
    if(f==NULL)
        return;
    t=f;
    do{
        printf("%d ",t->data);
        t=t->next;
    }
    while(t!=f);
    printf("\n");
}
int main(){
    int n,i,x;
    printf("Enter size of queue: ");
    scanf("%d",&n);
    printf("Enter queue elements:\n");
    for(i=0;i<n;i++){
        scanf("%d",&x);
        enqueue(x);
    }
    printf("Queue elements:\n");
    display();
    dequeue();
    printf("After first dequeue:\n");
    display();
    dequeue();
    printf("After second dequeue:\n");
    display();
    return 0;
}