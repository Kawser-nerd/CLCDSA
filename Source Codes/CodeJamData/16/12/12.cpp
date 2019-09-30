
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

#undef int
int main() {
#define int long long
    ios :: sync_with_stdio(0); cin.tie(0);
    cout << (fixed) << setprecision(9);

    int ntest; cin >> ntest;
    FOR(test,1,ntest) {
        set<int> all;
        int n; cin >> n;
        FOR(i,1,2*n-1) FOR(j,1,n) {
            int a; cin >> a;
            if (all.count(a)) all.erase(a);
            else all.insert(a);
        }
        assert(SZ(all) == n);
        cout << "Case #" << test << ":";
        for(int x : all) cout << ' ' << x;
        cout << endl;
    }
}
