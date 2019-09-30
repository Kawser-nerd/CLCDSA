#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int tt, n, j;
int ans[11];

bool p[10000];
vector<int> pr;

int main() {
    REP(i, 10000) p[i] = true;
    p[0] = p[1] = false;
    REP(i, 1000) if (p[i]) {
        for (int j = i * i; j < 10000; j += i) {
            p[j] = false;
        }
    }
    REP(i, 10000) if (p[i]) pr.pb(i);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &tt, &n, &j);
    printf("Case #1:\n");
    REP(i, 1 << (n - 2)) {
        LL mask = 1ll << (n - 2);
        mask |= i;
        mask <<= 1;
        mask |= 1;
        REP(i, 11) ans[i] = -1;
        bool ok = false;
        for (int x : pr) {
            for (int base = 2; base <= 10; ++base) {
                LL cur = mask;
                int num = 0;
                while (cur) {
                    num = base * num;
                    if (cur & 1) num += 1;
                    cur >>= 1;
                    num %= x;
                }
                if (num == 0 && ans[base] == -1) {
                    ans[base] = x;
                }
            }
            ok = true;
            for (int base = 2; base <= 10; ++base) if (ans[base] == -1) {
                ok = false;
            }
            if (ok) break;
        }
        if (ok) {
            while (mask) {
                if (mask & 1) printf("1");
                else printf("0");
                mask >>= 1;
            }
            for (int base = 2; base <= 10; ++base) {
                printf(" %d", ans[base]);
            }
            printf("\n");
            if (--j == 0) break;
        }
    }
    return 0;
}
