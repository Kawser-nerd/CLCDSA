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
        const int a0 = a[i];
        const int a1 = a[i + 1];
        const int a2 = a[i + 2];
        const int a3 = a[i + 3];
        const int a4 = a[i + 4];
        const int a5 = a[i + 5];

        for (int j = 0; j < n; j++) {
            ans ^= a0 + b[j];
            ans ^= a1 + b[j];
            ans ^= a2 + b[j];
            ans ^= a3 + b[j];
            ans ^= a4 + b[j];
            ans ^= a5 + b[j];
        }
    }

    for (int i = m; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans ^= a[i] + b[j];
        }
    }

    printf("%d\n", ans);
}