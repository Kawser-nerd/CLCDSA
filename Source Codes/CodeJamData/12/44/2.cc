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

string peta[66];

int vis[66][66];

vector< pair<int, int> > loc;

set< vector< pair<int,int> > > memo;

int dr[] = {0, 0, 1};
int dc[] = {1, -1, 0};

vector< pair<int, int> > Move(int dr, int dc, const vector< pair<int, int> > org) {
  vector< pair<int, int> > pool;
  FORIT(it, org) {
    int nr = it->A + dr;
    int nc = it->B + dc;
    if (peta[nr][nc] == '#') pool.PB(*it); else pool.PB(MP(nr, nc));
  }
  sort(ALL(pool));
  pool.erase(unique(ALL(pool)), pool.end());
  return pool;
}

int Process(const vector< pair<int,int> > oh) {
  if (memo.count(oh)) return 0;
  memo.insert(oh);
  
  FORIT(it, oh) if (!vis[it->A][it->B]) return 0;
  
  if (oh.size() == 1) {
    // good!
    return 1;
  }
  
  FORN(i, 3) if (Process(Move(dr[i], dc[i], oh))) return 1;
  return 0;
}

void Dfs(int r, int c) {
  if (vis[r][c]) return;
  if (peta[r][c] == '#') return;
  vis[r][c] = 1;
  
  loc.PB(MP(r, c));
  
  Dfs(r-1, c);
  Dfs(r, c+1);
  Dfs(r, c-1);
}



int main() {
  
  int ntc;
  cin >> ntc;
  
  FORN(itc, ntc) {
    cout << "Case #" << (itc+1) << ":\n";
    
    int row, col;
    cin >> row >> col;
    
    FORN(i, row) cin >> peta[i];
    
    FORN(i, 10) {
      int ir = -1, ic = -1;
      FORN(r, row) FORN(c, col) if (peta[r][c] == ('0' + i)) {
        ir = r;
        ic = c;
      }
      if (ir == -1) continue;
      
      loc.clear();
      
      FORN(r, row) FORN(c, col) vis[r][c] = 0;
      
      Dfs(ir, ic);
      
      int nr = SZ(loc);
      cout << i << ": " << nr << " ";
      
      vector< pair<int, int> > asal = Move(0, -1, loc);
      FORN(i, 60) asal = Move(0, -1, asal);
      
      memo.clear();
      if (Process(asal)) {
        cout << "Lucky\n";
      } else {
        cout << "Unlucky\n";
      }
    }
    
  }
  
}
