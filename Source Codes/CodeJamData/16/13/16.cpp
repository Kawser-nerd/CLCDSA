#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)

typedef long long ll;
typedef long long i64;
typedef long double ld;

const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 5000;
int a[maxn];
bool used[maxn];

int len[maxn], to[maxn], longest[maxn];

int test = 1;
void solve() {
    int n;
    cin >> n;
    forn (i, n) {
        cin >> a[i];
        --a[i];
    }
    forn (i, n) {
        longest[i] = 0;
        memset(used, 0, sizeof(used));
        int u = i;
        int l = 0;
        while (!used[u]) {
            ++l;
            used[u] = true;
            u = a[u];
        }
        len[i] = l;
        to[i] = u;
    }
    forn (i, n) {
        int u = to[i];
        longest[u] = max(longest[u], len[i] - len[u]);
    }
    int res = 0;
    int maxc = 0;
    memset(used, 0, sizeof(used));
    forn (i, n) {
        if (used[i] || to[i] != i)
            continue;
        vector<int> val;
        int u = i;
        while (!used[u]) {
            used[u] = true;
            val.push_back(longest[u]);
            u = a[u];
        }
        if (sz(val) == 2)
            res += val[0] + val[1] + 2;
        maxc = max(maxc, sz(val));
    }
    res = max(res, maxc);
    cout << "Case #" << test++ << ": " << res << '\n';
}

int main() {
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    int tn;
    cin >> tn;
    forn (i, tn)
        solve();

    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}
