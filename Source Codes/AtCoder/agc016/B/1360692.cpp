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

void yes() {
  printf("Yes\n");
  exit(0);
}

void no() {
  printf("No\n");
  exit(0);
}

int main() {
  int n;
  scanf("%d", &n);
  vi a(n);
  rep (i, n) {
    scanf("%d", &a[i]);
  }
  sort(all(a));
  if (a[n-1] - a[0] > 1) {
    no();
  }
  if (a[n-1] - a[0] == 1) {
    int ub = upper_bound(all(a), a[0]) - begin(a);
    if (n - ub == 1) {
      no();
    }
    if (ub + 1 <= a[n-1] && a[n-1] <= ub + (n - ub) / 2) {
      yes();
    } else {
      no();
    }
  }
  if (1 <= a[0] && a[0] <= n / 2) {
    yes();
  } else if (a[0] == n-1) {
    yes();
  } else {
    no();
  }

  return 0;
}