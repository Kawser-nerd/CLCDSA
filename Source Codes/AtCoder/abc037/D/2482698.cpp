#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <deque>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define ALL(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

double EPS = 1e-9;
int INFi = 1000000005;
long long INFll = 1000000000000000005ll;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};
ll MOD = 1000000007;

const int MAX_H = 1000;
const int MAX_W = 1000;
ll dp[MAX_H][MAX_W];
ll a[MAX_H][MAX_W];
int h, w;

ll dfs(int i, int j){
  if(dp[i][j]>0) return dp[i][j];
  ll res = 1;
  REP(k,4){
    int x = dirx[k] + i;
    int y = diry[k] + j;
    if(x>=0 && x < h && y >= 0 && y < w){
      if(a[x][y] > a[i][j]){
        res = (res + dfs(x,y)) % MOD;
      }
    }
  }
  return dp[i][j] = res;
}

int main(){
  cin >> h >> w;
  REP(i,h)REP(j,w) cin >> a[i][j];

  memset(dp, 0, sizeof(dp));

  ll ans = 0;
  REP(i,h)REP(j,w){
    if(dp[i][j] == 0){
      dfs(i,j);
    }
    ans = (ans + dp[i][j]) % MOD;
  }
  cout << ans << endl;

  return 0;
}