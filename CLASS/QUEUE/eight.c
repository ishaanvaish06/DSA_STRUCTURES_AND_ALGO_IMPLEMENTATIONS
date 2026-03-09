//CH.SC.U4AIE25020
//LRU Cache using Queue and Doubly Linked List
#include<stdio.h>
#include<stdlib.h>
typedef struct QNode
{
    unsigned pageNumber;
    struct QNode* prev;
    struct QNode* next;
}QNode;
typedef struct Queue
{
    int count;
    int numberOfFrames;
    QNode* front;
    QNode* rear;
}Queue;
QNode* newQNode(unsigned pageNumber)
{
    QNode* temp=(QNode*)malloc(sizeof(QNode));
    temp->pageNumber=pageNumber;
    temp->prev=NULL;
    temp->next=NULL;
    return temp;
}
Queue* createQueue(int numberOfFrames)
{
    Queue* queue=(Queue*)malloc(sizeof(Queue));
    queue->count=0;
    queue->front=NULL;
    queue->rear=NULL;
    queue->numberOfFrames=numberOfFrames;
    return queue;
}
void moveToFront(Queue* queue,QNode* node)
{
    if(queue->front==node)
    return;
    if(node->prev)
    node->prev->next=node->next;
    if(node->next)
    node->next->prev=node->prev;
    if(queue->rear==node)
    queue->rear=node->prev;
    node->next=queue->front;
    node->prev=NULL;
    if(queue->front)
    queue->front->prev=node;
    queue->front=node;
}
void enqueue(Queue* queue,unsigned pageNumber)
{
    QNode* node=newQNode(pageNumber);
    if(queue->count==queue->numberOfFrames)
    {
        QNode* temp=queue->rear;
        queue->rear=queue->rear->prev;
        if(queue->rear)
        queue->rear->next=NULL;
        free(temp);
        queue->count--;
    }
    node->next=queue->front;
    if(queue->front)
    queue->front->prev=node;
    queue->front=node;
    if(queue->rear==NULL)
    queue->rear=node;
    queue->count++;
}
QNode* search(Queue* queue,unsigned pageNumber)
{
    QNode* temp=queue->front;
    while(temp)
    {
        if(temp->pageNumber==pageNumber)
        return temp;
        temp=temp->next;
    }
    return NULL;
}
void referencePage(Queue* queue,unsigned pageNumber)
{
    QNode* reqPage=search(queue,pageNumber);
    if(reqPage==NULL)
    enqueue(queue,pageNumber);
    else
    moveToFront(queue,reqPage);
}
void display(Queue* queue)
{
    QNode* temp=queue->front;
    printf("Cache Frames: ");
    while(temp)
    {
        printf("%d ",temp->pageNumber);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    int n,m,i,page;
    printf("Enter number of pages and cache size:\n");
    scanf("%d %d",&n,&m);
    Queue* queue=createQueue(m);
    printf("Enter page reference string:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&page);
        referencePage(queue,page);
    }
    printf("Final cache content:\n");
    display(queue);
    return 0;
}