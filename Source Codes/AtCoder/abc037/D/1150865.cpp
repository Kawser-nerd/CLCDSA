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

typedef deque<db> ddb;

int mod = 1e9+7;
vi dh = {  0,  1, -1,  0 };
vi dw = {  1,  0,  0, -1 };

int h, w;
vvi a;
vv<pii> g;
ddb searched;
ll ans;
vvi pattern;

int search(int y, int x) {
  if (searched[y][x]) {
    return pattern[y][x];
  }
  searched[y][x] = true;
  ll ret = 0;
  rep (i, 4) {
    int y_ = y + dh[i];
    int x_ = x + dw[i];
    if (a[y][x] < a[y_][x_]) {
      ret += search(y_, x_);
    }
  }
  pattern[y][x] = (int)((ret + 1) % mod);
  return pattern[y][x];
}

int main() {
  scanf("%d %d", &h, &w);
  a.assign(h+2, vi(w+2, 0));
  FOR (i, 1, h+1) {
    FOR (j, 1, w+1) {
      scanf("%d", &a[i][j]);
    }
  }

  searched.assign(h+2, db(w+2, false));
  pattern.assign(h+2, vi(w+2, 0));
  ans = 0;

  FOR (i, 1, h+1) {
    FOR (j, 1, w+1) {
      ans += search(i, j);
      ans %= mod;
    }
  }
  printf("%lld\n", ans);

  return 0;
}