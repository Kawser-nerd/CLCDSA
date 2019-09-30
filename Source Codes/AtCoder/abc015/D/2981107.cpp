#include<iostream>
#include<queue>
#include<bitset>
#include<algorithm>
#include<climits>
#include<vector>
#include<deque>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define fill(x,y) memset(x,y,sizeof(x))
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define dump(a) rep(i,a.size()){ cout<<a[i]<<" "; } cout<<endl;
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define INF INT_MAX/3
#define EPS 1e-7


int main(){
  ll w,n,k;
  ll a[51], b[51];
  cin>>w>>n>>k;
  rep(i,n){
    cin>>a[i]>>b[i];
  }

  ll dp[2][10001][51]; // dp[i][j][k] [0:i)??????j????k??????????????? dp[n][w][k]
  fill(dp,0);

  rep(i,n){
    rep(j,w+1){
      rep(l,k+1){
        if(j-a[i]<0 || l-1<0) //????
          dp[(i+1)&1][j][l] = dp[i&1][j][l];
        else
          dp[(i+1)&1][j][l] = mmax(dp[i&1][j][l], dp[i&1][j-a[i]][l-1]+b[i]);
      }
    }
    /*
    rep(j,w+1){
      rep(l,k+1){ cout<<dp[i&1][j][l]<<" "; } cout<<endl;
    }
    */
  }

  cout<<dp[n&1][w][k]<<endl;

  return 0;
}