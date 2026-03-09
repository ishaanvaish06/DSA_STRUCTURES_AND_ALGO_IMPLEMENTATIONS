//ch.sc.u4aie25020

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node* insertAtBeginning(struct node* head, int data) {
    struct node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

void printList(struct node* head) {
    printf("Linked list :-- >");
    while (head != NULL) {
        printf("%d -- >", head->data);
        head = head->next;
    }
    printf("\n");
}

int GetNth(struct node* head, int index) {
    int count = 0;
    while (head != NULL) {
        if (count == index) {
            return head->data;
        }
        count++;
        head = head->next;
    }
    return -1;
}

int main() {
    int N,index,data,i;
    struct node* head=NULL;

    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&data);
        head=insertAtBeginning(head,data);
    }
    scanf("%d",&index);

    printList(head);
    int result=GetNth(head,index);
    if(result!=-1)
        printf("Node at index=%d:%d\n",index,result);
    else
        printf("Index out of range!\n");

    return 0;
}