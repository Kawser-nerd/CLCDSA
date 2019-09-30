#include <stdio.h>
#include <limits.h>

int main(void)
{
    int N, M, l, r, s, i, arry[1000002] = {0}, sum = 0, min = INT_MAX;

    scanf("%d%d", &N, &M);
    for(i=0; i<N; i++) {
        scanf("%d%d%d", &l, &r, &s);
        sum += s;
        arry[l] += s;
        arry[r+1] -= s;
    }
    for(i=1; i<=1000000; i++) {
        arry[i] += arry[i-1];
    }
    for(i=1; i<=M; i++) {
        if(arry[i]<min)  min = arry[i];
    }
    printf("%d\n", sum - min);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &N, &M);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d%d", &l, &r, &s);
         ^