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
#include <numeric>
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
#define debug(x) std::cerr<< #x <<": "<<x<<"\n"
#define debug2(x,y) std::cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<"\n"
 
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
vector<bool> used;

int main() {
  scanf("%d %d", &n, &m);
  g.resize(n);
  rep (i, m) {
    int a, b;
    scanf("%d %d", &a, &b);
    a -= 1; b -= 1;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  used.assign(n, false);
  vi path = {0};
  used[0] = true;

  while (true) {
    int u = *(path.end() - 1);
    for (int v : g[u]) {
      if (used[v]) {
        continue;
      }
      path.push_back(v);
      used[v] = true;
      break;
    }
    if (u == *(path.end() - 1)) {
      break;
    }
  }

  reverse(all(path));

  while (true) {
    int u = *(path.end() - 1);
    for (int v : g[u]) {
      if (used[v]) {
        continue;
      }
      path.push_back(v);
      used[v] = true;
      break;
    }
    if (u == *(path.end() - 1)) {
      break;
    }
  }

  printf("%lu\n", path.size());
  for (int u : path) {
    printf("%d ", u+1);
  }
  printf("\n");

  return 0;
}