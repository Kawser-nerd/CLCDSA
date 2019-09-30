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

vi a;
vvi g;
vi par;

ll evaluation(int u) {
  if ((int)g[u].size() == 1) {
    return a[u];
  }
  ll sum_childs = 0;
  vll childs;
  for (int v : g[u]) {
    if (v == par[u]) {
      continue;
    }
    ll tmp = evaluation(v);
    childs.push_back(tmp);
    sum_childs += tmp;
  }
  sort(all(childs));
  ll min_a, max_a;
  max_a = sum_childs;

  if (childs.back() * 2 >= sum_childs) {
    min_a = childs.back();
  } else {
    min_a = (sum_childs + 1) / 2;
  }

  if (a[u] < min_a || max_a < a[u]) {
    printf("NO\n");
    exit(0);
  }
  return sum_childs - (sum_childs - a[u]) * 2;
}

void search_main(int root) {
  ll sum_child = 0;
  vll childs;
  for (int u : g[root]) {
    ll tmp = evaluation(u);
    childs.push_back(tmp);
    sum_child += tmp;
  }
  if (a[root] * 2 != sum_child) {
    printf("NO\n");
    exit(0);
  }
  sort(all(childs));
  if (childs.back() * 2 > sum_child) {
    printf("NO\n");
    exit(0);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  a.resize(n);
  rep (i, n) {
    scanf("%d", &a[i]);
  }
  g.resize(n);
  rep (i, n-1) {
    int u, v;
    scanf("%d %d", &u, &v);
    u -= 1;
    v -= 1;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  if (n == 2) {
    if (a[0] == a[1]) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
    return 0;
  }
  int root = 0;
  rep (i, n) {
    if (g[root].size() < g[i].size()) {
      root = i;
    }
  }
  par.resize(n);
  par[root] = root;
  deque<int> st;
  for (int u : g[root]) {
    par[u] = root;
    st.push_back(u);
  }
  while (!st.empty()) {
    int u = st.front();
    st.pop_front();
    for (int v : g[u]) {
      if (v == par[u]) {
        continue;
      }
      par[v] = u;
      st.push_back(v);
    }
  }
  search_main(root);
  printf("YES\n");

  return 0;
}