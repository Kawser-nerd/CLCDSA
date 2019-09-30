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

const int inf = int(1e9) + 7;

int n;
string s[2010];
int a[2010][2010];

int gorow(int c) {
    forn(i, n) forn(j, n) a[i][j] = s[i][j] == '1';
    vector<int> rows[2];
    forn(i, n) {
        if ((i + c) % 2 != a[i][0])
            rows[ a[i][0] ].pb(i);
    }

    if (rows[0].size() != rows[1].size()) return inf;

    forn(i, rows[0].size()) {
        int r1 = rows[0][i];
        int r2 = rows[1][i];

        forn(j, n) swap(a[r1][j], a[r2][j]);
    }

    forn(j, n) {
        forn(i, n - 1) if (a[i][j] == a[i+1][j]) return inf;
    }

    return rows[0].size();
}

int gocol(int c) {
    forn(i, n) forn(j, n) a[i][j] = s[i][j] == '1';
    vector<int> rows[2];
    forn(i, n) {
        if ((i + c) % 2 != a[0][i])
            rows[ a[0][i] ].pb(i);
    }

    if (rows[0].size() != rows[1].size()) return inf;

    forn(i, rows[0].size()) {
        int r1 = rows[0][i];
        int r2 = rows[1][i];

        forn(j, n) swap(a[j][r1], a[j][r2]);
    }

    forn(i, n) {
        forn(j, n - 1) if (a[i][j] == a[i][j + 1]) return inf;
    }

    return rows[0].size();
}

void solve() {
    scanf("%d", &n);
    n <<= 1;
    forn(i, n) cin >> s[i];

    int ans = min(gorow(0), gorow(1)) + min(gocol(0), gocol(1));
    if (ans >= inf) printf("IMPOSSIBLE\n");
    else printf("%d\n", ans);
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        printf("Case #%d: ", t);
        solve();
        fprintf(stderr, "Test %d done, time: %.5f sec.\n", t, curtime());
    }
	return 0;
}
