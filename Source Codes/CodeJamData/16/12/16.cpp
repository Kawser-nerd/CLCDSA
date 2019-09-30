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

set<int> cnt;

int test = 1;
void solve() {
    int n;
    cin >> n;
    cnt.clear();
    forn (i, 2 * n - 1) {
        forn (j, n) {
            int x;
            cin >> x;
            if (cnt.count(x))
                cnt.erase(x);
            else
                cnt.insert(x);
        }
    }
    assert(sz(cnt) == n);
    cout << "Case #" << test++ << ":";
    for (auto x: cnt)
        cout << ' ' << x;
    cout << '\n';
}

int main() {
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
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
