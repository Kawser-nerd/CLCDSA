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

int see[2050];
int n;
int hei[2050];

int Solve(int a, int b, int dy) {
  if (a >= b) return 1;
  // Find the leftmost thing that see b
  int got = -1;
  REP(i, a, b) if (see[i] == b) {
    got = i;
    break;
  }
  if (got == -1) {
    // fatal error
    return 0;
  }
  
  hei[got] = hei[b] - dy * (b - got);
  return Solve(a, got, dy) && Solve(got+1, b, dy + 1);
}

int main() {
  
  int ntc;
  cin >> ntc;
  
  FORN(itc, ntc) {
    cout << "Case #" << (itc+1) << ":";
    
    cin >> n;
    FORN(i, n-1) {
      cin >> see[i];
      --see[i];
    }
    see[n-1] = -1;
    
    hei[n-1] = 1000000000;
    
    if (Solve(0, n-1, 0)) {
      FORN(i, n) cout << " " << hei[i];
      cout << endl;
    } else {
      cout << " Impossible\n";
    }
    
  }
  
}
