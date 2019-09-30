#include <stdio.h>
#include <stdlib.h>

// ????????????????
int main(int argc, char **argv)
{
    int n, m;
    scanf("%d %d", &n, &m);

    long long int *sum;
    sum = (long long int *) calloc(m + 1, sizeof(long long int));

    int l, r, s;
    long long int all = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &l, &r, &s);
        sum[l] += s;
        if (r + 1 <= m) {
            sum[r + 1] -= s;
        }
        all += s;
    }
    for (int i = 2; i <= m; ++i) {
        sum[i] += sum[i - 1];
    }

    long long int max = 0;
    for (int i = 1; i <= m; ++i) {
        long long int tmp = all - sum[i];
        if (tmp > max) {
            max = tmp;
        }
    }
    printf("%lld\n", max);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &m);
     ^
./Main.c:16:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d %d", &l, &r, &s);
         ^