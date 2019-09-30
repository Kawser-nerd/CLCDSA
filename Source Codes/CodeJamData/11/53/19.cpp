#include <cstdio>
#include <cmath>
#include <cstring>
#include <memory.h>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
const int maxn=102;
const int modo=1000003;
vector<int> edge[maxn*maxn+1];
bool v[maxn*maxn+1];
int n,m;
int vtxcnt,edgcnt;

void insertedge(int sx,int sy,int ex,int ey){
	int st=sx*m+sy;
	int en=ex*m+ey;
	edge[st].push_back(en);
	edge[en].push_back(st);
	return;
}

void init(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<=m*n;i++){
		edge[i].clear();
	}
	for (int i=0;i<n;i++){
		char str[maxn];
		scanf("%s",str);
		for (int j=0;j<m;j++){
			if (str[j]=='-'){
				insertedge(i,(j+m-1)%m,i,(j+1)%m);
			}
			if (str[j]=='|'){
				insertedge((i+n-1)%n,j,(i+1)%n,j);
			}
			if (str[j]=='/'){
				insertedge((i+1)%n,(j+m-1)%m,(i+n-1)%n,(j+1)%m);
			}
			if (str[j]=='\\'){
				insertedge((i+n-1)%n,(j+m-1)%m,(i+1)%n,(j+1)%m);
			}
		}
	}
	memset(v,false,sizeof(v));
	return;
}

void dfs(int k){
	if (v[k]){
		return;
	}
	v[k]=true;
	vtxcnt++;
	for (int i=0;i<edge[k].size();i++){
		edgcnt++;
		dfs(edge[k][i]);
	}
	return;
}

int calc(){
	int ans=1;
	for (int i=0;i<m*n;i++){
		if (v[i]){
			continue;
		}
		vtxcnt=0;
		edgcnt=0;
		dfs(i);
		if (edgcnt!=(vtxcnt*2)){
			return 0;
		}
		ans*=2;
		ans%=modo;
	}
	return ans;
}

int main(){
	int tcase;
	scanf("%d",&tcase);
	for (int i=1;i<=tcase;i++){
		init();
		printf("Case #%d: %d\n",i,calc());
	}
	return 0;
}
