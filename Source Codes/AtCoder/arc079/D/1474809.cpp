/* ***********************************************
Author        :yang12138
Created Time  :2017?08?01? ??? 00?58?00?
File Name     :F.cpp
************************************************ */
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdlib>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef pair<int,int>pii;
#define lson (root<<1)
#define rson (root<<1|1)
 
const int N=2e5+10;
 
vector<int>G[N];
void add_edge(int u,int v){
	G[u].push_back(v);
}
 
bool vis[N];
vector<int>cir;
 
bool dfs(int u,int an){
	vis[u]=1;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(vis[v]){
			if(v==an){
				cir.push_back(an);
				return 1;
			}
		}
		else if(dfs(v,an)){
			cir.push_back(v);
			return 1;
		}
	}
	return 0;
}
 
int dp[N],nex[N];
bool visit[N];
void DP(int u){
	vector<int>dat;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(vis[v]) continue;
		DP(v);
		dat.push_back(dp[v]);
	}

	for(int i=0;i<dat.size();i++) visit[dat[i]]=1;
	for(int i=0;;i++){
		if(!visit[i]) {dp[u]=i;break;}
	}
	for(int i=dp[u]+1;;i++){
		if(!visit[i]) {nex[u]=i;break;}
	}
 
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(vis[v]) continue;
		visit[dp[v]]=0;
	}
}
 
int ans[N];
void solve(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int p;
		scanf("%d",&p);
		add_edge(p,i);
	}
 
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			if(dfs(i,i)) break;
		}
	}
	mem(vis,0);
	for(int i=0;i<cir.size();i++) vis[cir[i]]=1;
 
	for(int i=1;i<=n;i++){
		if(vis[i]){
			DP(i);
		}
	}
 
	/*
	for(int i=0;i<cir.size();i++) cout<<cir[i]<<' ';
	cout<<endl;
	*/
 
 
	bool flag=0;
	ans[cir[0]]=dp[cir[0]];
	for(int i=1;i<cir.size();i++){
		if(ans[cir[i-1]]==dp[cir[i]]) ans[cir[i]]=nex[cir[i]];
		else ans[cir[i]]=dp[cir[i]];
	}
	if(ans[cir[cir.size()-1]]!=dp[cir[0]]) flag=1;
 
	ans[cir[0]]=nex[cir[0]];
	for(int i=1;i<cir.size();i++){
		if(ans[cir[i-1]]==dp[cir[i]]) ans[cir[i]]=nex[cir[i]];
		else ans[cir[i]]=dp[cir[i]];
	}
	if(ans[cir[cir.size()-1]]==dp[cir[0]]) flag=1;
 
	if(flag) printf("POSSIBLE\n");
	else printf("IMPOSSIBLE\n");
	
}
 
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
   	solve(); 
    return 0;
}