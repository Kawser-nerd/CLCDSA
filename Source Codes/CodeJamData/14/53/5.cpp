#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#define maxn 2010
#define maxm 2000000
#define inf 1000000000

using namespace std;

struct node {
	int f,x;
	int next;
};

node e[maxm*2];
int g[maxn];
int m,N,M,S,T;
int level[maxn];
int q[maxn];
bool used[maxn];
int first[maxn];
set<int> hash;

void makeedge(int st,int ed,int c) {
	e[M].f=c; e[M].x=ed; e[M].next=g[st]; g[st]=M;
	++M;
	e[M].f=0; e[M].x=st; e[M].next=g[ed]; g[ed]=M;
	++M;
}

bool bfs() {
	int h=1,t=1;
	q[1]=S;
	for (int i=0;i<=N;++i)
		level[i]=N*10;
	level[S]=0;
	memset(used,false,sizeof(used));
	used[S]=true;
	while (h<=t) {
		int p=g[q[h]];
		while (p!=-1) {
			if (e[p].f && level[q[h]]+1<level[e[p].x]) {
				level[e[p].x]=level[q[h]]+1;
				if (!used[e[p].x]) {
					q[++t]=e[p].x;
					used[q[t]]=true;
					if (q[t]==T) return true;
				}
			}
			p=e[p].next;
		}
		++h;
	}
	return used[T];
}

int dfs(int k,int flow) {
	if (k==T) return flow;
	int p=first[k]; int delta=0; int r=0;
	while (p!=-1) {
		if (e[p].f && level[k]+1==level[e[p].x]) {
			r=dfs(e[p].x,(int)min(e[p].f,flow-delta));
			e[p].f-=r; e[p ^ 1].f+=r;
			delta+=r;
			if (delta==flow) break;
		}
		p=e[p].next;
	}
	first[k]=p;
	return delta;
}

int tt;
int n;
char s[1010];
int id[1010];

int main() {
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);

	scanf("%d",&tt);
	memset(e,0,sizeof(e));
	for (int ii=1;ii<=tt;++ii) {
		scanf("%d\n",&n);
		int cnt=0;
		int ins=0;
		for (int i=1;i<=n;++i) {
			scanf("%c %d\n",&s[i],&id[i]);
			if (s[i]=='E') cnt++,ins++;
			else cnt--;
		}
		s[0]='E'; id[0]=0;
		s[n+1]='L'; id[n+1]=0;
		S=n+2,T=n+3;
		N=n+3;
		memset(g,255,sizeof(g));
		M=0;
		makeedge(S,0,max(0,-cnt));
		makeedge(n+1,T,max(0,-cnt)+cnt);
		for (int i=1;i<=n;++i)
			if (s[i]=='E')
				makeedge(S,i,1);
			else makeedge(i,T,1);
		for (int i=0;i<=n+1;++i)
			if (s[i]=='E') {
				hash.clear();
				for (int j=i+1;j<=n+1;++j) {
					if (s[j]=='L' && (id[i]==0 || id[i]==id[j] || id[j]==0)) {
						//if (id[i]!=0 && id[j]!=0 && hash.find(id[j])!=hash.end()) break;
						if (id[j]==0 || hash.find(id[j])==hash.end()) {
							makeedge(i,j,1);
							hash.insert(id[j]);
						}
					}
					if (s[j]=='E' && id[i]!=0 && id[i]==id[j]) break;
				}
			}

		int res=-1;
		int ans=0;
		for (int pp=max(0,-cnt);pp<=n;++pp) {
			while (bfs()) {
				for (int i=0;i<=N;++i)
					first[i]=g[i];
				ans+=dfs(S,inf);
			}
			if (ans>=ins+pp) {
				res=pp;
				break;
			}
			e[0].f++;
			e[2].f++;
		}

		/*
		for (int i=0;i<=N;++i) {
			for (int p=g[i];p!=-1;p=e[p].next)
				printf("%d:%d %d %d\n",p,i,e[p].x,e[p].f);
		}
		*/

		printf("Case #%d: ",ii);
		if (res==-1) printf("CRIME TIME\n");
		else printf("%d\n",res+cnt);
	}
}

