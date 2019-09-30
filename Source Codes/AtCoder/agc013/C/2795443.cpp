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


int per(ll x, int y) {
  int ret = x % y;
  if (ret < 0) {
    ret += y;
  }
  return ret;
}

int n, l, t;

int main() {
  scanf("%d %d %d", &n, &l, &t);
  vi x(n), w(n);
  vi vel(n);
  ll vel_sum = 0;
  rep (i, n) {
    scanf("%d %d", &x[i], &w[i]);
    if (w[i] == 1) {
      vel[i] = 1;
    } else {
      vel[i] = -1;
    }
    vel_sum += vel[i];
  }
  vi pos(n);
  rep (i, n) {
    pos[i] = x[i] + t * vel[i];
    pos[i] = per(pos[i], l);
  }
  sort(all(pos));
  ll diff = 0;
  rep (i, n) {
    diff += pos[i] - x[i];
  }
  assert ((vel_sum * t - diff) % l == 0);
  ll adj = (vel_sum * t - diff) / l;
  adj = per(adj, n);
  rep (i, n) {
    printf("%d\n", pos[(i+adj) % n]);
  }

  return 0;
}