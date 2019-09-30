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

int n, m, p, q, r;
vvi am;
int ans;

vector<bool> calculated;

int calculate_max_value(int girl) {
  vi value_of_boy(m, 0);
  rep (i, n) {
    if ((girl>>i)&1) {
      rep (j, m) {
        value_of_boy[j] += am[i][j];
      }
    }
  }
  sort(all(value_of_boy), greater<int>());
  int ret = 0;
  rep (i, q) {
    ret += value_of_boy[i];
  }
  return ret;
}

void dfs(int girl, int num_girl) {
  if (calculated[girl]) return;
  calculated[girl] = true;

  if (num_girl == p) {
    ans = max(ans, calculate_max_value(girl));
    return;
  }
  rep (i, n) {
    if (((girl>>i)&1) == 0) {
      dfs(girl|(1<<i), num_girl+1);
    }
  }
}

void solve() {
  ans = 0;
  calculated.assign((1<<n) + 10, false);
  dfs(0, 0);
}

int main() {
  scanf("%d%d%d%d%d", &n, &m, &p, &q, &r);
  am.assign(n, vi(m, 0));
  rep (i, r) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    x -= 1;
    y -= 1;
    am[x][y] = z;
  }

  solve();
  printf("%d\n", ans);

  return 0;
}