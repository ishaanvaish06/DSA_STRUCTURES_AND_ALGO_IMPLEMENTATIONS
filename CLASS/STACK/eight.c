//CH.SC.U4AIE25020
//Maximum XOR with Next Greater Elemen
#include<stdio.h>
long long arr[1000000];
long long st[1000000];
int main()
{
    int n,i,j;
    long long ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%lld",&arr[i]);
    for(i=0;i<n;i++)
    {
        st[i]=arr[i];
        for(j=i+1;j<n;j++)
        {
            if(arr[i]<arr[j])
            {
                st[i]=arr[i]^arr[j];
                break;
            }
        }
        if(st[i]>ans)
            ans=st[i];
    }
    printf("%lld",ans);
}
