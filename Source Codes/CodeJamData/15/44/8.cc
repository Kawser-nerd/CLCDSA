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

const int DBG = 0;
int R, C;
bool allowed[5];
long long MOD = 1000000007;
bool may_follow[6][6]; // pred, po
int eats_rows[6] = { 2, 1, 2, 3, 2, 0 };
int breaks_symmetry[6] = { 0, 0, 1, 1, 1, 0 };
int offsets[6] = { 1, 1, 3, 4, 6, 0 };

long long memo[128][6][16];

int lcm(int a, int b) { return a*b / __gcd(a,b); }

long long solve(int remains, int last, int period_length) {
    if (DBG) cout << "solve " << remains << " " << last << " " << period_length << endl;
    if (remains == 0) {
        if (DBG) cout << "solve " << remains << " " << last << " " << period_length << " return " << 1 << endl;
        return 1;
    }
    long long &res = memo[remains][last][period_length];
    if (res >= 0) return res;
    res = 0;
    for (int po=0; po<5; ++po) {
        if (!allowed[po]) continue;
        if (!may_follow[last][po]) continue;
        if (remains < eats_rows[po]) continue;
        long long zvysok = solve( remains - eats_rows[po], po, lcm( period_length, offsets[po] ) );
        zvysok *= __gcd( period_length, offsets[po] );
        res += zvysok;
    }
    res %= MOD;
    if (DBG) cout << "solve " << remains << " " << last << " " << period_length << " return " << res << endl;
    return res;
}

int main() {
    int T; cin >> T;
    REP(i,6) REP(j,6) may_follow[i][j] = false;
    REP(i,6) may_follow[5][i] = true; // toto je start
    for (int i=1; i<5; ++i) may_follow[0][i] = may_follow[i][0] = true;

    FOR(test,1,T) {
        cin >> R >> C;
        allowed[0] = allowed[1] = true;
        allowed[2] = (C%3 == 0);
        allowed[3] = (C%4 == 0);
        allowed[4] = (C%6 == 0);
        memset( memo, -1, sizeof(memo) );
        cout << "Case #" << test << ": " << solve(R,5,1) << endl;
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
