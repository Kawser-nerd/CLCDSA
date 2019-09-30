// Authored by dolphinigle
// GCJ 2013 1B
// 4 May 2013

#include <vector>
#include <list>
#include <map>
#include <set>

#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <assert.h>

#define FORN(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define REP(X,Y,Z) for (int (X) = (Y);(X) < (Z);++(X))

#define SZ(Z) ((int)(Z).size())
#define ALL(W) (W).begin(), (W).end()
#define PB push_back

#define MP make_pair
#define A first
#define B second

#define INF 1023123123
#define EPS 1e-11

#define MX(Z,Y) Z = max((Z),(Y))
#define MN(X,Y) X = min((X),(Y))

#define FORIT(X,Y) for(typeof((Y).begin()) X = (Y).begin();X!=(Y).end();X++)

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> vint;

db dp[2][3000];
db Solve(int mau, int total, int tingmax) {
  int z = 0;
  FORN(i, 3000) dp[z][i] = 0.0;
  dp[z][0] = 1.0;
  FORN(i, total) {
    int y = z^1;
    FORN(j, 3000) dp[y][j] = 0.0;
    FORN(j, tingmax+1) {
      int lef = j;
      int rig = i - j;
      if (lef < 0 || lef > tingmax || rig < 0 || rig > tingmax) continue;
      if (lef == tingmax) {
        // no choice but to right
        dp[y][lef] += dp[z][j];
      } else if (rig == tingmax) {
        // no choice but to left
        dp[y][lef+1] += dp[z][j];
      } else {
        // 0.5 chance left, 0.5 chance right
        dp[y][lef] += dp[z][j] * 0.5;
        dp[y][lef+1] += dp[z][j] * 0.5;
      }
    }
    z = y;
  }
  db res = 0.0;
  for (int i = mau; i <= tingmax; ++i) {
    res += dp[z][i];
  }
  return res;
}

int main() {
  int ntc;
  cin >> ntc;
  FORN(itc, ntc) {
    cout << "Case #" << (itc+1) << ": ";
    int n, x, y;
    cin >> n >> x >> y;
    int used = 0;
    int phase = 0;
    db res = 0.0;
    while (true) {
      int mau = 1 + 4 * phase;
      if ((abs(x) + y) / 2 == phase) {
        // this phase
        if (used + mau <= n) {
          res = 1.0;
          break;
        } else {
          if (abs(x) == 0) {
            // not possible
            break;
          }
          int sisa = n - used;
          int height = y+1;
          if (sisa < height) break;
          // minimum this amt
          // <= 3000
          // ...
          res = Solve(height, sisa, 2 * phase);
          break;
        }
      }
      used += mau;
      if (used >= n) break;
      phase += 1;
    }
    printf("%.10lf\n", res);
  }
}
