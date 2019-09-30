/**********************************************************************/
/********                                                      ********/
/********                     Writer:?~~                      ********/
/********                       Lang:C++                       ********/
/********                     Status:Unknow                    ********/
/********                                                      ********/
/**********************************************************************/
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <list>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <cstring>
#include <cmath>
//#include<bits/stdc++.h>
using namespace std;
#define max(a,b,c) (max(a,max(b,c)))

const int INF=0x3f3f3f3f;
const int SIZE=1000005;

vector<pair<int,int> > mp[SIZE];
vector<int> path[SIZE];
bool vis[SIZE];
int par[SIZE],dist[SIZE*2],id[SIZE];
bool use[SIZE];

int getp(int a){
	if(par[a]==a) return a; else return par[a]=getp(par[a]);
}

void mer(int a,int b){
	par[getp(a)]=getp(b);
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int p,q,c;
		scanf("%d%d%d",&p,&q,&c);
		mp[c].push_back(make_pair(p,q));
	}
	int sz=n;
	for(int col=1;col<SIZE;col++){
		for(int i=0;i<mp[col].size();i++){
			int a=mp[col][i].first,b=mp[col][i].second;
			par[a]=a;
			par[b]=b;
			use[a]=use[b]=false;
			id[a]=id[b]=-1;
		}
		for(int i=0;i<mp[col].size();i++){
			mer(mp[col][i].first,mp[col][i].second);
		}
		for(int i=0;i<mp[col].size();i++){
			int a=mp[col][i].first,b=mp[col][i].second;
			if(!use[a]){
				int r=getp(a);
				use[a]=true;
				if(id[r]==-1) id[r]=++sz;
				path[a].push_back(id[r]);
				path[id[r]].push_back(a);
			}
			if(!use[b]){
				int r=getp(b);
				use[b]=true;
				if(id[r]==-1) id[r]=++sz;
				path[b].push_back(id[r]);
				path[id[r]].push_back(b);
			}
		}
	}
	memset(dist,-1,sizeof(dist));
	dist[1]=0;
	queue<int> que;
	que.push(1);
	while(!que.empty()){
		int d=que.front();
		que.pop();
		for(int i=0;i<path[d].size();i++){
			int to=path[d][i];
			if(dist[to]==-1){
				dist[to]=dist[d]+1;
				que.push(to);
			}
		}
	}
	int ans=dist[n];
	if(ans!=-1) ans/=2;
	printf("%d\n",ans);
	return 0;
}