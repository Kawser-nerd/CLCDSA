#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
#include "math.h"
#include <complex>
#include <iomanip>
#include <map>
#define ifor(i,a,b) for (int i=(a);i<(b);i++)
#define rfor(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define rep(i,n) for (int i=0;i<(n);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
using namespace std;
typedef long double ld;
typedef long long int  lli;
typedef complex <double> P;
const double eps = 1e-11;
int vex[4]={1,0,-1,0};
int vey[4]={0,1,0,-1};
typedef vector<double> Vec;
typedef vector<int> vec;
typedef vector<Vec> MAT;
typedef vector<vec> mat;
lli MOD=1000000007;
lli dp[1<<16];
int x[16];
int N,M;
lli rec(int bit){
  if(~dp[bit])return dp[bit];
  if((1<<N)-1 == bit)return 1;//?????
  lli ans = 0;
  rep(i,N){
    if(bit&x[i])continue;
    if((bit>>i)&1)continue;
    ans += rec(bit |(1<<i));//or
  }
  return dp[bit]= ans;
}

int main(){
  memset (dp,-1,sizeof(dp));
  cin >> N >> M;
  rep(i,M){
    int a,b;
    cin>> a >> b;
    --a,--b;
    x[a] |= (1<<b);
  }
  cout << rec(0)<<endl;
  
}