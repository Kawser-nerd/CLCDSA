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

// cout vector
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size(); s << "\n";
  for (int i = 0; i < len; ++i) {
    s << v[i]; if (i < len - 1) s << "\t";
  }
  s << "\n"; return s;
}

// cout deque
template<typename T> ostream& operator<<(ostream& s, const deque<T>& v) {
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

vvi g;

deque<int> loop;

int dfs(int u) {
  if ((int)g.size() == 0) {
    return 0;
  }
  vi lis;
  for (int v : g[u]) {
    lis.push_back(dfs(v));
  }
  sort(all(lis));
  lis.erase(unique(all(lis)), end(lis));
  int lsz = lis.size();
  rep (i, lsz) {
    if (lis[i] != i) {
      return i;
    }
  }
  return lsz;
}

int main() {
  int n;
  scanf("%d", &n);
  g.resize(n);
  vi p(n);
  rep (i, n) {
    scanf("%d", &p[i]);
    p[i] -= 1;
    g[p[i]].push_back(i);
  }
  set<int> loop_s;
  for (int i = 0; ; i = p[i]) {
    if (loop_s.find(i) != end(loop_s)) {
      loop.push_back(i);
      break;
    }
    loop_s.insert(i);
  }
  while (true) {
    int nex = p[loop.back()];
    if (nex == loop[0]) {
      break;
    }
    loop.push_back(nex);
  }
  int m = loop.size();
  loop.push_back(loop[0]);
  vi grundy(n, -1);

  FOR (i, 1, m+1) {
    for (int u : g[loop[i]]) {
      if (u == loop[i-1]) {
        continue;
      }
      grundy[u] = dfs(u);
    }
  }

  vi cand = {0, 1};
  vi not_cand;
  for (int u : g[loop[0]]) {
    if (u == loop[1]) {
      continue;
    }
    not_cand.push_back(grundy[u]);
  }
  sort(all(not_cand));
  for (int gn : not_cand) {
    if (gn == cand[0]) {
      cand[0] = cand[1];
      cand[1] += 1;
    } else if (gn == cand[1]) {
      cand[1] += 1;
    }
  }

  vi grundy_loop;
  bool ans = false;
  rep (j, 2) {
    grundy_loop.assign(m+1, -1);
    grundy_loop[0] = cand[j];
    FOR (i, 1, m+1) {
      vi ng;
      for (int u : g[loop[i]]) {
        if (u == loop[i-1]) {
          ng.push_back(grundy_loop[i-1]);
        } else {
          ng.push_back(grundy[u]);
        }
      }
      sort(all(ng));
      ng.erase(unique(all(ng)), end(ng));
      ng.push_back(INT_MAX);
      int ngsz = ng.size();
      rep (k, ngsz) {
        if (ng[k] != k) {
          grundy_loop[i] = k;
          break;
        }
      }
    }
    if (grundy_loop[m] == grundy_loop[0]) {
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