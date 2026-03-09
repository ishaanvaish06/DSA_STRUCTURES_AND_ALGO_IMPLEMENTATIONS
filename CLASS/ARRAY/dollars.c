
//ch.sc.u4aie25020
//Array-6: item dollar calculation
#include <stdio.h>
#include <string.h>

#define MAX 10
#define LEN 100

int main(){
    int dollar, items, i;
    scanf("%d %d",&dollar,&items);
    char name[MAX][LEN];
    int price[MAX], afford[MAX];
    for(i=0;i<items;i++) {
        scanf("%s %d",name[i],&price[i]);
        afford[i]=0;
    }
    int spent=0;
    for(i=0;i<items;i++) {
        if(price[i]<=dollar-spent) {
            afford[i]=1;
            spent+=price[i];
        }
    }
    int any=0;
    for(i=0;i<items;i++) {
        if(afford[i]) {
            printf("I can afford %s\n",name[i]);
            any=1;
        } else {
            printf("I can't afford %s\n",name[i]);
        }
    }
    if(!any) {
        printf("I need more Dollar!\n");
    } else {
        printf("%d\n",dollar-spent);
    }
    return 0;
}