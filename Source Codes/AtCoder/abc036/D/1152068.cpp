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

int mod = 1e9+7;

vvi g;
vi parent;
set<int> leaf;

void parent_bfs() {
  int root = 0;
  deque<int> stk;
  stk.push_back(root);
  while (!stk.empty()) {
    int u = stk.front();
    stk.pop_front();
    int num_child = 0;
    for (int v : g[u]) {
      if (v == parent[u]) {
        continue;
      }
      parent[v] = u;
      stk.push_back(v);
      num_child += 1;
    }
    if (num_child == 0) {
      leaf.insert(u);
    }
  }
}

bool is_leaf(int u) {
  return (leaf.find(u) != end(leaf));
}

pii white_black(int u) {
  if (is_leaf(u)) {
    return make_pair(1, 1);
  }
  ll w = 1;
  ll b = 1;
  for (int v : g[u]) {
    if (v == parent[u]) {
      continue;
    }
    auto p = white_black(v);
    w = w * (p.first + p.second) % mod;
    b = b * p.first % mod;
  }
  return make_pair((int)w, (int)b);
}

int main() {
  int n;
  scanf("%d", &n);
  g.resize(n);
  rep (i, n-1) {
    int a, b;
    scanf("%d %d", &a, &b);
    a -= 1;
    b -= 1;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  parent.assign(n, -1);
  parent_bfs();
  auto ans = white_black(0);
  printf("%d\n", (ans.first + ans.second) % mod);

  return 0;
}