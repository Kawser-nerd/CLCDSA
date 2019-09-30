#include <algorithm>
#include <cassert>
#include <cfloat>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
 
#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define rep(i,n) FOR(i,0,n)
#define all(v) begin(v), end(v)
#define debug(x) cerr<< #x <<": "<<x<<endl
#define debug2(x,y) cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
typedef deque<bool> db;
template<class T> using vv=vector<vector< T > >;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<set<int> > g(n);
  rep (i, m) {
    int a, b;
    scanf("%d%d", &a, &b);
    a -= 1; b -= 1;
    g[a].insert(b);
    g[b].insert(a);
  }
  bool ans = false;
  for (int u : g[0]) {
    if (g[u].find(n-1) != end(g[u])) {
      ans = true;
      break;
    }
  }
  if (ans) {
    printf("POSSIBLE\n");
  } else {
    printf("IMPOSSIBLE\n");
  }
  return 0;
}