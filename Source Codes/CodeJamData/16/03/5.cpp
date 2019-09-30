#include <bits/stdc++.h>
using namespace std;

long long now;
int n = 14;
int k = 500;

long long compute(long long base, int mask) {
    long long res = 1;
    for (int i = 0; i < n; i++) {
        if ((mask & (1<<i)) != 0) {
            res = base * res + 1;
        } else {
            res = base * res;
        }
    }

    res = base * res + 1;
    return res;
}
int main() {
    printf("Case #1:\n");
    for (int i = 0; i < min(k, (1<<n)); i++) {
        printf("1");
        for (int j = 0; j < n; j++) {
            if ((i & (1<<j)) != 0) {
                printf("1");
            } else {
                printf("0");
            }
        }
        printf("1");
        printf("1");
        for (int j = 0; j < n; j++) {
            if ((i & (1<<j)) != 0) {
                printf("1");
            } else {
                printf("0");
            }
        }
        printf("1");
        for (int j = 2; j <= 10; j++) {
            printf(" %lld", compute(j, i));
        }
        printf("\n");
    }
    
}
