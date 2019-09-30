#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cassert>
#include <exception>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<string,ll> P;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<P> vp;
#define rep(i,a,n) for(ll i = (a);i < (n);i++)
#define per(i,a,n) for(ll i = (a);i > (n);i--)
#define lep(i,a,n) for(ll i = (a);i <= (n);i++)
#define pel(i,a,n) for(ll i = (a);i >= (n);i--)
#define clr(a,b) memset((a),(b),sizeof(a))
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define sz size()
#define print(X) cout << (X) << endl
const ll INF = 1e+8+7;
ll n,m,l;
string s,t;
int d[100000],dp[50][410][410];
int a[50],b[50],c[50];

int main(){
  cin >> n >> m >> l;
  rep(i,0,n)cin >> a[i] >> b[i] >> c[i];
  lep(i,0,n){
    rep(j,0,410){
      rep(k,0,410){
        dp[i][j][k] = INF;
      }
    }
  }
  dp[0][0][0] = 0;
  rep(i,0,n){
    lep(j,0,400){
      lep(k,0,400){
        if(dp[i][j][k] == INF)continue;
        dp[i+1][j][k] = min(dp[i][j][k],dp[i+1][j][k]);
        dp[i+1][j+a[i]][k+b[i]] = min(dp[i+1][j+a[i]][k+b[i]]+c[i],dp[i][j][k]+c[i]);
      }
    }
  }
  int ans = INF;
  lep(i,1,400){
    lep(j,1,400){
      if(i*l == j*m)ans = min(ans,dp[n][i][j]);
    }
  }
  if(ans == INF)ans = -1;
  print(ans);
  return 0;
}