#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
#include <functional>
#include <utility>
#include <numeric>
#include <complex>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <cassert>

#include <gmp.h>
#include <gmpxx.h>

using namespace std;

#define REP(i,n) for(int i = 0; i < (int)(n); i++)
#define FOR(i,c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALLOF(c) ((c).begin()), ((c).end())

#define MOD 10007

void solve_case() {

    int h, w, n;
    cin >> h >> w >> n;

    vector< vector<bool> > rock(h, w);

    REP(k, n) {
        int i, j;
        cin >> i >> j;
        i--; j--;
        rock[i][j] = true;
    }

    vector< vector<int> > dp(h+2, w+2);
    dp[0][0] = 1;

    REP(i, h) REP(j, w) {
        if (!rock[i][j]) {
            dp[i+1][j+2] = (dp[i+1][j+2] + dp[i][j]) % MOD;
            dp[i+2][j+1] = (dp[i+2][j+1] + dp[i][j]) % MOD;
        }
    }

    cout << dp[h-1][w-1] << endl;
}


int main() {

    int nCases;
    cin >> nCases;

    REP(iCase, nCases) {
        cout << "Case #" << iCase+1 << ": ";
        solve_case();
    }

    return 0;
}
