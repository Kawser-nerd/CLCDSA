#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <bitset>
#include <climits>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define RFOR(i,a,b) for (int i=(a)-1;i>=(b);i--)
#define ll long long
#define ull unsigned long long
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int INF = 1e9;
const ll LL_INF = 1e18;
const int MOD = 1e9 + 7;

using namespace std;

int r[10];
int dist[202][202];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, M, R;
  cin >> N >> M >> R;
  fill(dist[0], dist[N], INF);
  REP(i,R){
    cin >> r[i];
    r[i]--;
  }
  REP(i,M){
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    dist[a][b] = dist[b][a] = c;
  }

  REP(k,N)
    REP(i,N)
    REP(j,N)
    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

  int dp[1 << 8][8];
  fill(dp[0], dp[(1 << 8)], INF);
  REP(i,R){
    dp[1 << i][i] = 0;
  }
  for(int i = 0; i < 1 << R; i++){
    REP(u, R){
      if((i & (1 << u)) == 0) continue;
      REP(v, R){
        if(i & (1 << v)) continue;
        dp[i | (1 << v)][v] = min(dp[i | ( 1 << v)][v], dp[i][u] + dist[r[u]][r[v]]);
      }
    }
  }
  cout << *min_element(dp[(1 << R) - 1], dp[1 << R]) << endl;
  return 0;
} ./Main.cpp:56:15: warning: array index 256 is past the end of the array (which contains 256 elements) [-Warray-bounds]
  fill(dp[0], dp[(1 << 8)], INF);
              ^   ~~~~~~
./Main.cpp:55:3: note: array 'dp' declared here
  int dp[1 << 8][8];
  ^
1 warning generated.