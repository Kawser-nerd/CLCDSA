#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
#include "math.h"
#include <complex>
#include <iomanip>
#define ifor(i,a,b) for (int i=(a);i<(b);i++)
#define rfor(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define rep(i,n) for (int i=0;i<(n);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define SIZE 200005
#define UF_MAX 200005
using namespace std;
typedef long double ld;
typedef long long int  lli;
const double eps = 1e-11;
int vex[4]={1,0,-1,0};
int vey[4]={0,1,0,-1};
lli MOD = 1000000007;
//BIT
struct UFind{
	int par[UF_MAX];
	int rank[UF_MAX];

	void init(int n){
		rep(i,n){
			par[i] = i;
			rank[i] = 0;
		}
	}
	int find(int x){
		if(par[x]== x){
			return x;
		}else {
			return par[x]= find(par[x]);
		}
	}
	void unite (int x,int y){
		x =find(x);
		y = find(y);
		if(x==y)return;
		if(rank[x]<rank[y]){
			par[x] = y;
		}
		else {
			par[y] = x;
			if(rank[x] == rank[y])rank[x]++;
		}
	}
	bool same (int x ,int y){
		return find(x)==find(y);
	}
};

struct BIT{
	lli bit[SIZE];
	
	lli sum (int i){
		int s = 0;
		while(i>0){
			s+=bit[i];
			i -= i&-i;
		}
		return s;
	}

	void add(int i,int x){
		while(i<SIZE){
			bit[i] +=x;
			i += i&-i;
		}
	}
};
//MST(??????
//Prime
#define MAX_V 105
typedef pair<int,int> P;
struct Graph{
	int G,V,E;
	vector<pair<int,int> >  Edge[MAX_V];
	int d[MAX_V];
	int dis[MAX_V][MAX_V];
	lli Prim(){
		bool used [MAX_V]={};
		priority_queue<P,vector<P>,greater<P> > que;
		//pair??????????????pos
		que.push(P(0,0));
		lli ans =0;
		while(!que.empty()){
			pair<int,int> cnt = que.top();
			que.pop();
			if(used[cnt.second])continue;
			used[cnt.second]=true;
			ans += cnt.first;
			rep(i,Edge[cnt.second].size()){
				pair<int,int> to = Edge[cnt.second][i];
				if(!used[to.second]){
					que.push(to);
				}
			}
		}
		
		return ans;
	};
	void dijkstra(int s){
		priority_queue<P,vector<P>,greater<P> > que;
		lli INF = 10000000000;
		rep(i,MAX_V)d[i] = INF;
		d[s]=0;
		que.push(P(0,s));
		while(!que.empty()){
			P p = que.top();
			que.pop();
			int v= p.second;
			if(d[v]<p.first)continue;
			rep(i,Edge[v].size()){
				P e = Edge[v][i];
				if(d[e.second]>d[v]+e.first){
					d[e.second] = d[v] + e.first;
					que.push(P(d[e.second],e.second));
				}
			}
		}

	}

};
void solve(){
	int N,M,S;
	cin >> N >> M >> S;
	vector<int> x[UF_MAX];
	int u,v;
	rep(i,M){
		scanf("%d %d",&u,&v);
		x[u].push_back(v);
		x[v].push_back(u);
	}
	UFind uf;
	uf.init(N+3);
	vector<int> ans;
	for(int i = M;i>=1;i--){
		for(int v : x[i]){
			if (v > i) uf.unite(i,v);
		}
		if(uf.same(i,S))ans.push_back(i);
	}
	//reverse(ans.begin(),ans.end());
	for(int i = ans.size()-1;i>=0;i--)cout << ans[i]<<endl;

}
int main(){
	solve();
}