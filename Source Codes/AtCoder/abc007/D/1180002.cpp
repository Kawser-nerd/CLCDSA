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

//         0  1  2  3  4  5  6  7  8  9
vi wo49 = {0, 1, 2, 3, 4, 4, 5, 6, 7, 8};

ll po8(int x) {
  return (ll)1 << (3 * x);
}

ll without49(ll n) {
  string s = to_string(n);
  int nd = s.length();
  ll ret = 0;
  rep (i, nd) {
    ret += (wo49[s[i] - '0']) * po8(nd-1-i);
    if (s[i] == '4' || s[i] == '9') {
      return ret;
    }
  }
  return ret + 1; // include n
}


int main() {
  ll a, b;
  scanf("%lld %lld", &a, &b);
  a -= 1;
  ll ans = without49(b) - without49(a);
  ans = (b - a) - ans;
  printf("%lld\n", ans);

  return 0;
}