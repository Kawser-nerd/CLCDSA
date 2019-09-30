#include<iostream>
#include<vector>
using namespace std;
 
const int mod=1e9+7;
const int MAX_N=1e5+1;
vector<int> edge[MAX_N];
 
long long dp[MAX_N][2];
 
void solve(int now,int prev){
	dp[now][0]=dp[now][1]=1;
	for(int i=0;i<edge[now].size();i++){
		if(prev!=edge[now][i]){
			solve(edge[now][i],now);
			dp[now][0]=(dp[now][0]*(dp[edge[now][i]][0]+dp[edge[now][i]][1]))%mod;
			dp[now][1]=(dp[now][1]*dp[edge[now][i]][0])%mod;
		}
	}
}
 
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	solve(1,-1);
	cout<<(dp[1][0]+dp[1][1])%mod<<endl;
 
}