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


void solve_case() {

    int h, w;
    cin >> h >> w;

    vector<int> ptn;

    REP(i, h) {
        int p = 0;
        REP(j, w) {
            char c;
            cin >> c;
            if (c == 'x')
                p |= 1 << j;
        }
        ptn.push_back(p);
    }

    vector<int> dp_prev(1<<w, 0);
    REP(iRow, h) {
        const int p = ptn[iRow];
        vector<int> dp_next(1<<w, -1);
        REP(i, 1<<w) {
            if (dp_prev[i] < 0)
                continue;
            int forbid = (i >> 1) | (i << 1) | p;
            REP(j, 1<<w) {
                if (j & forbid)
                    continue;
                if (j & (j<<1))
                    continue;
                dp_next[j] >?= dp_prev[i] + __builtin_popcount(j);
            }
        }
        dp_prev.swap(dp_next);
    }

    cout << *max_element(ALLOF(dp_prev)) << endl;
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
