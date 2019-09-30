// another fine solution by misof
// #includes {{{
#include <algorithm>
#include <numeric>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
using namespace std;
// }}}

/////////////////// PRE-WRITTEN CODE FOLLOWS, LOOK DOWN FOR THE SOLUTION ////////////////////////////////

// pre-written code {{{
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define SIZE(t) ((int)((t).size()))
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

int N;
int V[1000];

int skus(int ktore) {
  int top = 0;
  stack<int> open;
  REP(i,2*N) {
    int x;
    if (V[i] > 0) {
      x = V[i];
      --x;
      if (!(ktore & 1<<x)) continue;
      open.push(x);
      top = max(top,SIZE(open));
    } else {
      x = -V[i];
      --x;
      if (!(ktore & 1<<x)) continue;
      if (open.top() != x) return 987654321;
      open.pop();
    }
  }
  return top;
}

int main() {
  int TTT;
  cin >> TTT;
  FOR(ttt,1,TTT) {
    cin >> N;
    map<string,int> ID;
    int cnt = 0;
    REP(i,2*N) {
      string f;
      cin >> f;
      if (ID.count(f)) {
        V[i] = -ID[f];
      } else {
        ID[f] = ++cnt;
        V[i] = ID[f];
      }
    }
    int best = 987654321;
    int vsetky = (1<<N)-1;
    REP(hore,1<<(N-1)) {
      int toto = skus(hore) + skus(vsetky ^ hore);
      best = min(best, toto);
    }
    if (best == 987654321) {
      cout << "Case #" << ttt << ": " << -1 << endl;
    } else {
      cout << "Case #" << ttt << ": " << best << endl;
    }
  }
  return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
