//CH.SC.U4AIE25020
//Next Greater Element with Smaller Digit-Sum Query
#include<stdio.h>
int digitSum(long long x)
{
    int s=0;
    while(x>0)
    {
        s=s+(x%10);
        x=x/10;
    }
    return s;
}
int main()
{
    int n,q,i,j,x;
    long long arr[100005];
    int arr2[100005];
    int res[100005];
    scanf("%d%d",&n,&q);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&arr[i]);
        arr2[i]=digitSum(arr[i]);
    }
    for(i=0;i<q;i++)
    {
        scanf("%d",&x);
        int ans=-1;
        for(j=x+1;j<=n;j++)
        {
            if(arr[x]<arr[j])
            {
                if(arr2[x]>arr2[j])
                {
                    ans=j;
                    break;
                }
            }
        }
        res[i]=ans;
    }
    for(i=0;i<q;i++)
        printf("%d ",res[i]);
    return 0;
}
