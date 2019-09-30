#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cassert>
#include<queue>
#define rep(ii,aa,bb) for(int ii=aa;ii<=bb;ii++)
using namespace std;
typedef long long int ll;
ll n;
string s;
ll m;
ll dp[5005][5005]; //dp[i][j]????i??j
int main(){
	cin>>n>>s;
	m=s.size();
	rep(j,0,n)dp[0][j]=0;
	dp[0][0]=1;
	rep(i,1,n)rep(j,0,n){
		if(j==0)dp[i][j]=dp[i-1][j]+2*dp[i-1][j+1];else
		dp[i][j]=dp[i-1][j-1]+2*dp[i-1][j+1];
		dp[i][j]%=1000000007;
	}
//	rep(i,0,n){rep(j,0,n)printf("%4lld",dp[i][j]);printf("\n");}
	printf("%lld",dp[n][m]);
	return 0;
}