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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  int a[2][200];
  REP(i,2)
  REP(j,N){
    cin >> a[i][j];
  }
  int u = 0, d = a[1][N-1];
  int ans = 0;
  REP(j,N) u += a[0][j];
  ans = max(ans, u + d);
  RREP(i,N){
    if(i == 0) continue;
    d += a[1][i - 1];
    u -= a[0][i];
    ans = max(ans, u + d);
  }
  cout << ans << endl;
  return 0;
}