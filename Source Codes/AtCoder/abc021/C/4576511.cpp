#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<numeric>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b));i>=((int)(a));i--)
typedef long long ll;
typedef pair<ll, ll> mp;

/*
*/

ll n,a,b,m,d[110],ans[110]={},mod=1e9+7,visited[110]={};
vector<ll> v[110];
queue<ll> Q;

int main(void){
	cin>>n>>a>>b>>m;
	rep(i,m){
		ll x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	//
	reg(i,1,n)d[i]=1e18;
	//
	Q.push(a);
	d[a]=0;
	while(!Q.empty()){
		ll p = Q.front();Q.pop();
		for(ll q:v[p]){
			if(d[q]>d[p]+1){
				d[q]=d[p]+1;
				Q.push(q);
			}
		}
	}
	//
	ans[a]=1;
	Q.push(a);
	while(!Q.empty()){
		ll p = Q.front();Q.pop();
		if(visited[p]==0){//??????????dp??????????
			visited[p]=1;
		}else{
			continue;
		}
		// cout<<p<<":"<<d[p]<<endl;
		for(ll q:v[p]){
			if(d[q]==d[p]+1){
				ans[q]=(ans[q]+ans[p])%mod;
				Q.push(q);
			}
		}
	}
	cout<<ans[b]<<endl;
	return 0;
}