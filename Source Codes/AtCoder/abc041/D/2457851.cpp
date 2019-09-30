#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <deque>
#include <string>
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

// bitdp O(2^n * n)
// 1. memset(dp, -1, sizeof(dp));
// 2. rec(0, 0);

// example of Traveling Salesman Probrem

const int MAX_N = 16;
ll dp[1 << MAX_N];

bool d[MAX_N][MAX_N];

int main(){
  int n, m;
  cin >> n >> m;
  int x[m], y[m];
  memset(d, true, sizeof(d));
  REP(i,m){
    cin >> x[i] >> y[i];
    d[x[i]-1][y[i]-1] = false;
  }

  memset(dp, 0, sizeof(dp));
  dp[0] = 1;
  REP(i, 1<<n){
    REP(j, n){
      if(i & (1<<j)) continue;
      bool flag = true;
      REP(k,n) if((1<<k)&i &&!d[k][j]) flag = false;
      if(flag) dp[i | (1<<j)] += dp[i];
    }
  }
  cout << dp[(1<<n)-1] << endl;

  return 0;
}