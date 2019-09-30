#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <string.h>
#include <queue>
#include <cstdio>
#include <cassert>
#include <deque>
#include <stack>
#include <utility>
#include <numeric>
#include <ctime>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forv(i, v) forn(i, v.size())

#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll dp[32][2][2][2];
int a, b, k;

ll calc(int pos, int fa, int fb, int fk) {
    if (pos == -1) return 1;
    if (dp[pos][fa][fb][fk] != -1) return dp[pos][fa][fb][fk];
    int bitA = (a >> pos) & 1;
    int bitB = (b >> pos) & 1;
    int bitK = (k >> pos) & 1;
    ll& res = dp[pos][fa][fb][fk];
    res = 0;
    forn(xa, 2) {
        forn(xb, 2) {
            if (fa == 0 && xa > bitA) continue;
            if (fb == 0 && xb > bitB) continue;
            int xk = xa & xb;
            if (fk == 0 && xk > bitK) continue;
            res += calc(pos - 1, fa | (xa < bitA), fb | (xb < bitB), fk | (xk < bitK));
        }
    }    
    return res;
}

void solve(int tc) {
    cout << "Case #" << tc << ": ";
    memset(dp, 255, sizeof(dp));
    cin >> a >> b >> k;
    a--, b--, k--;
    cout << calc(30, 0, 0, 0) << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    forn(i, tc) solve(i + 1);
    return 0;
}
