//#pragma GCC optimize("O3")
//#pragma GCC target ("avx")

#include <cstdio>
#include <cstdlib>

__attribute__((target("avx"))) int main() {
	int n;
    int a[200000], b[200000];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", b + i);
    }

    int ans = 0;
    int m = n / 6 * 6;

    for (int i = 0; i < m; i += 6) {
        for (int j = 0; j < n; j++) {
            ans ^= a[i] + b[j];
            ans ^= a[i + 1] + b[j];
            ans ^= a[i + 2] + b[j];
            ans ^= a[i + 3] + b[j];
            ans ^= a[i + 4] + b[j];
            ans ^= a[i + 5] + b[j];
        }
    }

    for (int i = m; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans ^= a[i] + b[j];
        }
    }

    printf("%d\n", ans);
}