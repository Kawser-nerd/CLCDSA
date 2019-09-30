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

int n, m;;
vvll x;

ll calc() {
  vll sumx(n, 0);
  rep (i, n) {
    rep (j, 3) {
      sumx[i] += x[i][j];
    }
  }
  sort(all(sumx), std::greater<>());
  ll ret = 0;
  rep (i, m) {
    ret += sumx[i];
  }
  return ret;
}


int main() {
  scanf("%d %d", &n, &m);
  x.assign(n, vll(3, 0));
  rep (i, n) {
    rep (j, 3) {
      scanf("%lld", &x[i][j]);
    }
  }
  /*
  vi gray(8);
  rep (i, 8) {
    gray[i] = (i ^ (i >> 1));
  }
  debug(gray);
  */
  vi change = {0, 1, 0, 2, 0, 1, 0};
  ll ans = 0;
  ans = max(ans, calc());
  rep (i, 7) {
    rep (j, n) {
      x[j][change[i]] *= (-1);
    }
    ans = max(ans, calc());
  }
  printf("%lld\n", ans);

  return 0;
}