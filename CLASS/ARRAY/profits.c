
//ch.sc.u4aie25020
//profit case
#include <stdio.h>

int main() {
    int t,i;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        int arr[n];
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        int profit=0;
        for(i=1;i<n;i++) {
            if(arr[i]>arr[i-1]) {
                printf("(%d %d) ",i-1,i);
                profit=1;
            }
        }
        if(profit==0)
            printf("No Profit");
        printf("\n");
    }
    return 0;
}