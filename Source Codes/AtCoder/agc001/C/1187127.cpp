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

vvi g;
int cnt;
int max_distance;

void dfs(int prev, int current, int distance) {
  cnt += 1;
  if (distance == max_distance) return;
  for (int u : g[current]) {
    if (u == prev) continue;
    dfs(current, u, distance + 1);
  }
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  g.resize(n);
  vvi edges(n-1, vi(2));
  rep (i, n-1) {
    int a, b;
    scanf("%d%d", &a, &b);
    a -= 1;
    b -= 1;
    g[a].push_back(b);
    g[b].push_back(a);
    edges[i][0] = a;
    edges[i][1] = b;
  }

  max_distance = k / 2;
  int max_nodes = 0;
  if ((k&1) == 0) {
    rep (i, n) {
      cnt = 0;
      dfs(-1, i, 0);
      max_nodes = max(max_nodes, cnt);
    }
  } else {
    rep (i, n-1) {
      cnt = 0;
      dfs(edges[i][0], edges[i][1], 0);
      dfs(edges[i][1], edges[i][0], 0);
      max_nodes = max(max_nodes, cnt);
    }
  }
  printf("%d\n", n - max_nodes);

  return 0;
}