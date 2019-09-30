#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 1000010
#define INF 1000000007
int p[N*2],Lp;
struct T
{
	int d,w,e,s;
	T(){}
	T(int _d,int _w,int _e,int _s){d=_d,w=_w,e=_e,s=_s;p[Lp++]=w,p[Lp++]=e;}
};
int n,L;T a[N];
int f[N*2*4],g[N*2*4];
bool cmp(const T&a,const T&b)
{
	return a.d<b.d;
}
int ask(int p,int l,int r,int L,int R)
{
	if(L<=l&&r<=R)return f[p];
	f[p*2+1]=max(f[p*2+1],g[p]);
	g[p*2+1]=max(g[p*2+1],g[p]);
	f[p*2+2]=max(f[p*2+2],g[p]);
	g[p*2+2]=max(g[p*2+2],g[p]);
	int mid=(l+r)/2,S=INF;
	if(L<mid)S=min(S,ask(p*2+1,l,mid,L,R));
	if(mid<R)S=min(S,ask(p*2+2,mid,r,L,R));
	return S;
}
void upd(int p,int l,int r,int L,int R,int x)
{
	if(L<=l&&r<=R){f[p]=max(f[p],x);g[p]=max(g[p],x);return;}
	f[p*2+1]=max(f[p*2+1],g[p]);
	g[p*2+1]=max(g[p*2+1],g[p]);
	f[p*2+2]=max(f[p*2+2],g[p]);
	g[p*2+2]=max(g[p*2+2],g[p]);
	int mid=(l+r)/2;
	if(L<mid)upd(p*2+1,l,mid,L,R,x);
	if(mid<R)upd(p*2+2,mid,r,L,R,x);
	f[p]=min(f[p*2+1],f[p*2+2]);
}
int main()
{
	int _;scanf("%d",&_);
	for(int __=1;__<=_;__++)
	{
		scanf("%d",&n);L=Lp=0;
		for(int i=0;i<n;i++)
		{
			int d,n,w,e,s,dd,dp,ds;
			scanf("%d%d%d%d%d%d%d%d",&d,&n,&w,&e,&s,&dd,&dp,&ds);
			for(int i=0;i<n;i++)
				a[L++]=T(d+dd*i,w+dp*i,e+dp*i,s+ds*i);
		}
		sort(p,p+Lp),Lp=unique(p,p+Lp)-p;
		memset(f,0,sizeof f);
		memset(g,0,sizeof g);
		sort(a,a+L,cmp);
		int S=0;
		for(int i=0,j=0;i<700000;i++)
		{
			int k=j;
			for(;j<L&&a[j].d==i;j++)
			{
				int pl=lower_bound(p,p+Lp,a[j].w)-p,pr=lower_bound(p,p+Lp,a[j].e)-p;
				if(ask(0,0,Lp,pl,pr)<a[j].s)S++;
			}
			for(j=k;j<L&&a[j].d==i;j++)
			{
				int pl=lower_bound(p,p+Lp,a[j].w)-p,pr=lower_bound(p,p+Lp,a[j].e)-p;
				upd(0,0,Lp,pl,pr,a[j].s);
			}
		}
		printf("Case #%d: %d\n",__,S);
	}
	return 0;
}