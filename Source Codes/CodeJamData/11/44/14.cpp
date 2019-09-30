#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int n,m;
int D[400];
int e[4001][2];
vector<int> ngb[400];
queue<int> q;
int ans[4001];
bool marked[4001];
bool adj[400][400];
int addit(int v,int w,int u){
	int ans=0;
	for (int i=0;i<ngb[u].size();++i)
		if ((v==-1 || !adj[e[ngb[u][i]][1]][v]) && !adj[e[ngb[u][i]][1]][w])
			++ans;
	return ans;
}
int tot;
void bfs(){
	memset(D,-1,sizeof D);
	memset(ans,-1,sizeof ans);
	memset(marked,0,sizeof marked);
	D[0]=0;
	while (!q.empty()) q.pop();
	q.push(m+m);
	ans[m+m]=ngb[0].size();
	marked[m+m]=true;
	while (!q.empty()){
		int E=q.front();q.pop();
		int v=e[E][0];
		int w=e[E][1];
		for (int i=0;i<ngb[w].size();++i){
			int nE=ngb[w][i];
			int u=e[nE][1];
			if (D[u]==-1)
				D[u]=D[w]+1;
			if (D[u]==D[w]+1){
				int cur=addit(v,w,u)+ans[E]-1;
				if (u==1)
					tot=max(tot,ans[E]);
				ans[nE]=max(ans[nE],cur);
				if (!marked[nE])
					q.push(nE);
				marked[nE]=true;
			}
		}
	}
}
int main(){
	int tnum,tcou=0;cin>>tnum;
	while (tnum--){
		memset(adj,0,sizeof adj);
		for (int i=0;i<400;++i)
			ngb[i].clear();
		cin>>n>>m;
		for (int i=0;i<n;++i)
			adj[i][i]=true;
		for (int i=0;i<m;++i){
			char temp;
			cin>>e[i][0]>>temp>>e[i][1];
			e[i+m][1]=e[i][0];
			e[i+m][0]=e[i][1];
			ngb[e[i][0]].push_back(i);
			ngb[e[i][1]].push_back(i+m);
			adj[e[i][0]][e[i][1]]=true;
			adj[e[i][1]][e[i][0]]=true;
		}
		e[m+m][0]=-1;
		e[m+m][1]=0;
		tot=0;
		bfs();
		cout<<"Case #"<<++tcou<<": "<<D[1]-1<<' '<<tot<<endl;
	}
	return 0;
}
