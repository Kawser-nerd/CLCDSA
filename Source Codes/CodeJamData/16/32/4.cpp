#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void Solve() {
    int n; ll m;
    scanf("%d%Ld", &n, &m);
    if (m > (1ll << (n - 2))) {
        printf("IMPOSSIBLE\n");
        return;
    }
    printf("POSSIBLE\n");
    if (m == (1ll << (n - 2))) {
        printf("0");
        for (int i = 1; i < n; ++i) printf("1");
        printf("\n");
    } else {
        printf("0");
        for (int i = n - 3; i >= 0; --i) {
            if (m & (1ll << i)) {
                printf("1");
            } else {
                printf("0");
            }
        }
        printf("0");
        printf("\n");
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j > i) printf("1");
            else printf("0");
        }
        printf("\n");
    }
}

int main() {
    freopen("B.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {
        printf("Case #%d: ", i);
        Solve();
    }
}
