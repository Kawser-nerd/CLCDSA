#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <functional>
#include <iostream>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n,k,l;
vector<int> G[2][200001];
int num[200001];
int cnt,size,now;
map<P,int> group;
bool used[200001];
int res[200001];
int vs[200001];

void dfs(int v){
	num[v]=cnt;
	for(int i=0;i<G[0][v].size();i++){
		if(num[G[0][v][i]]==-1){
			dfs(G[0][v][i]);
		}
	}
}

void dfs2(int v){
	used[v]=true;
	group[P(now,num[v])]++;
	vs[size++]=v;
	for(int i=0;i<G[1][v].size();i++){
		if(!used[G[1][v][i]]){
			dfs2(G[1][v][i]);
		}
	}
}

int main(void){
	scanf("%d%d%d",&n,&k,&l);
	for(int i=0;i<k;i++){
		int f,t;
		scanf("%d%d",&f,&t);
		f--;
		t--;
		G[0][f].push_back(t);
		G[0][t].push_back(f);
	}
	for(int i=0;i<l;i++){
		int f,t;
		scanf("%d%d",&f,&t);
		f--;
		t--;
		G[1][f].push_back(t);
		G[1][t].push_back(f);
	}
	memset(num,-1,sizeof(num));
	cnt=0;
	for(int i=0;i<n;i++){
		if(num[i]==-1){
			dfs(i);
			cnt++;
		}
	}
	memset(used,false,sizeof(used));
	for(int i=0;i<n;i++){
		if(!used[i]){
			size=0;
			dfs2(i);
			for(int j=0;j<size;j++){
				res[vs[j]]=group[P(now,num[vs[j]])];
			}
			now++;
		}
	}
	for(int i=0;i<n;i++){
		printf("%d%c",res[i],i+1==n?'\n':' ');
	}
	return 0;
}