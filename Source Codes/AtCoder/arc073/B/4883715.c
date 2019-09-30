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
    long long (*dp)[k+1][l+1][m+1] = (long long(*)[k+1][l+1][m+1])malloc((j+1)*(k+1)*(l+1)*(m+1)*sizeof(long long));
    long long (*weight)[k+1][l+1][m+1] = (long long(*)[k+1][l+1][m+1])malloc((j+1)*(k+1)*(l+1)*(m+1)*sizeof(long long));
    memset(dp,0,sizeof(dp));
    memset(weight,0,sizeof(weight));
    for (a=0;a<=j;a++) for (b=0;b<=k;b++) for (c=0;c<=l;c++) for (d=0;d<=m;d++) {
        if (a>0) if (weight[a-1][b][c][d] + w[0] <= W && dp[a][b][c][d] < dp[a-1][b][c][d] + w0[a]) {
//            printf("%d\n", w0[a]);
            dp[a][b][c][d] = dp[a-1][b][c][d] + w0[a];
            weight[a][b][c][d] = weight[a-1][b][c][d] + w[0];
        } else if (dp[a][b][c][d] < dp[a-1][b][c][d]) {
            dp[a][b][c][d] = dp[a-1][b][c][d];
            weight[a][b][c][d] = weight[a-1][b][c][d];
        }
        if (b>0) if (weight[a][b-1][c][d] + w[0]+1 <= W && dp[a][b][c][d] < dp[a][b-1][c][d] + w1[b]) {
            dp[a][b][c][d] = dp[a][b-1][c][d] + w1[b];
            weight[a][b][c][d] = weight[a][b-1][c][d] + w[0]+1;
        } else if (dp[a][b][c][d] < dp[a][b-1][c][d]) {
            dp[a][b][c][d] = dp[a][b-1][c][d];
            weight[a][b][c][d] = weight[a][b-1][c][d];
        }
        if (c>0) if (weight[a][b][c-1][d] + w[0]+2 <= W && dp[a][b][c][d] < dp[a][b][c-1][d] + w2[c]) {
            dp[a][b][c][d] = dp[a][b][c-1][d] + w2[c];
            weight[a][b][c][d] = weight[a][b][c-1][d] + w[0]+2;
        } else if (dp[a][b][c][d] < dp[a][b][c-1][d]) {
            dp[a][b][c][d] = dp[a][b][c-1][d];
            weight[a][b][c][d] = weight[a][b][c-1][d];
        }
        if (d>0) if (weight[a][b][c][d-1] + w[0]+3 <= W && dp[a][b][c][d] < dp[a][b][c][d-1] + w3[d]) {
            dp[a][b][c][d] = dp[a][b][c][d-1] + w3[d];
            weight[a][b][c][d] = weight[a][b][c][d-1] + w[0]+3;
        } else if (dp[a][b][c][d] < dp[a][b][c][d-1]) {
            dp[a][b][c][d] = dp[a][b][c][d-1];
            weight[a][b][c][d] = weight[a][b][c][d-1];
        }
//        printf("%d,%d,%d,%d:%lld\n",a,b,c,d,dp[a][b][c][d]);
    }

    printf("%lld\n", dp[j][k][l][m]);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:32:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%lld", &N, &W);
     ^
./Main.c:33:23: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for (i=0;i<N;i++) scanf("%lld%d", &w[i], &v[i]);
                       ^