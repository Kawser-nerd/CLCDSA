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

int main() {
  int n;
  scanf("%d", &n);
  vi x(n);
  vector<pii> x_sorted(n);
  vvi a(n, vi(n, -1)); // ???????+1
  rep (i, n) {
    scanf("%d", &x[i]);
    x[i] -= 1;
    a[i][i] = x[i];
    x_sorted[i] = (make_pair(x[i], i));
  }
  sort(all(x_sorted));
  vi order(n*n);
  rep (i, n*n) {
    order[i] = i;
  }
  for (int i = n-1; i >= 0; --i) {
    order.erase(begin(order) + x_sorted[i].first);
  }

  rep (i, n) {
    int xi = x_sorted[i].first;
    if (lower_bound(all(order), xi) - begin(order) < x_sorted[i].second) {
      printf("No\n");
      return 0;
    }
    rep (j, x_sorted[i].second) {
      a[x_sorted[i].second][j] = order[j];
    }
    order.erase(begin(order), begin(order) + x_sorted[i].second);
  }


  rep (i, n) {
    if (order.empty()) {
      break;
    }
    int xi = x_sorted[i].first;
    if (order.at(0) < xi) {
      printf("No\n");
      return 0;
    }
    int offset = x_sorted[i].second + 1;
    FOR (j, offset, n) {
      a[x_sorted[i].second][j] = order[j - offset];
    }
    order.erase(begin(order), begin(order) + (n - offset));
  }

  vi a_print(n*n);
  rep (i, n) {
    rep (j, n) {
      a_print[a[i][j]] = i + 1;
    }
  }
  printf("Yes\n");
  rep (i, n*n-1) {
    printf("%d ", a_print[i]);
  }
  printf("%d\n", a_print[n*n-1]);

  return 0;
}