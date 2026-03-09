//ch.sc.u4aie25020

#include<stdio.h>
#include<stdlib.h>
struct node{int data;struct node*next;};
struct node*head=NULL;
void create(int n){
    struct node*newnode,*p1;int i,val;
    for(i=0;i<n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&val);
        newnode->data=val;
        newnode->next=NULL;
        if(head==NULL){head=newnode;p1=head;}
        else{p1->next=newnode;p1=newnode;}
    }}
void deletek(int k){
    struct node*p1=head;int i;
    for(i=0;i<k && p1!=NULL;i++){p1=p1->next;}
    head=p1;
}
void display(){
    struct node*p1=head;
    printf("Linked List:");
    while(p1!=NULL){
        printf("->%d",p1->data);
        p1=p1->next;
    }
    printf("\n");
}
int main(){
    int n,k;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    printf("Enter elements:\n");
    create(n);
    printf("Enter k value: ");
    scanf("%d",&k);
    deletek(k);
    display();
    return 0;
}