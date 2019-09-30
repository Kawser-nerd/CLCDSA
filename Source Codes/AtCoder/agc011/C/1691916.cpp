#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

typedef long long ll;
const int N=100009;
const int M=200009;

int n,m;
int to[M<<1],nxt[M<<1],beg[N],tot;
int col[N],cnt,flag,si,bi,nbi;

inline void add(int u,int v)
{
	to[++tot]=v;
	nxt[tot]=beg[u];
	beg[u]=tot;
}

inline void dfs(int u)
{
	cnt++;
	for(int i=beg[u];i;i=nxt[i])
		if(col[to[i]]==-1)
		{
			col[to[i]]=col[u]^1;
			dfs(to[i]);
		}
		else if(col[to[i]]!=col[u]^1)
			flag=1;
}

int main()
{
	if(fopen("vj.in","r"))
	{
		freopen("vj.in","r",stdin);
		freopen("vj.out","w",stdout);
	}

	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
	}
	
	memset(col,-1,sizeof(col));

	for(int i=1;i<=n;i++)
		if(col[i]==-1)
		{
			cnt=flag=0;
			col[i]=0;
			dfs(i);
			if(cnt==1)si++;
			else if(flag)nbi++;
			else bi++;
		}

	ll ans=0;
	ans=1ll*si*si+2ll*si*(n-si);
	ans+=1ll*nbi*nbi+2ll*bi*nbi;
	ans+=2ll*bi*bi;

	printf("%lld\n",ans);
	return 0;
} ./Main.cpp:33:29: warning: ^ has lower precedence than !=; != will be evaluated first [-Wparentheses]
                else if(col[to[i]]!=col[u]^1)
                        ~~~~~~~~~~~~~~~~~~^
./Main.cpp:33:29: note: place parentheses around the '!=' expression to silence this warning
                else if(col[to[i]]!=col[u]^1)
                                          ^
                        (                 )
./Main.cpp:33:29: note: place parentheses around the ^ expression to evaluate it first
                else if(col[to[i]]!=col[u]^1)
                                          ^
                                    (       )
1 warning generated.