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

int main() {
  int h, w;
  scanf("%d %d", &h, &w);
  int n;
  scanf("%d", &n);
  vi a(n);
  rep (i, n) {
    scanf("%d", &a[i]);
  }
  vvi c(h, vi(w, 0));
  int cnt = 0;
  rep (i, n) {
    rep (j, a[i]) {
      int h_ = cnt / w;
      int w_ = cnt % w;
      if (h_ % 2 == 1) {
        w_ = w-1 - w_;
      }
      c[h_][w_] = i+1;
      cnt += 1;
    }
  }
  rep (i, h) {
    rep (j, w) {
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }

  return 0;
}