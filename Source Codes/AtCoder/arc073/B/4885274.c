#include <stdarg.h>
#include <stdio.h>
#include <string.h>

long long max(int len, ...) {
    long long i, _max, num;
    va_list ap;
    va_start(ap, len);
 
    _max = va_arg(ap, long long);
    for (i = 1; i < len; i++) {
        num = va_arg(ap, long long);
        if (num > _max)
            _max = num;
    }
    va_end(ap);
    return _max;
}
long long min(int len, ...) {
    long long i, _min, num;
    va_list ap;
    va_start(ap, len);
 
    _min = va_arg(ap, long long);
    for (i = 1; i < len; i++) {
        num = va_arg(ap, long long);
        if (num < _min)
            _min = num;
    }
    va_end(ap);
    return _min;
}
int main(void) {
    int i, j, k, N;
    long long W, res, l, w0, w[110], v[110], dp[110][310];
    scanf("%d%lld", &N, &W);
    for (i=0;i<N;i++) scanf("%lld%lld", &w[i], &v[i]);
    w0 = w[0];
    for (i=0;i<N;i++) w[i] -= w0;

    memset(dp,-1,sizeof(dp));
    dp[0][0] = 0;
    dp[1][0] = v[0];
    for (i=1;i<N;i++) {
        for (j=i;j>=0;j--) {
            for (k=299-w[i];k>=0;k--) {
                if (dp[j][k] != -1) dp[j+1][k+w[i]] = max(2,dp[j+1][k+w[i]],dp[j][k]+v[i]);
            }
        }
    }
    res = -1LL;
    for (i=0;i<=N;i++) {
        for (l=min(2,299,W-w0*i);l>=0;l--) res = max(2,res,dp[i][l]);
    }
    printf("%lld\n", res);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:36:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%lld", &N, &W);
     ^
./Main.c:37:23: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for (i=0;i<N;i++) scanf("%lld%lld", &w[i], &v[i]);
                       ^