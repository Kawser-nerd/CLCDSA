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

int n, m;
vvi g;
vll dp;
deque<bool> calculated;

ll solve(int index) {
  if (calculated[index]) {
    return dp[index];
  }
  set<int> s;
  rep (i, n) {
    if (((index >> i) & 1) == 1) {
      s.insert(i);
    }
  }
  for (int i : s) {
    bool continue_flag = false;
    for (int j : s) {
      if (i == j) {
        continue;
      }
      if (g[i][j] == 1) {
        continue_flag = true;
        break;
      }
    }
    if (continue_flag) {
      continue;
    }
    dp[index] += solve(index - (1 << i));
  }
  calculated[index] = true;
  return dp[index];
}

int main() {
  scanf("%d %d", &n, &m);
  g.assign(n, vi(n, 0));
  rep (i, m) {
    int x, y;
    scanf("%d %d", &x, &y);
    x -= 1;
    y -= 1;
    g[x][y] = 1;
  }
  dp.assign((1 << n), 0);
  calculated.assign((1 << n), false);
  rep (i, n) {
    int index = (1 << i);
    dp[index] = 1;
    calculated[index] = true;
  }
  ll ans = solve((1 << n) - 1);
  printf("%lld\n", ans);

  return 0;
}