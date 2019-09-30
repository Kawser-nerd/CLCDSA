#include <algorithm>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
 
#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define rep(i,n) FOR(i,0,n)
#define pb push_back
#define all(v) begin(v), end(v)
#define debug(x) cerr<< #x <<": "<<x<<endl
#define debug2(x,y) cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl
 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
template<class T> using vv=vector<vector< T > >;

#define INF 1e9
 
int main() {
  int n, ma, mb;
  scanf("%d %d %d", &n, &ma, &mb);
  vi a(n), b(n), c(n);
  rep (i, n) {
    scanf("%d %d %d", &a[i], &b[i], &c[i]);
  }
  if (n == 1) {
    if (ma * b[0] == mb * a[0]) {
      printf("%d\n", c[0]);
    } else {
      printf("-1\n");
    }
    return 0;
  }
  vvi p1(201, vi(201, INF)), p2(201, vi(201, INF));
  int mid1 = n/2;
  int mid2 = n - mid1;
 
  rep (i, (1 << mid1)) {
    int aa = 0;
    int bb = 0;
    int cost = 0;
    rep (j, mid1) {
      if (((i >> j)&1) == 1) {
        aa += a[j];
        bb += b[j];
        cost += c[j];
      }
    }
    p1[aa][bb] = min(p1[aa][bb], cost);
  }
  rep (i, (1 << mid2)) {
    int aa = 0;
    int bb = 0;
    int cost = 0;
    rep (j, mid2) {
      if (((i >> j)&1) == 1) {
        aa += a[j + mid1];
        bb += b[j + mid1];
        cost += c[j + mid1];
      }
    }
    p2[aa][bb] = min(p2[aa][bb], cost);
  }
 
  int ans = INF;
  rep (i, 201) {
    rep (j, 201) {
      if (p1[i][j] == INF) {
        continue;
      }
      FOR (r, 1, 401) {
        int ra = ma * r;
        int rb = mb * r;
        int i2 = ra - i;
        int j2 = rb - j;
        if (i2 < 0 || j2 < 0) {
          continue;
        }
        if (i2 > 200 || j2 > 200) {
          break;
        }
        if (p2[i2][j2] == INF) {
          continue;
        }
        ans = min(ans, p1[i][j] + p2[i2][j2]);
      }
    }
  }
  if (ans != INF) {
    printf("%d\n", ans);
  } else {
    printf("-1\n");
  }
 
  return 0;
}