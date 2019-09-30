#include <algorithm>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define rep(i,n) FOR(i,0,n)
#define pb push_back
#define all(v) begin(v), end(v)
#define debug(x) cerr<< #x <<": "<<x<<endl
#define debug2(x,y) cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
template<class T> using vv=vector<vector< T > >;

vi a; // number of node
vvi g;
vvi child;
set<int, greater<int> > root;
deque<bool> reached;

void dfs(int s) {
  root.insert(s);
  deque<int> st;
  st.push_back(s);
  reached[s] = true;
  while (!st.empty()) {
    int u = st.back();
    for (int v : g[u]) {
      if (!reached[v]) {
        child[u].push_back(v);
        st.push_back(v);
        reached[v] = true;
        st.push_back(v);
        break;
      }
    }
    if (st.back() == u) {
      st.pop_back();
    }
  }
}

vi retrieve(int r) {
  int sz = (int)child[r].size();
  if (sz == 0) {
    return (vi){r};
  }
  int ret_size = 0;
  vvi tmp(sz);
  rep (i, sz) {
    tmp[i] = retrieve(child[r][i]);
    tmp[i].push_back(-1);
    ret_size += (int)tmp[i].size();
  }
  vi ret;
  ret.reserve(ret_size + 10);
  ret.push_back(r);
  vi index(sz, 0);
  while (true) {
    int next_i = -1;
    int selected = -1;
    rep (i, sz) {
      if (next_i < tmp[i][index[i]]) {
        next_i = tmp[i][index[i]];
        selected = i;
      }
    }
    if (next_i == -1) {
      break;
    }
    ret.push_back(next_i);
    index[selected] += 1;
  }
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  a.resize(n);
  rep (i, n) {
    scanf("%d", &a[i]);
  }
  sort(all(a));

  g.resize(n);
  rep (i, n) {
    rep (j, n) {
      if (i == j) {
        continue;
      }
      if (__gcd(a[i], a[j]) == 1) {
        continue;
      }
      g[i].push_back(j);
      g[j].push_back(i);
    }
  }
  rep (i, n) {
    sort(all(g[i]));
  }

  // construct tree
  child.resize(n);
  reached.assign(n, false);
  rep (i, n) {
    if (reached[i]) {
      continue;
    }
    if (a[i] == 1) {
      root.insert(i);
      reached[i] = true;
      continue;
    }
    dfs(i);
  }

  for (int r : root) {
    vi tmp = retrieve(r);
    for (int i : tmp) {
      printf("%d ", a[i]);
    }
  }
  printf("\n");

  return 0;
}