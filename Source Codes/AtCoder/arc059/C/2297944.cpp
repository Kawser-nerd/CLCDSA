#include<cstring>
#include<string>
#include<vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<list>
#include<set>
#include<map>
#include<complex>
#include<sstream>
#include<climits>
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

const int MAX_N = 400, MAX_C = 400, MAX_X = 400, MOD = 1e9+7;
int N, C;
int A[MAX_N+1], B[MAX_N+1];
ll dp[MAX_N+1][MAX_C+1];
ll sum_pow[MAX_C+1][MAX_X+1];

int main() {
  cin >> N >> C;
  for (int i = 1; i <= N; ++i) cin >> A[i];
  for (int i = 1; i <= N; ++i) cin >> B[i];

  for (int x = 1; x <= MAX_X; ++x) sum_pow[0][x] = x;
  for (int c = 1; c <= MAX_C; ++c) {
    for (int x = 1; x <= MAX_X; ++x) {
      sum_pow[c][x] = (sum_pow[c][x-1] + (sum_pow[c-1][x]-sum_pow[c-1][x-1]+MOD)%MOD*x) % MOD;
    }
  }

  dp[0][0] = 1;
  for (int i = 1; i <= N; ++i) {
    for (int j = 0; j <= C; ++j) {
      for (int k = 0; k <= j; ++k) {
        ll add = (sum_pow[k][B[i]] - sum_pow[k][A[i]-1]+ MOD)%MOD;
        (dp[i][j] += dp[i-1][j-k]*add) %= MOD;
      }
    }
  }


  cout << dp[N][C] << endl;

  return 0;
}