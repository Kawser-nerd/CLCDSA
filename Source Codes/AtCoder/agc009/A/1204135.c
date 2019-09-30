#include <stdio.h>
typedef long long int i64;
i64 n, a[1<<17], b[1<<17];
i64 solve(void) {
    i64 cnt = 0;
    for(i64 i = n - 1; i >= 0; i--) {
        i64 k = (a[i] + cnt) % b[i];
        cnt += k ? b[i] - k : 0;
    }
    return cnt;
}
int main(void) {
    scanf("%d", &n);
    for(i64 i = 0; i < n; i++)
        scanf("%lld%lld", &a[i], &b[i]);
    printf("%lld", solve());
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:11: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘i64 * {aka long long int *}’ [-Wformat=]
     scanf("%d", &n);
           ^
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:15:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld%lld", &a[i], &b[i]);
         ^