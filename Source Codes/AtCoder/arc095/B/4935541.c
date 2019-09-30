#include <stdio.h>
#include <stdlib.h>

long long max(long long a, long long b) {
    if (a<b) return b;
    else return a;
}
long long min(long long a, long long b) {
    if (a>b) return b;
    else return a;
}

long long mindist(const long long n, long long a, long long b) {
    long long h = n/2;
    if (h%2) {
        if (min(llabs(h-a),llabs(h+1-a)) > min(llabs(h-b),llabs(h+1-b))) return b;
        else if (min(llabs(h-a),llabs(h+1-a)) == min(llabs(h-b),llabs(h+1-b))) return min(a,b);
        else return a;
    } else {
        if (llabs(h-a) > llabs(h-b)) return b;
        else if (llabs(h-a) == llabs(h-b)) return min(a,b);
        else return a;
    }
}

int main(void) {
    int i, N;
    long long a[100010], m, r;
    scanf("%d", &N);
    for (i=0;i<N;i++) scanf("%lld", &a[i]);

    m = a[0];
    for (i=1;i<N;i++) m = max(m,a[i]);
    r = a[0];
    for (i=1;i<N;i++) r = mindist(m,r,a[i]);

    printf("%lld %lld\n", m, r);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:29:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:30:23: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for (i=0;i<N;i++) scanf("%lld", &a[i]);
                       ^