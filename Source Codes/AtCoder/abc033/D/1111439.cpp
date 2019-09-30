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
typedef pair<double, int> pdi;

#define EPS 1e-14

int main() {
  int n;
  scanf("%d", &n);
  vi x(n), y(n);
  rep (i, n) {
    scanf("%d %d", &x[i], &y[i]);
  }
  ll ei, cho, don, devnull;
  ei = cho = don = devnull = 0;
  rep (i, n) {
    vector<double> ar;
    ar.reserve(3 * n);
    vector<double> theta(n, 0);
    rep (j, n) {
      if (i == j) {
        continue;
      }
      int dx = x[j] - x[i];
      int dy = y[j] - y[i];
      theta[j] = atan2(dy, dx);
      for (int k = -1; k <= 1; ++k) {
        ar.push_back(theta[j] + k * 2*M_PI);
      }
    }
    sort(all(ar));
    ll dcho, ddon, ddevnull;
    dcho = ddon = ddevnull = 0;
    rep (j, n) {
      if (i == j) {
        continue;
      }
      vi lb(5), ub(5);
      for (int k = -2; k <= 2; ++k) {
        lb[k+2] = lower_bound(all(ar), theta[j] + k * M_PI/2 - EPS) - begin(ar);
        ub[k+2] = upper_bound(all(ar), theta[j] + k * M_PI/2 + EPS) - begin(ar);
      }
      don += lb[1] - ub[0];
      cho += ub[1] - lb[1];
      devnull += ub[2] - lb[2] - 1;
      cho += ub[3] - lb[3];
      don += lb[4] - ub[3];
      devnull += ub[4] - lb[4];
    }
  }
  cho /= 2;
  don /= 2;
  devnull /= 6;
  ei = (ll)n * (n-1) * (n-2) / 6 - cho - don - devnull;
  printf("%lld %lld %lld\n", ei, cho, don);
  return 0;
}