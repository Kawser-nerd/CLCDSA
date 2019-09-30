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

int test = 1;
void solve() {
    string s;
    cin >> s;
    string t;
    for (auto c: s) {
        if (t.empty() || c < t[0])
            t.push_back(c);
        else
            t.insert(t.begin(), c);
    }
    cout << "Case #" << test++ << ": " << t << '\n';
}


int main() {
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    assert(freopen("a.in", "r", stdin));
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
