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

// cout 2-dimentional vector
template<typename T> ostream& operator<<(ostream& s, const vector< vector<T> >& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) { s << vv[i]; }
  return s;
}


int main() {
  int n;
  scanf("%d", &n);
  vvi a(n, vi(n, 0));
  rep (i, n) {
    rep (j, n) {
      scanf("%d", &a[i][j]);
    }
  }
  int INF = INT_MAX / 2;
  vvi kingdom(n, vi(n, INF));
  rep (i, n) {
    rep (j, n) {
      if (i == j) { continue; }
      bool flag;
      flag = false;
      rep (k, n) {
        if (i == k || j == k) { continue; }
        if (a[i][k] + a[k][j] < a[i][j]) {
          printf("-1\n");
          return 0;
        }
        if (a[i][k] + a[k][j] == a[i][j]) {
          flag = true;
          break;
        }
      }
      if (flag) {
      } else {
        kingdom[i][j] = kingdom[j][i] = a[i][j];
      }
    }
  }

  ll ans = 0;
  rep (i, n) {
    rep (j, n) {
      if (kingdom[i][j] < INF) {
        ans += kingdom[i][j];
      }
    }
  }
  ans /= 2;
  printf("%lld\n", ans);

  return 0;
}