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
#define debug(x) //cerr<< #x <<": "<<x<<endl
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

// cout vector
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size(); s << "\n";
  for (int i = 0; i < len; ++i) {
    s << v[i]; if (i < len - 1) s << "\t";
  }
  s << "\n"; return s;
}

// cout 2-dimentional vector
template<typename T> ostream& operator<<(ostream& s, const vector< vector<T> >& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) { s << vv[i]; }
  return s;
}


int n, m;
vvi g;
vector<bool> arrived;

vi dfs(int start) {
  arrived[start] = true;
  vector<bool> used_local(n, false);
  used_local[start] = true;
  vi color(n, -1);
  color[start] = 0;
  deque<int> st = {start};
  while (!st.empty()) {
    int u = st.front();
    st.pop_front();
    rep (v, n) {
      if (g[u][v] == 0) {
        continue;
      }
      if (arrived[v]) {
        if (color[v] == color[u]) {
          printf("-1\n");
          exit(0);
        }
        continue;
      }
      arrived[v] = true;
      used_local[v] = true;
      if (color[v] == -1) {
        color[v] = 1 - color[u];
      } else if (color[v] == color[u]) {
        printf("-1\n");
        exit(0);
      }
      st.push_back(v);
    }
  }
  vi ret = {0, 0};
  rep (i, n) {
    if (!used_local[i]) {
      continue;
    }
    ret[color[i]] += 1;
  }
  return ret;
}

int main() {
  scanf("%d %d", &n, &m);
  g.assign(n, vi(n, 0));
  rep (i, m) {
    int a, b;
    scanf("%d %d", &a, &b);
    a -= 1; b -= 1;
    g[a][b] = g[b][a] = 1;
  }
  rep (i, n) {
    g[i][i] = 1;
  }
  rep (i, n) {
    rep (j, n) {
      g[i][j] = 1 - g[i][j];
    }
  }

  arrived.assign(n, false);
  vvi sts;
  rep (i, n) {
    if (arrived[i]) {
      continue;
    }
    sts.push_back(dfs(i));
  }

  debug(sts);
  int sz = sts.size();
  rep (i, sz) {
    if (sts[i][0] > sts[i][1]) {
      swap(sts[i][0], sts[i][1]);
    }
  }
  sort(all(sts), [](vi x, vi y) {
      return (x[1] - x[0]) > (y[1] - y[0]);
      });
  debug(sts);
  vi gr = {0, 0};
  rep (i, sz) {
    gr[0] += sts[i][0];
    gr[1] += sts[i][1];
    if (gr[0] < gr[1]) {
      swap(gr[0], gr[1]);
    }
  }

  int ans = gr[0] * (gr[0]-1) / 2 + gr[1] * (gr[1]-1) / 2;
  printf("%d\n", ans);

  return 0;
}