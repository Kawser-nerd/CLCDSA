#include <stdio.h>
typedef long long ll;

int main() {
    ll table[101];
    table[0] = 1;
    for (ll i = 1; i < 101; i++) table[i] = table[i-1] * i;
    int n, c[128]; scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", c + i);
    int cnt[128];
    for (int i = 0; i < n; i++) {
        cnt[i] = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (c[i] % c[j] == 0) cnt[i]++;
        }
    }
    double ret = 0;
    for (int i = 0; i < n; i++) {
        if (cnt[i] % 2 == 1) ret += 0.5;
        else ret += ((double)cnt[i] + 2.0) / (2.0 * (double)cnt[i] + 2.0);
    }
    printf("%lf\n", ret);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     int n, c[128]; scanf("%d", &n);
                    ^
./Main.c:9:33: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for (int i = 0; i < n; i++) scanf("%d", c + i);
                                 ^