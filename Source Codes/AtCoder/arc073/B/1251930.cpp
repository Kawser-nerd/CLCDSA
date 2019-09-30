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

deque<int> weight_list;
vi weight;
bool judge(int n, int sum, int para) {
  int s = 0;
  int lb = lower_bound(all(weight_list), weight[0] + para) - begin(weight_list);
  if (lb < n) {
    rep (i, n) {
      if (i == lb) { continue; }
      s += weight_list[i];
    }
  } else {
    s += weight_list[lb];
    rep (i, n-1) {
      if (i == lb) { continue; }
      s += weight_list[i];
    }
  }
  return s <= sum;
}

int main() {
  int n, w;
  scanf("%d%d", &n, &w);
  weight.resize(n);
  vi value(n);
  rep (i, n) {
    scanf("%d%d", &weight[i], &value[i]);
  }
  if (weight[0] < 100) {
    vvi dp(n+1, vi(w+1, 0));
    FOR (i, 1, n+1) {
      FOR (j, 1, w+1) {
        dp[i][j] = dp[i-1][j];
        if (j >= weight[i-1]) {
          dp[i][j] = max(dp[i][j], dp[i-1][j-weight[i-1]] + value[i-1]);
        }
      }
    }
    printf("%d\n", dp[n][w]);
    return 0;
  }

  vi sorted_value = value;
  sort(all(sorted_value), greater<int>());
  debug(sorted_value[0]);
  int kosu = w / (weight[0] + 3);
  int ans1= 0;
  rep (i, min(kosu, n)) {
    ans1 += sorted_value[i];
  }

  if (kosu >= n) {
    printf("%d\n", ans1);
    return 0;
  }
  {
    vi sorted_weight = weight;
    sort(all(sorted_weight));
    int wsum = 0;
    rep (i, kosu+1) {
      wsum += sorted_weight[i];
    }
    if (wsum > w) {
      printf("%d\n", ans1);
      return 0;
    }
  }

  vector<priority_queue<int> > vpi(4);
  rep (i, n) {
    int ind = weight[i] - weight[0];
    vpi[ind].push(value[i]);
  }

  weight_list.resize(n);
  rep (i, n) {
    weight_list[i] = weight[i];
  }
  sort(all(weight_list));

  int ans2 = 0;
  int w_ = w;
  rep (j, kosu+1) {
    int ma = 0;
    int ind = 0;
    rep (i, 4) {
      if (vpi[i].empty()) { continue; }
      if (w_ < weight[0] + i) { continue; }
      if (!judge(kosu+1 - j, w_, i)) { continue; }
      if (ma < vpi[i].top()) {
        ma = vpi[i].top();
        ind = i;
      }
    }
    ans2 += ma;
    vpi[ind].pop();
    w_ -= weight[0] + ind;
  }

  printf("%d\n", max(ans1, ans2));

  return 0;
}