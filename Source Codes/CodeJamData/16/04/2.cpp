#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int tt, k, c, s;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &tt);
    for (int test = 1; test <= tt; ++test) {
        printf("Case #%d: ", test);
        scanf("%d%d%d", &k, &c, &s);
        if (s < (k + c - 1) / c) {
            printf("IMPOSSIBLE\n");
            continue;
        }
        for (int i = 0; i < k; i += c) {
            LL val = 0;
            for (int jj = i; jj < i + c; ++jj) {
                int j = jj % k;
                val = k * val + j;
            }
            printf("%I64d ", val + 1);
        }
        printf("\n");
    }
    return 0;
}
