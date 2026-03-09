//CH.SC.U4AIE25020
//Postfix to Prefix Expression Conversion Using Stack
#include<stdio.h>
#include<string.h>
char stack[100][100];
int top=-1;
void push(char s[]){
    strcpy(stack[++top],s);
}
char* pop(){
    return stack[top--];
}
int isOperator(char c){
    if(c=='+'||c=='-'||c=='*'||c=='/')
        return 1;
    return 0;
}
int main(){
    char exp[100];
    int i;
    scanf("%s",exp);
    for(i=0;i<strlen(exp);i++)
    {
        if(!isOperator(exp[i]))
        {
            char s[2];
            s[0]=exp[i];
            s[1]='\0';
            push(s);
        }
        else
        {
            char op1[100],op2[100],res[200];
            strcpy(op2,pop());
            strcpy(op1,pop());
            res[0]=exp[i];
            res[1]='\0';
            strcat(res,op1);
            strcat(res,op2);
            push(res);
        }
    }
    printf("%s",pop());
}