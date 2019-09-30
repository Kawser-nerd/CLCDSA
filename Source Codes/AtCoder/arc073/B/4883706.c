#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N, v[110];
long long W, w[110], w0[110], w1[110], w2[110], w3[110];

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

int llcmp(const void *a, const void *b) {
    if (*(long long *)a < *(long long *)b) return 1;
    else if (*(long long *)a > *(long long *)b) return -1;
    else return 0;
}

int main(void) {
    int a, b, c, d, i, j, k, l, m;
    long long res, weight;
    scanf("%d%lld", &N, &W);
    for (i=0;i<N;i++) scanf("%lld%d", &w[i], &v[i]);

    j = 0; k = 0; l = 0; m = 0;
    for (i=0;i<N;i++) {
        if (w[i] == w[0]) w0[++j] = v[i];
        else if (w[i] == w[0]+1) w1[++k] = v[i];
        else if (w[i] == w[0]+2) w2[++l] = v[i];
        else w3[++m] = v[i];
    }
    qsort(w0+1,j,sizeof(long long),llcmp);
    qsort(w1+1,k,sizeof(long long),llcmp);
    qsort(w2+1,l,sizeof(long long),llcmp);
    qsort(w3+1,m,sizeof(long long),llcmp);
    for (a=1;a<=j;a++) w0[a] += w0[a-1];
    for (b=1;b<=k;b++) w1[b] += w1[b-1];
    for (c=1;c<=l;c++) w2[c] += w2[c-1];
    for (d=1;d<=m;d++) w3[d] += w3[d-1]; 
    res = 0; weight = 0;
    for (a=0;a<=j;a++) for (b=0;b<=k;b++) for (c=0;c<=l;c++) for (d=0;d<=m;d++) {
        weight = w[0]*a + (w[0]+1)*b + (w[0]+2)*c + (w[0]+3)*d;
        if (weight <= W) res = max(2,res,w0[a]+w1[b]+w2[c]+w3[d]);
    }

    printf("%lld\n", res);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:33:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%lld", &N, &W);
     ^
./Main.c:34:23: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for (i=0;i<N;i++) scanf("%lld%d", &w[i], &v[i]);
                       ^