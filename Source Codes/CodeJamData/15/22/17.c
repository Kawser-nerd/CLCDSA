/* 
 
Google Code Jam Round 1B
May 2, 2015

Jesse Pritchard
Public contact: chaserdevelopment@gmail.com
 
Problem B

*/

#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int iterate(int* a, int N, int R, int C, int l) {
    int min = N * 4;
    if (l < N - 1) {
        while(a[l] < a[l+1]) {
            a[l + 1] = a[l] + 1;
            if (a[l + 1] < R*C && a[l] < a[l+1]) {
                int t = iterate(a, N, R, C, l + 1);
                min = t < min ? t : min;
            }
            a[l]++;
        }
        a[l]--;
    }
    else {
        while (a[l] < R*C) {
            int unhappiness = 0;
            int k, m;
            for (k = 0; k < N; k++) {
                for (m = k+1; m < N; m++) {
                    unhappiness += (a[m] == a[k] + 1 && a[m] % C) + (a[m] == a[k] + C);
                }
            }
            a[l]++;
            min = min < unhappiness ? min : unhappiness;
        }
        a[l]--;
    }
    return min;
}


int main() {
    int num, iii;
    scanf(" %d", &num);
    for (iii = 0; iii < num; iii++) {
        int R, C, N;
        scanf(" %d %d %d", &R, &C, &N);
        int a[N], i;
        for (i = 0; i < N; i++) {
            a[i]=i;
        }
        printf("Case #%d: %d\n", iii + 1, iterate(a, N, R, C, 0));
    }
    return 0;
}
