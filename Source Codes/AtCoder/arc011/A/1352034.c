#include <stdio.h>

int main(void){
    int m, n, N;
    scanf("%d %d %d", &m, &n, &N);
    int ans = N;
    while(N>=m){
        int a = n*(N/m);
        N = N%m + a;
        ans += a;
    }

    printf("%d\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d", &m, &n, &N);
     ^