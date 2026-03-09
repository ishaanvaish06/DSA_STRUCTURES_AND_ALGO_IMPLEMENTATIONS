//ch.sc.u4aie25020
//Array-1: numbers to martian symbols
#include <stdio.h>

void toMartian(int n) {
    char buf[50];
    int i = 0;

    while (n >= 1000) {
        buf[i++] = 'R';
        n -= 1000;
    }

    while (n >= 500) {
        buf[i++] = 'G';
        n -= 500;
    }

    while (n >= 100) {
        buf[i++] = 'B';
        n -= 100;
    }

    while (n >= 50) {
        buf[i++] = 'P';
        n -= 50;
    }

    while (n >= 10) {
        buf[i++] = 'Z';
        n -= 10;
    }

    while (n >= 5) {
        buf[i++] = 'W';
        n -= 5;
    }

    while (n >= 1) {
        buf[i++] = 'B';
        n -= 1;
    }

    buf[i] = '\0';
    printf("%s\n", buf);
}

int main() {
    int arr[5],i;
    for ( i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < 5; i++) {
        toMartian(arr[i]);
    }
    return 0;
}