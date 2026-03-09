//CH.SC.U4AIE25020
//Stock Span Problem Using Stack
#include<stdio.h>
void printArray(int arr[],int n){
    int i;
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}
void calculateSpan(int price[],int n,int S[]){
    int stack[1000];
    int top=-1;
    int i;
    stack[++top]=0;
    S[0]=1;
    for(i=1;i<n;i++){
        while(top>=0 && price[stack[top]]<=price[i])
            top--;
        if(top<0)
            S[i]=i+1;
        else
            S[i]=i-stack[top];
        stack[++top]=i;
    }
}
int main(){
    int n,i;
    int price[1000];
    int S[1000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&price[i]);
    calculateSpan(price,n,S);
    printArray(S,n);
    return 0;
}