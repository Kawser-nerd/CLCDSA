#include <stdio.h>

int main(void)
{
    int R, C, K, N, r[100000], c[100000], r_sum[100001] = {0}, c_sum[100001] = {0},
        X[100001] = {0}, Y[100001] = {0}, i, j;
    long int ans = 0;

    scanf("%d%d%d%d", &R, &C, &K, &N);
    for(i=0; i<N; i++) {
        scanf("%d%d", &r[i], &c[i]);
        r_sum[r[i]]++;
        c_sum[c[i]]++;
    }
    for(i=0; i<R; i++) {
        X[r_sum[i+1]]++;
    }
    for(i=0; i<C; i++) {
        Y[c_sum[i+1]]++;
    }
    for(i=0; i<=K; i++) {
        ans += X[i]*Y[K-i];
    }
    for(i=0; i<N; i++) {
        if(r_sum[r[i]] + c_sum[c[i]] == K+1)  ans++;
        if(r_sum[r[i]] + c_sum[c[i]] == K)  ans--;
    }
    printf("%ld\n", ans);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d", &R, &C, &K, &N);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d", &r[i], &c[i]);
         ^