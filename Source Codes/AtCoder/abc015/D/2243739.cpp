#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
using ll = long long;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define FOR(i,a,n) for(int i = (a); i < (n); ++i)
#define RFOR(i,a,n) for(int i = (a)-1; i >= (n); --i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,n,0)
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int N, W, K;
int a[51], b[51];
int dp[51][10001][51];
int main() {
  cin >> W >> N >> K;
  FOR(i,1,N+1) cin >> a[i] >> b[i];
  FOR(i,1,N+1) FOR(j,1,W+1) FOR(k,1,K+1) {
    dp[i][j][k] = dp[i-1][j][k];
    if (j >= a[i])
      dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-a[i]][k-1]+b[i]);
  }
  cout << dp[N][W][K];
  return 0;
}