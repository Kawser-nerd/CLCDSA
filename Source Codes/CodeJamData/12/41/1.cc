// Authored by dolphinigle
// GCJ 2012 Round 2
// 26 May 2012

// T-shirt! #wantwantwant

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

int best[10300];
int len[10300];
int loc[10300];

int main() {
  
  int ntc;
  cin >> ntc;
  
  FORN(itc, ntc) {
    cout << "Case #" << (itc+1) << ": ";
    
    int n;
    cin >> n;
    
    FORN(i, n) {
      cin >> loc[i] >> len[i];
    }
    
    int d;
    cin >> d;
    len[n] = INF;
    loc[n] = d;
    
    ++n;
    
    FORN(i, 10300) best[i] = -1;
    best[0] = loc[0];
    
    set< pair<int, int> > itu;
    itu.insert(MP(-loc[0], 0));
    
    while (!itu.empty()) {
      int val = itu.begin()->A;
      int p = itu.begin()->B;
      
      itu.erase(itu.begin());
      
      if (best[p] != -val) {
        // wrong
        assert(-val < best[p]);
        continue;
      }
      
      val *= -1;
      
      // do it
      FORN(i, n) if (abs(loc[i] - loc[p]) <= val) {
        // ok here
        int np = i;
        int nval = min(abs(loc[i] - loc[p]), len[i]);
        if (best[np] < nval) {
          best[np] = nval;
          itu.insert(MP(-nval, np));
        }
      }
    }
    
    if (best[n-1] == -1) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  
}
