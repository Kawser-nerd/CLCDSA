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

vector<int> adj[1050];
pair<int, int> Binarize(int node, int parent) {
  // min no of nodes to rem, total no of nodes
  vector<int> ch;
  int nodesum = 1;
  FORIT(it, adj[node]) {
    if (*it == parent) continue;
    pair<int, int> child = Binarize(*it, node);
    nodesum += child.B;
    // if we keep this, we pay child.A. If we remove, we pay child.B.
    ch.PB(child.B - child.A);
  }
  sort(ALL(ch));
  reverse(ALL(ch));
  int besta = nodesum - 1;
  if (SZ(ch) >= 2) {
    MN(besta, besta - ch[0] - ch[1]);
  }
  return MP(besta, nodesum);
}

int main() {
  int ntc;
  cin >> ntc;
  FORN(itc, ntc) {
    printf("Case #%d: ", itc+1);
    int n;
    cin >> n;
    FORN(i, 1050) adj[i].clear();
    FORN(i, n-1) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      adj[a].PB(b);
      adj[b].PB(a);
    }
    int best = INF;
    FORN(i, n) {
      pair<int, int> result = Binarize(i, -1);
      MN(best, result.A);
    }
    cout << best << endl;
  }
  return 0;
}

