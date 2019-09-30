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

vector<char> s;
vector<set<int> > g;

bool judge(int x) {
  bool oka = false;
  bool okb = false;
  for (int y : g[x]) {
    if (s[y] == 'A') {
      oka = true;
    } else {
      okb = true;
    }
    if (oka && okb) {
      return true;
    }
  }
  return false;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  s.resize(n);
  rep (i, n) {
    scanf(" %c", &s[i]);
  }
  g.resize(n);
  rep (i, m) {
    int a, b;
    scanf("%d %d", &a, &b);
    a -= 1; b -= 1;
    g[a].insert(b);
    g[b].insert(a);
  }

  vector<bool> ng_flag(n, false);
  deque<int> stk;
  rep (i, n) {
    if (!judge(i)) {
      stk.push_back(i);
      ng_flag[i] = true;
    }
  }
  while(!stk.empty()) {
    int u = stk.front();
    stk.pop_front();
    for (int v : g[u]) {
      if (ng_flag[v]) {
        continue;
      }
      g[v].erase(u);
      if (!judge(v)) {
        stk.push_back(v);
        ng_flag[v] = true;
      }
    }
  }
  int ok_cnt = 0;
  rep (i, n) {
    if (ng_flag[i] == false) {
      ok_cnt += 1;
    }
  }
  if (ok_cnt > 0) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}