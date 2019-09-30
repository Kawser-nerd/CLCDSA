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

int cnt;
static const int num_pattern = 4;
static const double big_sep = 1e10;
static const double small_sep = 1e-3;

double combination(ll n, ll k) {
  k = min(k, n-k);
  if (k == 0) {
    return 1;
  }
  double ret = 1.0;
  FOR (i, n-k+1, n+1) {
    ret *= i;
    while (ret > big_sep) {
      ret /= num_pattern;
      cnt += 1;
    }
  }
  FOR (i, 1, k+1) {
    ret /= i;
    while (ret < small_sep) {
      ret *= num_pattern;
      cnt -= 1;
    }
  }
  return ret;
}

int main() {
  int n, d;
  scanf("%d %d", &n, &d);
  int x, y;
  scanf("%d %d", &x, &y);
  if (x < 0) {
    x *= (-1);
  }
  if (y < 0) {
    y *= (-1);
  }
  if (x % d != 0 || y % d != 0) {
    printf("0\n");
    return 0;
  }
  x /= d;
  y /= d;
  if (x + y > n || (n - x - y) % 2 != 0) {
    printf("0\n");
    return 0;
  }

  vector<double> ans;
  for (int i = x; n - i >= y; i += 2) {
    // n C i * i C (i-x)/2 * (n-i) C (n-i-y)/2 / 4**n
    cnt = 0;
    double add = 1.0;
    add *= combination(n, i);
    add *= combination(i, (i-x)/2);
    add *= combination(n-i, (n-i-y)/2);
    if (n > cnt) {
      rep (j, n-cnt) {
        add /= num_pattern;
      }
    } else {
      rep (j, cnt-n) {
        add *= num_pattern;
      }
    }
    ans.push_back(add);
  }
  sort(all(ans));
  double result = 0.0;
  rep (i, (int)ans.size()) {
    result += ans[i];
  }

  printf("%.12f\n", result);

  return 0;
}