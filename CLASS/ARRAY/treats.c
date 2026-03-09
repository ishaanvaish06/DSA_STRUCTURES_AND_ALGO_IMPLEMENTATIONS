//ch.sc.u4aie25020
//Array-10: Bear Grylls sorting treats for animals
#include <stdio.h>

#define MAXN 105
#define MAXT 105

int results[MAXT];

void sol(int index) {
    int N, i, j, temp;
    scanf("%d", &N);
    int s[MAXN];
    for(i=0; i<N; i++) {
        scanf("%d", &s[i]);
    }
    for(i=0; i<N-1; i++) {
        for(j=0; j<N-i-1; j++) {
            if(s[j] > s[j+1]) {
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
    int treats = 0;
    int current = 1;
    treats += current;
    for(i=1; i<N; i++) {
        if(s[i] == s[i-1]) {
            treats += current;
        } else {
            current++;
            treats += current;
        }
    }
    results[index] = treats;
}

int main() {
    int T, t;
    scanf("%d", &T);
    for(t=0; t<T; t++) {
        sol(t);
    }
    for(t=0; t<T; t++) {
        printf("%d\n", results[t]);
    }
    return 0;
}