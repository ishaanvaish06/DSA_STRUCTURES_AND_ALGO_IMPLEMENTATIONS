//ch.sc.u4aie25020
//infix to prefix

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top=-1;

void push(char c){
    stack[++top]=c;
}

char pop(){
    return stack[top--];
}

int priority(char c){
    if(c=='+' || c=='-')
        return 1;
    if(c=='*' || c=='/')
        return 2;
    if(c=='^')
        return 3;
    return 0;
}
void reverse(char exp[]){
    int i,j;
    char temp;
    int len=strlen(exp);
    for(i=0,j=len-1;i<j;i++,j--){
        temp=exp[i];
        exp[i]=exp[j];
        exp[j]=temp;
    }
}
int main(){
    char infix[MAX],prefix[MAX];
    int i,j=0;
    printf("Enter Infix Expression: ");
    scanf("%s",infix);

    reverse(infix);
    for(i=0;infix[i];i++){
        if(infix[i]=='(')
            infix[i]=')';
        else if(infix[i]==')')
            infix[i]='(';
    }
    for(i=0;infix[i]!='\0';i++){
        if(isalnum(infix[i]))
            prefix[j++]=infix[i];
        else if(infix[i]=='(')
            push(infix[i]);
        else if(infix[i]==')'){
            while(stack[top]!='(')
                prefix[j++]=pop();
            pop();
        }
        else{
            while(top!=-1 && priority(stack[top])>=priority(infix[i]))
                prefix[j++]=pop();
            push(infix[i]);
        }
    }

    while(top!=-1)
        prefix[j++]=pop();

    prefix[j]='\0';

    reverse(prefix);

    printf("Prefix Expression: %s",prefix);

    return 0;
}