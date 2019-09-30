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

int n;
vi x, y, c;

bool possible(double time) {
  double xl, xh, yl, yh;
  double dist = time / c[0];
  xl = x[0] - dist;
  xh = x[0] + dist;
  yl = y[0] - dist;
  yh = y[0] + dist;

  double nxl, nxh, nyl, nyh;
  FOR (i, 1, n) {
    dist = time / c[i];
    nxl = x[i] - dist;
    nxh = x[i] + dist;
    nyl = y[i] - dist;
    nyh = y[i] + dist;
    if (nxh < xl || xh < nxl || nyh < yl || yh < nyl) {
      return false;
    }
    xl = max(xl, nxl);
    xh = min(xh, nxh);
    yl = max(yl, nyl);
    yh = min(yh, nyh);
  }
  return true;
}

int main() {
  scanf("%d", &n);
  x.resize(n);
  y.resize(n);
  c.resize(n);
  rep (i, n) {
    scanf("%d %d %d", &x[i], &y[i], &c[i]);
  }

  double h = 1e9;
  double l = 0.0;
  double mid;
  while (h - l > 1e-5) {
    mid = (h + l) / 2;
    if (possible(mid)) {
      h = mid;
    } else {
      l = mid;
    }
  }
  printf("%.6f\n", h);

  return 0;
}