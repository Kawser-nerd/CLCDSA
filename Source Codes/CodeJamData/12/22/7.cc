// Authored by dolphinigle
// GCJ 2012 1B
// 5 May 2012

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
#include <assert.h>

#define FORN(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define REP(X,Y,Z) for (int (X) = (Y);(X) < (Z);++(X))

#define SZ(Z) ((int)(Z).size())
#define ALL(W) W.begin(), W.end()
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

ll baw[120][120];
ll ats[120][120];

ll dp[120][120];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

ll minhei(int r1, int c1, int r2, int c2) {
  ll flor1 = baw[r1][c1];
  ll flor2 = baw[r2][c2];
  ll ceil1 = ats[r1][c1];
  ll ceil2 = ats[r2][c2];
  if (ceil2 - flor2 < 50LL) return -1LL;
  if (ceil2 - flor1 < 50LL) return -1LL;
  if (ceil1 - flor2 < 50LL) return -1LL;
  
  // harus ada 50 between ceil and water level
  return ceil2 - 50LL;
}

int main() {
  
  int ntc;
  cin >> ntc;
  
  FORN(itc, ntc) {
    cout << "Case #" << (itc+1) << ": ";
    
    ll row, col, h;
    cin >> h >> row >> col;
    
    // Fill all!
    FORN(i, 120) FORN(j, 120) baw[i][j] = ats[i][j] = 0;
    
    FORN(i, row) {
      FORN(j, col) {
        cin >> ats[i+1][j+1];
      }
    }
    FORN(i, row) FORN(j, col) cin >> baw[i+1][j+1];
    
    // Done filling
    row += 2;
    col += 2;
    
    FORN(i, row) FORN(j, col) dp[i][j] = 1123123123LL * 1123123123LL;
    
    set< pair<ll, pair<int,int> > > s;
    dp[1][1] = 0LL;
    s.insert(MP(0LL, MP(1, 1)));
    
    while (!s.empty()) {
      ll val = s.begin()->A;
      int r = s.begin()->B.A;
      int c = s.begin()->B.B;
      s.erase(s.begin());
     // cout << r << " " << c << " " << val << endl;
      if (dp[r][c] != val) continue;
      
      // try moving
      FORN(i, 4) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        ll hei = minhei(r, c, nr, nc);
        //cout << hei << endl;
        if (hei == -1LL) continue; // cannot move
        ll ch = h - val;
        ll taim = 0LL;
        if (ch <= hei) {
          // no need to wait
          taim = 0LL;
        } else {
          taim = (ch - hei);
          ch = hei;
        }
        
        if (taim != 0LL || val) {
          if (ch - baw[r][c] >= 20LL) {
            taim += 10LL;
          } else {
            taim += 100LL;
          }
        }
        
        ll total = taim + val;
        if (dp[nr][nc] <= total) continue;
        dp[nr][nc] = total;
        s.insert(MP(total, MP(nr, nc)));
      }
    }
    
    db ret = dp[row-2][col-2];
    ret /= 10.0;
    printf("%.11lf\n", ret);
  }
  
}
