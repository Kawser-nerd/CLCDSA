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
    vector<double> theta;
    theta.reserve(n);
    rep (j, n) {
      if (i == j) {
        continue;
      }
      int dx = x[j] - x[i];
      int dy = y[j] - y[i];
      double tj = atan2(dy, dx);
      theta.push_back(tj);
    }
    sort(all(theta));
    vector<double> ar;
    ar.reserve(3 * n);
    rep (j, n-1) {
      ar.push_back(theta[j] - 2*M_PI);
    }
    rep (j, n-1) {
      ar.push_back(theta[j]);
    }
    rep (j, n-1) {
      ar.push_back(theta[j] + 2*M_PI);
    }
    sort(all(ar));
    int sz = (int)ar.size();
    vvi tpa(n-1, vi(10, 0));
    rep (k, 5) {
      tpa[0][2*k] = lower_bound(all(ar), theta[0] + (k-2) * M_PI/2 - EPS) - begin(ar);
      tpa[0][2*k+1] = upper_bound(all(ar), theta[0] + (k-2) * M_PI/2 + EPS) - begin(ar);
    }
    FOR (j, 1, n-1) {
      tpa[j][0] = tpa[j-1][0];
      while (ar[tpa[j][0]] < theta[j] + (-2) * M_PI/2 - EPS && tpa[j][0] < sz-1) {
        tpa[j][0] += 1;
      }
      tpa[j][1] = max(tpa[j-1][1], tpa[j][0]);
      while (ar[tpa[j][1]] <= theta[j] + (-2) * M_PI/2 + EPS && tpa[j][1] < sz-1) {
        tpa[j][1] += 1;
      }
      FOR (k, 1, 5) {
        tpa[j][2*k] = max(tpa[j-1][2*k], tpa[j][2*k-1]);
        while (ar[tpa[j][2*k]] < theta[j] + (k-2) * M_PI/2 - EPS && tpa[j][2*k] < sz-1) {
          tpa[j][2*k] += 1;
        }
        tpa[j][2*k+1] = max(tpa[j-1][2*k+1], tpa[j][2*k]);
        while (ar[tpa[j][2*k+1]] <= theta[j] + (k-2) * M_PI/2 + EPS && tpa[j][2*k+1] < sz-1) {
          tpa[j][2*k+1] += 1;
        }
      }
    }
    rep (j, n-1) {
      don += tpa[j][2] - tpa[j][1];
      cho += tpa[j][3] - tpa[j][2];
      devnull += tpa[j][5] - tpa[j][4] - 1;
      cho += tpa[j][7] - tpa[j][6];
      don += tpa[j][8] - tpa[j][7];
    }
  }
  cho /= 2;
  don /= 2;
  devnull /= 2;
  ei = (ll)n * (n-1) * (n-2) / 6 - cho - don - devnull;
  printf("%lld %lld %lld\n", ei, cho, don);
  return 0;
}