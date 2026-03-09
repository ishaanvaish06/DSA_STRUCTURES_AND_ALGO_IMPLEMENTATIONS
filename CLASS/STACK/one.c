//CH.SC.U4AIE25020
//Two-pointer array comparison game (start vs end element selection)
#include<stdio.h>
long long a[1000000];
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%lld",&a[i]);
    i=0;
    j=n-1;
    while(i<n && j>=0)
    {
        if(a[i]>a[j])
        {
            printf("1 ");
            j--;
        }
        else if(a[i]<a[j])
        {
            printf("2 ");
            i++;
        }
        else
        {
            printf("0 ");
            i++;
            j--;
        }
    }
    return 0;
}