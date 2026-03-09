//CH.SC.U4AIE25020
//Product of three largest numbers

#include<stdio.h>
int main()
{
    int n,i,j;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the array elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int biggest,second,third,big;
    for(i=0;i<n;i++)
    {
        if(i<2)
        {
            printf("-1\n");
        }
        else
        {
            biggest=-1;
            second=-1;
            third=-1;
            for(j=0;j<=i;j++)
            {
                big=a[j];
                if(biggest<big)
                {
                    third=second;
                    second=biggest;
                    biggest=big;
                }
                else
                {
                    if(a[j]>biggest)
                    {
                        biggest=a[j];
                    }
                    else if(a[j]>second)
                    {
                        third=second;
                        second=a[j];
                    }
                    else if(a[j]>third)
                    {
                        third=a[j];
                    }
                }
            }
            printf("%d\n",biggest*second*third);
        }
    }
    return 0;
}