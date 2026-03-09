//CH.SC.U4AIE25020
//Queue using Linked List
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *rear = NULL;
struct node *front = NULL;
void enqueue(int d) {
    struct node* new_n;
    new_n = (struct node*)malloc(sizeof(struct node));
    new_n->data=d;
    new_n->next=NULL;
    if(front==NULL) {
        front=new_n;
        rear=new_n;
    } else {
        rear->next=new_n;
        rear=new_n;
    }
}
void dequeue() {
    struct node *temp;
    if(front==NULL) {
        return;
    }
    temp=front;
    front=front->next;
    free(temp);
}
void print() {
    struct node *temp=front;
    while(temp!=NULL) {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main() {
    int n,i,x;
    printf("Enter size of queue: ");
    scanf("%d",&n);
    printf("Enter queue elements:\n");
    for(i=0; i<n; i++) {
        scanf("%d",&x);
        enqueue(x);
    }
    print();
    dequeue();
    print();
    return 0;
}