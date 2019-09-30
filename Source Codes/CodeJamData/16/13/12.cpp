
#include <bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; ++i)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; --i)
#define REP(i,a) for(int i=0,_a=(a); i < _a; ++i)

#define DEBUG(X) { cout << #X << " = " << (X) << endl; }
#define PR(A,n)  { cout << #A << " = "; FOR(_,1,n) cout << A[_] << ' '; cout << endl; }
#define PR0(A,n) { cout << #A << " = "; REP(_,n) cout << A[_] << ' '; cout << endl; }

#define sqr(x) ((x) * (x))
#define ll long long
#define __builtin_popcount __builtin_popcountll
#define SZ(x) ((int) (x).size())
using namespace std;

//int GI(int& x) {
//    return scanf("%lld", &x);
//}

int n, f[1011], to[1011], getIn[1011], getOut[1011], seen[1011];
int maxCycle;

void init() {
    maxCycle = 0;
    FOR(i,1,n) {
        to[i] = getIn[i] = getOut[i] = 0;
    }

    FOR(i,1,n) {
        int u = i, v = f[i];
        getOut[u]++;
        getIn[v]++;
    }
    FOR(i,1,n) if (getIn[i] == 0) {
        memset(seen, 0, sizeof seen);
        seen[i] = 1;

        int u = i;
        while (true) {
            int v = f[u];
            if (f[v] == u) break;

            if (seen[v]) break;
            seen[v] = seen[u] + 1;

            to[v] = max(to[v], to[u] + 1);
            u = v;
        }
    }

    FOR(i,1,n) {
        memset(seen, 0, sizeof seen);
        seen[i] = 1;

        int u = i;
        while (true) {
            int v = f[u];
            if (seen[v]) {
                maxCycle = max(maxCycle, seen[u] + 1 - seen[v]);
                break;
            }
            seen[v] = seen[u] + 1;

            u = v;
        }
    }
//    DEBUG(maxCycle);
}

int solve() {
    init();
    int res = maxCycle;

//    PR(f, n);
//    PR(to, n);

    // all cycle of length 2
    int cur = 0;
    FOR(i,1,n) if (f[f[i]] == i && f[i] > i) {
//        cout << i << ' ' << f[i] << endl;
        cur += 2 + to[i] + to[f[i]];
    }
    res = max(res, cur);
    return res;
}

#undef int
int main() {
#define int long long
    ios :: sync_with_stdio(0); cin.tie(0);
    cout << (fixed) << setprecision(9);
    int ntest; cin >> ntest;
    FOR(test,1,ntest) {
        cin >> n; FOR(i,1,n) cin >> f[i];
        int res = solve();
        cout << "Case #" << test << ": " << res << endl;
    }
}
