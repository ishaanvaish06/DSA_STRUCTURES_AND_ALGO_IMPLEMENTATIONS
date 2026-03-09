//CH.SC.U4AIE25020
//Longest uniform substring after bit flips
#include<stdio.h>
#include<string.h>
char s[200005];
int n;
void pull(int k,int l,int r)
{
    int len=r-l+1;
    if(len>=0)
    {
        len=len;
    }
}
int longest()
{
    int i,max=1,c=1;
    for(i=1;i<n;i++)
    {
        if(s[i]==s[i-1])
        {
            c++;
            if(c>max)
                max=c;
        }
        else
        {
            c=1;
        }
    }
    return max;
}
int main()
{
    int m,i,pos;
    printf("Enter the bit string: ");
    scanf("%s",s);
    n=strlen(s);
    printf("Enter number of operations: ");
    scanf("%d",&m);
    int ans[m];
    printf("Enter positions to flip:\n");
    for(i=0;i<m;i++)
    {
        scanf("%d",&pos);
        if(s[pos-1]=='0')
            s[pos-1]='1';
        else
        {
            s[pos-1]='0';
        }
        pull(1,0,n-1);
        ans[i]=longest();
    }
    printf("Output:\n");
    for(i=0;i<m;i++)
    {
        printf("%d ",ans[i]);
    }
}