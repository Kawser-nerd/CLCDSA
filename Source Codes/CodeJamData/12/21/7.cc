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

int main() {
  
  int ntc;
  cin >> ntc;
  
  FORN(itc, ntc) {
    cout << "Case #" << (itc+1) << ":";
    
    int n;
    cin >> n;
    vint scores;
    db tot = 0.0;
    FORN(i, n) {
      int a;
      cin >> a;
      tot += (db)a;
      scores.PB(a);
    }
    
    FORN(i, n) {
      vector<db> scp;
      FORN(j, n) if (i != j) scp.PB(scores[j]);
      sort(ALL(scp));
      reverse(ALL(scp));
      
      // scp[0] = largest
      
      db low = 0.0;
      db hi = 1.0;
      db ret = 1.0;
      
      FORN(j, 100) {
        db mid = (low+hi)/2.0;
        db mysc = (db)scores[i] + tot * mid;
        db total = mid;
        FORN(k, n-1) {
          db needsc = mysc - scp[k];
          if (needsc <= 0.0) continue;
          db needp = needsc / tot;
          total += needp;
        }
        
        if (total > 1.0) {
          // success
          hi = mid;
          ret = mid;
        } else {
          low = mid;
        }
      }
      printf(" %.10lf", 100.0 * ret);
    }
    cout << endl;
  }
  
}
