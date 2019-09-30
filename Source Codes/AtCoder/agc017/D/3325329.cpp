#include<cstdio>
#include<vector>
#define MAXN 100006
#include<algorithm>
using namespace std;
int d[MAXN],n,u,v;
vector<int> road[MAXN];
void DFS(int x,int fa)
{
	for(int i=0;i<(int)road[x].size();i++)
	{
		int nex=road[x][i];
		if(nex==fa) continue;
		DFS(nex,x);
		d[x]^=(d[nex]+1);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		road[u].push_back(v);
		road[v].push_back(u);
	}
	DFS(1,0);
	if(d[1]) printf("Alice");
	else printf("Bob");
}