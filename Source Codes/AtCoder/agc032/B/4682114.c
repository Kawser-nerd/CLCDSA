#include <stdio.h>

int main(void) {
    int i, j, k, M, N, a[10010], b[10010];
    scanf("%d", &N);
    M = N*(N-1)/2 - N/2;
    k = 0;
    for (i=1;i<=N;i++) for (j=i+1;j<=N;j++) {
        a[k] = i; b[k++] = j;
    }
    printf("%d\n", M);
    for (i=0;i<k;i++) {
        if ((N%2 && a[i]+b[i] == N) || (!(N%2) && a[i]+b[i] == N+1)) continue;
        printf("%d %d\n", a[i], b[i]);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^