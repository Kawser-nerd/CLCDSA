#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>
#include <queue>
#include <math.h>
#include <set>
#include <cstring>

using namespace std;
#define LL long long
using VS = vector<string>;
using VI = vector<int>;
using VL = vector<LL>;
using VVI = vector<VI>;
using VVL = vector<VL>;
#define FOR(i,s,e) for(i = s; i < e; i++)
#define FORR(i,s,e) for(i = e-1; i >= s; i--)
const LL INF = (LL)1e16;
const LL MOD = (LL)1e9 + 7;

int f(LL i, LL j){
  int y = j/5;
  int x = j%5;
  if (x > 0 && x < 4){
    if ((i&(1<<(j-1))) == 0 && (i&(1<<(j+1))) > 0) return 0;
    if ((i&(1<<(j-1))) > 0 && (i&(1<<(j+1))) == 0) return 0;
  }
  if (y > 0 && y < 4){
    if ((i&(1<<(j-5))) == 0 && (i&(1<<(j+5))) > 0) return 0;
    if ((i&(1<<(j-5))) > 0 && (i&(1<<(j+5))) == 0) return 0;
  }
  return 1;
}
int dp[1<<25];

int main(){
  int n,i,j,k,a[5][5],alr[26];
  set<LL> l,li,li2,b;
  char c;
  FOR(i,0,5){
    cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4];
  }
  memset(dp,0,sizeof(dp));
  dp[0] = 1;
  memset(alr,-1,sizeof(alr));
  FOR(i,0,5)FOR(j,0,5){
    if (a[i][j] > 0) alr[a[i][j]] = i*5+j;
    else l.insert(i*5+j);
  }
  li = {0};
  FOR(n,0,25){
    li2 = {};
    if (alr[n+1] >= 0) b = {alr[n+1]};
    else b = l;
    for (auto j:b){
      k = (1<<j);
      for (auto i:li){
        if (i&k) continue;
        dp[i|k] += dp[i]*f(i,j);
        dp[i|k] %= MOD;
        li2.insert(i|k);
      }
    }
    li = li2;
  }
  cout << dp[(1<<25)-1] << endl;
  return 0;
}