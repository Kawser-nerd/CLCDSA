#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <complex>
#include <valarray>
//#include <unordered_map>
//#include <array>
#include <fstream>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
//#include <random>
#include <numeric>

#define INIT std::ios::sync_with_stdio(false);std::cin.tie(0);
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define mod(n, m) (((n)%(m)+(m))%m)
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
const int INFINT = 1 << 30;                          // 1.07x10^ 9
const ll INFLL = 1LL << 60;                          // 1.15x10^18
const double EPS = 1e-10;
const int MOD = 1000000007;

const int MAX_N = 1000, MAX_X = 5000;
int N;
int P[MAX_N];
int X[MAX_N];
int dp[MAX_N][MAX_X+1];
vector<int> child[MAX_N];

int memo_dp(int n, int k, vector<Pii> vp) {
  if (n == -1) return 0; 
  if (dp[n][k] >= -1) return dp[n][k];
  int ma = -1;
  if (k >= vp[n].fi) {
    int tmp = memo_dp(n-1, k-vp[n].fi, vp);
    if (tmp >= 0) ma = tmp + vp[n].fi;
  }
  if (k >= vp[n].sc) {
    int tmp = memo_dp(n-1, k-vp[n].sc, vp);
    if (tmp >= 0) ma = max(ma, tmp + vp[n].sc);
  }
  return dp[n][k] = ma;
}

Pii rec(int v) {
  if (child[v].size() == 0) return Pii(X[v], 0);

  vector<Pii> vp;
  int sum = 0;
  for (int i = 0; i < child[v].size(); ++i) {
    Pii pii = rec(child[v][i]);
    if (pii.fi < 0) return Pii(-1, 0);
    sum += pii.fi + pii.sc;
    vp.push_back(pii);
  }

  for (int i = 0; i <= child[v].size(); ++i) {
    for (int j = 0; j <= X[v]; ++j) {
      dp[i][j] = -2;
    }
  }
  int ma = memo_dp(child[v].size()-1, X[v], vp);

  if (ma < 0) return Pii(-1, 0);
  else {
    return Pii(X[v], sum-ma);
  }
}


int main() {

  cin >> N;
  for (int i = 1; i < N; ++i) {
    cin >> P[i]; --P[i];
  }
  for (int i = 0; i < N; ++i) cin >> X[i];

  if (N == 1) {
    cout << "POSSIBLE" << endl;
    return 0;
  }

  for (int i = 1; i < N; ++i) {
    child[P[i]].push_back(i);
  }

  Pii pii = rec(0);

  if (pii.fi <= 0) cout << "IMPOSSIBLE" << endl;
  else cout << "POSSIBLE"  << endl;

  return 0;
}