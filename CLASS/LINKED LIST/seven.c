//ch.sc.u4aie25020

#include<stdio.h>
#include<stdlib.h>
struct node{int data;struct node*next;};
void create(struct node **head,int data){
    struct node *newnode,*p1;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    if(*head==NULL){*head=newnode;return;}
    p1=*head;
    while(p1->next!=NULL){p1=p1->next;}
    p1->next=newnode;
}
void print(struct node *head){
    struct node *p1=head;
    printf("Link list data:");
    while(p1!=NULL){printf("%d ",p1->data);p1=p1->next;}
    printf("\n");
}
void fold(struct node *head,int n){
    int arr[1000],i=0;
    struct node *p1=head;
    while(p1!=NULL){arr[i++]=p1->data;p1=p1->next;}
    int l=0,r=n-1;
    printf("Link list data after fold:");
    while(l<=r){
        if(l==r){printf("%d ",arr[l]);break;}
        printf("%d %d ",arr[l],arr[r]);
        l++;r--;
    }
    printf("\n");
}
int main(){
    struct node *head=NULL;
    int n,x,i;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    printf("Enter elements:\n");
    for(i=0;i<n;i++){scanf("%d",&x);create(&head,x);}
    print(head);
    fold(head,n);
    return 0;
}