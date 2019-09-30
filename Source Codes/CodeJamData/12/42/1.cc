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

int r[1050];
int c[1050];
int placed[1050];
int reach[1050];

int width, height, n;
int row;

int IntervalOverlap(int a1, int b1, int a2, int b2) {
  if (a1 <= a2 && b1 > a2) return 1;
  if (a2 <= a1 && b2 > a1) return 1;
  return 0;
}

int FindPlace(int radius, int pwt) {
  while (true) {
    int col = 0;
    FORN(i, n) if (placed[i]) {
      // check if intersect
      int int1a = r[i] - reach[i];
      int int1b = r[i] + reach[i];
      int int2a = row - radius;
      int int2b = row + radius;
      if (IntervalOverlap(int1a, int1b, int2a, int2b)) MX(col, c[i] + reach[i] + radius);
    }
    if (col > width) {
      row += pwt;
      continue;
    } else {
      return col;
    }
  }
    
}

int main() {
  
  int ntc;
  cin >> ntc;
  
  FORN(itc, ntc) {
    cout << "Case #" << (itc+1) << ":";
    
    cin >> n >> width >> height;
    
    vint done(n, 0);
    FORN(i, n) placed[i] = 0;
    
    FORN(i, n) {
      cin >> reach[i];
    }
    
    int ptw = 1;
    while (ptw <= (*(max_element(reach, reach + n)))) ptw *= 2;
    ptw /= 2;
    
    row = 0;
    
    while (ptw) {
      // preprocess
      FindPlace(ptw, ptw);
      
      // take all sizes >= ptw
      vint obj;
      FORN(i, n) if (!done[i] && reach[i] >= ptw) {
        done[i] = 1;
        obj.PB(i);
      }
      
      // try placing each of them
      FORIT(it, obj) {
        int id = *it;
        int pnj = reach[id];
        
        int col = FindPlace(pnj, ptw);
        assert(row >= 0 && row <= height && col >= 0 && col <= width);
        
        r[id] = row;
        c[id] = col;
        placed[id] = 1;
      }
            
      ptw /= 2; 
    }
    
    FORN(i, n) {
      assert(placed[i]);
      cout << " " << c[i] << " " << r[i];
      
      // test
      FORN(j, n) if (i != j) {
        assert(!IntervalOverlap(r[i] - reach[i], r[i] + reach[i], r[j] - reach[j], r[j] + reach[j]) ||
               !IntervalOverlap(c[i] - reach[i], c[i] + reach[i], c[j] - reach[j], c[j] + reach[j]));
      }
    }
    cout << endl;
    
  }
  
}
