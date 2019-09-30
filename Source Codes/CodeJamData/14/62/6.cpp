#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
#include <cmath>
#include <iostream>
#include <string>
#include <ctime>
#include <sstream>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

double curtime() {
    return double(clock()) / CLOCKS_PER_SEC;
}

int n, k;
vector<int> a;
ll ans;
ll fact[15];

bool ok(int i, const vector<int>& cur) {
    return ((cur[i] & 1) == 0 && cur[i] + 1 == cur[i+1]);
}

void go(int j, int c, vector<int> a) {
    int step = 1 << j;
    //printf("go j=%d (%d), c=%d\n", j, step, c);
    //printf("["); forn(q, a.size()) printf("%d%c", a[q], q + 1 == int(a.size()) ? ']': ','); printf("\n"); 
    if (step == n) {
        ans += fact[c];
        return;
    }

    vector<int> bad;
    for (size_t i = 0; i < a.size(); i += 2) {
        if (ok(i, a)) continue;
        bad.pb(i);
    }

    //printf("bad = "); forn(jj, bad.size()) printf("%d ", bad[jj]); printf("\n");

    if (bad.empty()) {
        vector<int> cur;
        for (size_t i = 0; i < a.size(); i += 2) {
            cur.pb(a[i] >> 1);
        }
        go(j + 1, c, cur);
    } else if (bad.size() == 1) {
        swap(a[ bad[0] ], a[ bad[0] + 1]);
        if (ok(bad[0], a)) {
            vector<int> cur;
            for (size_t i = 0; i < a.size(); i += 2) {
                cur.pb(a[i] >> 1);
            }
            go(j + 1, c + 1, cur);
        }
        swap(a[ bad[0] ], a[ bad[0] + 1]);
    } else if (bad.size() == 2) {
        forn(j0, 2) forn(j1, 2) {
            swap(a[ bad[0] + j0 ], a[ bad[1] + j1 ]);
            if (ok(bad[0], a) && ok(bad[1], a)) {
                vector<int> cur;
                for (size_t i = 0; i < a.size(); i += 2) {
                    cur.pb(a[i] >> 1);
                }
                go(j + 1, c + 1, cur);
            }
            swap(a[ bad[0] + j0 ], a[ bad[1] + j1 ]);
        }
    }
}

void solve() {
    scanf("%d", &k);
    n = 1 << k;
    a = vector<int>(n);
    forn(i, n) scanf("%d", &a[i]), a[i]--;
    ans = 0;
    go(0, 0, a);
    printf("%lld\n", ans);
}

int main() {
    fact[0] = fact[1] = 1;
    for (int i = 1; i <= 12; i++) fact[i] = fact[i - 1] * i;
    int tc;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        printf("Case #%d: ", t);
        solve();
        fprintf(stderr, "Test %d done, time: %.5f sec.\n", t, curtime());
    }
	return 0;
}
