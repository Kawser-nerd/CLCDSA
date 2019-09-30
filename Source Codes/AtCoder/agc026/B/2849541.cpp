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

ll gcd(ll a, ll b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

ll calc(ll a, ll b, ll c, ll d) {
  if (a < b) {
    return a;
  }
  ll ra = a % b;
  ll rc = c % b;
  if (ra > rc) {
    return c - rc + ra;
  }
  ra += b;
  return c - rc + ra;
}


bool judge(ll a, ll b, ll c, ll d) {
  if (a < b) {
    return false;
  }
  if (b > d) {
    return false;
  }
  if (b <= c+1) {
    return true;
  }
  // exist in [c+1, b-1] ?
  ll bo= c+1;
  ll to= b-1;


  ll g = gcd(b, d);
  a = calc(a, b, c, d);
  if (a >= b) {
    a -= b;
  }

  ll rbo = bo % g;
  ll rto = rbo - bo + to;
  ll ra = a % g;
  if (ra < rbo) {
    ra += g;
  }
  if (ra <= rto) {
    return false;
  }

  return true;
}

int main() {
  int t;
  scanf("%d", &t);
  rep (i, t) {
    ll a, b, c, d;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    if (judge(a, b, c, d)) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
  return 0;
}