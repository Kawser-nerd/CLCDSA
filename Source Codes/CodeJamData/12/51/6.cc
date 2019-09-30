// another fine solution by misof
// #includes {{{
#include <algorithm>
#include <numeric>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
using namespace std;
// }}}

/////////////////// PRE-WRITTEN CODE FOLLOWS, LOOK DOWN FOR THE SOLUTION ////////////////////////////////

// pre-written code {{{
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define REP(i,n) for(int i=0;i<(int)(n);++i)
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

struct zaznam { int L, P, id; };
bool operator<(const zaznam &A, const zaznam &B) {
    if (A.L*B.P < A.P*B.L) return true;
    if (A.L*B.P > A.P*B.L) return false;
    return A.id < B.id;
}

int main() {
    int T; cin >> T;
    FOR(t,1,T) {
        int N; cin >> N;
        vector<int> L(N); for (int &x:L) cin >> x;
        vector<int> P(N); for (int &x:P) cin >> x;
        vector<zaznam> Z;
        REP(n,N) { zaznam tmp; tmp.L=L[n]; tmp.P=P[n]; tmp.id=n; Z.push_back(tmp); }
        sort( Z.begin(), Z.end() );
        cout << "Case #" << t << ":";
        REP(n,N) cout << " " << Z[n].id;
        cout << endl;
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
