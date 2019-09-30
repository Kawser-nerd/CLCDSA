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
const int MAXN = (1e5) + 4;
int r[30][100005];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, C;
  cin >> N >> C;
  REP(i,N){
    int s, t, c;
    cin >> s >> t >> c;
    c--;
    s--;
    r[c][s]++;
    r[c][t]--;
  }
  REP(i,C)
  REP(j,MAXN){
      r[i][j + 1] += r[i][j];
  }
  int ans = 0;
  REP(i,MAXN){
    int res = 0;
    REP(j,C) if(r[j][i] > 0) res++;
    ans = max(ans, res);
  }
  cout << ans << endl;
  return 0;
}