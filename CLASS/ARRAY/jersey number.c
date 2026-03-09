//ch.sc.u4aie25020
//Array-5: jersey num alpha
#include <stdio.h>
#include <string.h>

int main() {
    char nums[13][256] = {
        "ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX",
        "SEVEN","EIGHT","NINE","TEN","ELEVEN","TWELVE"
    };
    int arr[100], n, i, j, k=0;
    while(1) {
        int x;
        scanf("%d",&x);
        arr[k++]=x;
        if(x==999) break;
    }
    for(i=0;i<k;i++)
        printf("%d ",arr[i]);
    printf(". ");
    int letters[26]={0};
    for(i=0;i<k;i++) {
        if(arr[i]>=0 && arr[i]<=12) {
            for(j=0;j<strlen(nums[arr[i]]);j++) {
                char c=nums[arr[i]][j];
                if(c>='A' && c<='Z')
                    letters[c-'A']++;
            }
        }
    }
    for(n=0;n<26;n++) {
        while(letters[n]--)
            printf("%c",n+'A');
    }
    return 0;
}