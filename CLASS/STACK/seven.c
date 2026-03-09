//CH.SC.U4AIE25020
//Next Greater Element followed by Next Smaller Element
#include<stdio.h>
int main(){
    int n,i,j,k;
    long long a[3005];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%lld",&a[i]);
    for(i=0;i<n;i++){
        int f=-1;
        for(j=i+1;j<n;j++){
            if(a[j]>a[i]){
                f=j;
                break;
            }
        }
        if(f==-1){
            printf("-1 ");
            continue;}
        int g=-1;
        for(k=f+1;k<n;k++)
            if(a[k]<a[f]){
                g=k;
                break;}
        if(g==-1)
            printf("-1 ");
        else
            printf("%lld ",a[g]);
    }
}