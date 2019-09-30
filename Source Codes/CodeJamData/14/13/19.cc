// Authored by dolphinigle

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
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

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

#define FORIT(X,Y) for(__typeof__((Y).begin()) X = (Y).begin();X!=(Y).end();X++)

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> vint;

db chance[1020][1020];
db dp[2][1020][1020];

int main() {
  int ntc;
  cin >> ntc;
  int x = 0;
  FORN(i, 1000) dp[x][i][i] = 1.0;
  int n = 1000;
  FORN(i, n) {
    int y = x^1;
    FORN(j, n) {
      // i swap j
      db ch = 1.0 / (db)n;
      // chance[j] = chance[j-1] * 1-ch + ch * chance[i]
      FORN(k, n) dp[y][k][j] = dp[x][k][j] * (1.0 - ch) + ch * dp[x][k][i];
    }
    FORN(j, n) dp[y][j][i] = 1.0 / (db)n;
    x = y;
  }
  FORN(i, n) {
    FORN(j, n) {
      chance[i][j] = dp[x][i][j] / (1.0 / (db)n);
    }
  }

  FORN(itc, ntc) {
    int an;
    cin >> an;
    db ch = 1.0;
    FORN(i, an) {
      int x;
      cin >> x;
      ch *= chance[x][i];
    }
    printf("Case #%d: ", itc+1);
    db median = 0.845452;
    if (ch > median) {
      cout << "BAD" << endl;
    } else {
      cout << "GOOD" << endl;
    }
  }

  return 0;
}

