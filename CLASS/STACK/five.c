//CH.SC.U4AIE25020
//Balanced Brackets Checking Using Stack
#include<stdio.h>
#include<string.h>
char stack[1000];
int top=-1;
void push(char x){
    stack[++top]=x;
}
char pop(){
    return stack[top--];
}
int empty(){
    if(top==-1)
        return 1;
    return 0;
}
int main(){
    char s[1000];
    int i,flag=1;
    scanf("%s",s);
    for(i=0;i<strlen(s);i++){
        if(s[i]=='('||s[i]=='{'||s[i]=='[')
            push(s[i]);
        else{
            if(empty())
            {
                flag=0;
                break;
            }
            char c=pop();
            if((s[i]==')'&&c!='(')||(s[i]=='}'&&c!='{')||(s[i]==']'&&c!='['))
            {
                flag=0;
                break;
            }
        }
    }
    if(flag && empty())
        printf("Balanced");
    else
        printf("Not Balanced");
}