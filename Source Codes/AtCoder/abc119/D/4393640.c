#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

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

int binary(long long *src, int len, long long trg) {
    // assumed src[0..len+1] 
    int low, hi, mid;
    low = 0; hi = len+1;
    while (low < hi) {
        mid = low + (hi-low)/2;
        if (trg < *(src+mid)) hi = mid;
        else low = mid+1;
    }
    return low;
}

#define INF 1000000000000000000LL

int main(void) {
    int i, j, k, l, m, n, A, B, Q;
    long long s[100010], t[100010], x, res, d1, d2;
    scanf("%d%d%d", &A, &B, &Q);
    for (i=1;i<=A;i++) scanf("%lld", &s[i]);
    s[0] = -INF; s[A+1] = INF;
    for (j=1;j<=B;j++) scanf("%lld", &t[j]);
    t[0] = -INF; t[B+1] = INF;

    for (i=1;i<=Q;i++) {
        scanf("%lld", &x);
        k = binary(s, A, x);
        l = binary(t, B, x);
        res = INF;
        for (m=k-1;m<=k;m++) for (n=l-1;n<=l;n++) {
            d1 = llabs(s[m] - x) + llabs(t[n] - s[m]);
            d2 = llabs(t[n] - x) + llabs(s[m] - t[n]);
            res = min( 3, res, d1, d2);
        }
        printf("%lld\n", res);
    }

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:37:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d", &A, &B, &Q);
     ^
./Main.c:38:24: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for (i=1;i<=A;i++) scanf("%lld", &s[i]);
                        ^
./Main.c:40:24: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for (j=1;j<=B;j++) scanf("%lld", &t[j]);
                        ^
./Main.c:44:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld", &x);
         ^