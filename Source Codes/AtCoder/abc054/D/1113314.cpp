#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int nmax=40,abmax=10,inf = 1000000;
int a[nmax],b[nmax],c[nmax];
int dp[nmax+1][nmax*abmax+1][nmax*abmax+1];
int main(void){
	int n,ma,mb;
	cin >> n >> ma >> mb;
	for(int i=0;i<n;++i){
		cin >> a[i] >> b[i] >> c[i];
	}
	for(int i = 0; i <= n; ++i){
		for(int ca = 0; ca <= nmax*abmax; ++ca){
			for(int cb = 0; cb <= nmax*abmax; ++cb){
				dp[i][ca][cb]=inf;
			} 
		}
	}
	dp[0][0][0]=0;
	for(int i=0;i<n;++i){
		for(int ca = 0; ca <= nmax*abmax; ++ca){
			for(int cb = 0; cb <= nmax*abmax; ++cb){
				if(dp[i][ca][cb]==inf) continue;
				dp[i+1][ca][cb]=min(dp[i+1][ca][cb],dp[i][ca][cb]);
				dp[i+1][ca+a[i]][cb+b[i]]=min(dp[i+1][ca+a[i]][cb+b[i]],dp[i][ca][cb]+c[i]);
			} 
		}
	}
	int ans=inf;
	for(int ca = 1; ca <= nmax*abmax; ++ca){
		for(int cb = 1; cb <= nmax*abmax; ++cb){
			if(ca*mb==cb*ma) ans=min(ans,dp[n][ca][cb]);
		}
	}
	if(ans==inf) ans=-1;
	cout << ans << endl;
	return 0; 
}