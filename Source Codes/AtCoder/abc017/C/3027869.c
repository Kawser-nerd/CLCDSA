#include <stdio.h>

typedef long long ll;

int n, m;
int l[100000], r[100000], s[100000];

int main() {
    scanf("%d%d", &n, &m);
    ll sum[100010] = {0};
    ll all = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", l + i, r + i, s + i);
        sum[l[i]] += s[i];
        sum[r[i] + 1] -= s[i];
        all += s[i];
    }
    ll sub = all;
    for (int i = 1; i <= m; i++) {
        sum[i] += sum[i-1];
        sub = sub > sum[i] ? sum[i] : sub;
    }
    printf("%lld\n", all - sub);
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &n, &m);
     ^
./Main.c:13:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d%d", l + i, r + i, s + i);
         ^