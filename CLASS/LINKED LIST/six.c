//ch.sc.u4aie25020

#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
void create(int n){
    struct node *p1,*newnode;
    int i,val;
    for(i=0;i<n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter element %d: ",i+1);
        scanf("%d",&val);
        newnode->data=val;
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
            p1=head;
        }
        else{
            p1->next=newnode;
            p1=newnode;
        }
    }
}
void del(int key){
    struct node *p1=head;
    while(p1!=NULL && p1->data!=key){
        p1=p1->next;
    }
    if(p1==NULL){
        printf("Invalid Node!\n");
        return;
    }
    head=p1;
}
void display(){
    struct node *p1=head;
    printf("Linked List:");
    while(p1!=NULL){
        printf("->%d",p1->data);
        p1=p1->next;
    }
    printf("\n");
}
int main(){
    int n,key;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    create(n);
    printf("Enter key node: ");
    scanf("%d",&key);
    del(key);
    display();
    return 0;
}