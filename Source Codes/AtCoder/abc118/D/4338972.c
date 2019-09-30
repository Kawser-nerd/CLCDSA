#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF -(1<<20)

int max(int len, ...) {
    int i, _max, num;
    va_list ap;
    va_start(ap, len);

    _max = va_arg(ap, int);
    for (i = 1; i < len; i++) {
        num = va_arg(ap, int);
        if (num > _max)
            _max = num;
    }
    va_end(ap);
    return _max;
}

int C[10] = {0,2,5,5,4,5,6,3,7,6};

int desc(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int main(void) {
    int flag, i, j, K, min, N, M, A[10], AS[10], dp[100010];
    scanf("%d%d", &N, &M);
    for (i=1;i<=M;i++) scanf("%d",&A[i]);

//    memmove(AS,A,sizeof(int)*10);

    dp[0] = 0;
    flag = 0;
    for (i=1;i<=N;i++) {
        dp[i] = INF;
        for (j=1;j<=M;j++) {
            if (i-C[A[j]] >= 0) {
                dp[i] = max( 2, dp[i], dp[i-C[A[j]]] );
                flag = 1;
            }
        }
        if (flag) dp[i] += 1;
    }

    K = N;
    memmove(AS,A,sizeof(int)*10);
    qsort(AS+1,9,sizeof(int),desc);
    while (K>0) {
        for (j=1;j<=M;j++) {
//            printf("%d %d\n", K, K-C[AS[j]]);
            if (K-C[AS[j]] >= 0) { //printf(" %d %d\n", dp[K], dp[K-C[AS[j]]]);
                if (dp[K] == dp[K-C[AS[j]]] + 1) {
                    printf("%d", AS[j]); 
                    K -= C[AS[j]];
                    break;
                }
            }
        }
    }
    printf("\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:31:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &N, &M);
     ^
./Main.c:32:24: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for (i=1;i<=M;i++) scanf("%d",&A[i]);
                        ^