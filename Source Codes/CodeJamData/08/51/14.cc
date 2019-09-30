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

#define N 6400

const int INF = N*2;

void go(vector<int>& v) {
    int p = max_element(ALLOF(v)) - v.begin();
    int l = -INF;
    for(int i = N-1; i >= p; i--) {
        l >?= v[i];
        v[i] = l;
    }
}

void calc_conv(vector<int>& mini, vector<int>& maxi) {
    go(maxi); reverse(ALLOF(maxi)); go(maxi); reverse(ALLOF(maxi));
    REP(i, N)
        mini[i] = -mini[i];
    go(mini); reverse(ALLOF(mini)); go(mini); reverse(ALLOF(mini));
    REP(i, N)
        mini[i] = -mini[i];
}

void solve_case() {

    vector<int> mini(N, INF);
    vector<int> maxi(N, -INF);

    int cx = N/2, cy = 0, cdir = 0;

    int nCommands;
    cin >> nCommands;

    int original = 0;

    REP(iCommand, nCommands) {
        string cmd;
        int nRepeats;
        cin >> cmd >> nRepeats;

        REP(iRepeat, nRepeats) {
            REP(iOperation, cmd.size()) {
                int ox = cx, oy = cy;
                char op = cmd[iOperation];
                if (op == 'L') {
                    cdir = (cdir + 1) % 4;
                }
                else if (op == 'R') {
                    cdir = (cdir + 3) % 4;
                }
                else if (op == 'F') {
                    if (cdir == 0) {
                        cy++;
                    }
                    else if (cdir == 2) {
                        cy--;
                    }
                    else {
                        int x = (cdir == 1 ? cx-1 : cx);
                        mini[x] <?= cy;
                        maxi[x] >?= cy;
                        cx += (cdir == 1 ? -1 : 1);
                    }
                }
                else {
                    assert(false);
                }
                original += cx * oy - cy * ox;
            }
        }
    }

    calc_conv(mini, maxi);
    int padded = 0;
    REP(i, N)
        if (maxi[i] > mini[i])
            padded += maxi[i]-mini[i];

    original = abs(original) / 2;

    cout << padded-original << endl;
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
