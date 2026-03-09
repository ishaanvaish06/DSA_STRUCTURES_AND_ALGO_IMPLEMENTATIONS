//CH.SC.U4AIE25020

#include<stdio.h>
#include<stdlib.h>
struct n{int data;struct n*next;};
struct n*head=NULL;
void insert(int data){
    struct n*newnode,*p1;
    newnode=(struct n*)malloc(sizeof(struct n));
    newnode->data=data;
    if(head==NULL){head=newnode;newnode->next=head;return;}
    p1=head;
    while(p1->next!=head){p1=p1->next;}
    p1->next=newnode;
    newnode->next=head;
}
void display(struct n*h){
    struct n*p1=h;
    printf("[h]");
    do{printf("=>%d",p1->data);p1=p1->next;}while(p1!=h);
    printf("=>[h]\n");
}
void separate(){
    struct n*p1=head;
    printf("Odd:\n[h]");
    do{if(p1->data%2!=0)printf("=>%d",p1->data);p1=p1->next;}while(p1!=head);
    printf("=>[h]\n");
    p1=head;
    printf("Even:\n[h]");
    do{if(p1->data%2==0)printf("=>%d",p1->data);p1=p1->next;}while(p1!=head);
    printf("=>[h]\n");
}
int main(){
    int n,i;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)insert(i);
    printf("Complete linked_list:\n");
    display(head);
    separate();
    return 0;
}