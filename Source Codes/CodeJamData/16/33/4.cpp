#include <bits/stdc++.h>

using namespace std;

void Solve() {
    int a, b, c, k;
    scanf("%d%d%d%d", &a, &b, &c, &k); 
    printf("%d\n", a * b * min(c, k));
    k = min(c, k);
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            for (int t = (i + j) % c, p = 0; p < k; ++p, ++t) {
                if (t == c) t = 0;
                printf("%d %d %d\n", i + 1, j + 1, t + 1);
            }
        }
    }
}

int main() {
    freopen("C.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; scanf("%d", &t);
    for(int i = 1; i <= t; ++i) {
        printf("Case #%d: ", i);
        Solve();
    }
}
