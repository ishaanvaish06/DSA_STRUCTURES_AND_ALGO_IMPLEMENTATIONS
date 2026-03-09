
//ch.sc.u4aie25040
//Array-7: submatrix sum
#include <stdio.h>

int main() {
    int T, i, j;
    scanf("%d",&T);
    while(T--) {
        int n,m;
        scanf("%d %d",&n,&m);
        int C[n][m];
        for(i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                scanf("%d",&C[i][j]);
            }
        }
        int x1,y1,x2,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        int sum=0;
        for(i=x1-1;i<=x2-1;i++) {
            for(j=y1-1;j<=y2-1;j++) {
                sum+=C[i][j];
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}