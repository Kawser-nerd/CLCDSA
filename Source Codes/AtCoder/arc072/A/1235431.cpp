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

int n;
vi a;
vll accum;
ll count() {
  ll cnt = 0;
  FOR (i, 1, n) {
    accum[i] = accum[i-1] + a[i];
    if (accum[i-1] < 0 && accum[i] <= 0) {
      cnt += 1 - accum[i];
      accum[i] = 1;
    }
    if (accum[i-1] > 0 && accum[i] >= 0) {
      cnt += accum[i] + 1;
      accum[i] = -1;
    }
  }
  return cnt;
}

int main() {
  scanf("%d", &n);
  a.resize(n);
  rep (i, n) {
    scanf("%d", &a[i]);
  }
  accum.assign(n, 0);
  accum[0] = a[0];

  ll cnt_minus = 0;
  if (accum[0] >= 0) {
    cnt_minus += accum[0] + 1;
    accum[0] = -1;
  }
  cnt_minus += count();

  accum.assign(n, 0);
  accum[0] = a[0];
  ll cnt_plus = 0;
  if (accum[0] <= 0) {
    cnt_plus += 1 - accum[0];
    accum[0] = 1;
  }
  cnt_plus += count();
  printf("%lld\n", min(cnt_minus, cnt_plus));

  return 0;
}