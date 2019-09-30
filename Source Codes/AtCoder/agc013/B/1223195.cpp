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

int n, m;
vvi g;
vector<bool> reached;
vi previous;

deque<int> dfs(int s) {
  deque<int> stk;
  stk.push_back(s);
  reached.assign(n, false);
  reached[s] = true;
  previous.assign(n, -1);

  while (!stk.empty()) {
    int u = stk.back();
    for (auto v : g[u]) {
      if (reached[v]) { continue; }
      reached[v] = true;
      previous[v] = u;
      stk.push_back(v);
    }
    if (stk.back() == u) {
      deque<int> ret;
      for (int i = u; i != -1; i = previous[i]) {
        ret.push_front(i);
      }
      return ret;
    }
  }
}

deque<int> dfs(deque<int> &di) {
  reached.assign(n, false);
  int n_ = di.size();
  rep (i, n_) {
    reached[di[i]] = true;
  }
  previous.assign(n, -1);
  FOR (i, 1, n_) {
    previous[di[i]] = di[i-1];
  }
  deque<int> stk;
  stk.push_back(di.back());

  while (!stk.empty()) {
    int u = stk.back();
    for (auto v : g[u]) {
      if (reached[v]) { continue; }
      reached[v] = true;
      previous[v] = u;
      stk.push_back(v);
    }
    if (stk.back() == u) {
      deque<int> ret;
      for (int i = u; i != di.back(); i = previous[i]) {
        ret.push_front(i);
      }
      ret.insert(begin(ret), all(di));
      return ret;
    }
  }
}

bool check_tail(deque<int> &di) {
  reached.assign(n, false);
  int n_ = di.size();
  rep (i, n_) {
    reached[di[i]] = true;
  }
  int goal = di.back();
  for (int u : g[goal]) {
    if (!reached[u]) {
      return false;
    }
  }
  return true;
}

void print_path(deque<int> &path) {
  int n_ = path.size();
  printf("%d\n", n_);
  rep (i, n_) {
    printf("%d ", path[i] + 1);
  }
  printf("\n");
  exit(0);
}

int main() {
  scanf("%d%d", &n, &m);
  g.resize(n);
  rep (i, m) {
    int a, b;
    scanf("%d%d", &a, &b);
    a -= 1; b -= 1;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  auto path = dfs(0);
  while (!check_tail(path)) {
    path = dfs(path);
  }
  reverse(all(path));
  while (!check_tail(path)) {
    path = dfs(path);
  }
  print_path(path);

  return 0;
} ./Main.cpp:64:1: warning: control may reach end of non-void function [-Wreturn-type]
}
^
./Main.cpp:96:1: warning: control may reach end of non-void function [-Wreturn-type]
}
^
2 warnings generated.