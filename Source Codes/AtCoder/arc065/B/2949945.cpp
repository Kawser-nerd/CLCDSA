#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
#define N 200005
#define M 100005
struct node1{
	int to,nxt;
}e1[2*M];
int fir1[N],cnt1;
void adde1(int a,int b)
{
	e1[++cnt1].to=b;
	e1[cnt1].nxt=fir1[a];
	fir1[a]=cnt1;
	e1[++cnt1].to=a;
	e1[cnt1].nxt=fir1[b];
	fir1[b]=cnt1;
}
int vis1[N],tot1;
void dfs1(int u)
{
	int v,p;
	vis1[u]=tot1;
	for(p=fir1[u];p;p=e1[p].nxt){
		v=e1[p].to;
		if(!vis1[v])
			dfs1(v);
	}
}

struct node2{
	int to,nxt;
}e2[2*M];
int fir2[N],cnt2;
void adde2(int a,int b)
{
	e2[++cnt2].to=b;
	e2[cnt2].nxt=fir2[a];
	fir2[a]=cnt2;
	e2[++cnt2].to=a;
	e2[cnt2].nxt=fir2[b];
	fir2[b]=cnt2;
}
int vis2[N],tot2;
void dfs2(int u)
{
	int v,p;
	vis2[u]=tot2;
	for(p=fir2[u];p;p=e2[p].nxt){
		v=e2[p].to;
		if(!vis2[v])
			dfs2(v);
	}
}
map<long long,int >b;
int main()
{
	int n,m1,m2,u,v,i;
	scanf("%d%d%d",&n,&m1,&m2);
	for(i=1;i<=m1;i++){
		scanf("%d%d",&u,&v);
		adde1(u,v);
	}
	for(i=1;i<=n;i++)
		if(!vis1[i]){tot1++;dfs1(i);}
	
	for(i=1;i<=m2;i++){
		scanf("%d%d",&u,&v);
		adde2(u,v);
	}
	for(i=1;i<=n;i++)
		if(!vis2[i]){tot2++;dfs2(i);}
	
	for(i=1;i<=n;i++)
		b[1ll*vis1[i]*N+1ll*vis2[i]]++;
	for(i=1;i<=n;i++){
		printf("%d",b[1ll*vis1[i]*N+1ll*vis2[i]]);
		if(i!=n)printf(" ");
	}
}