//Zory-2019
#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<stack>
#include<bitset>
#include<vector>
#include<algorithm>
#include<iostream>
#include<deque>
// #include<unordered_map>
using namespace std;
int bin[40],lg[1<<21];
namespace mine
{
	typedef long long ll;
	#define double long double
	const int INF=0x3f3f3f3f;
	const ll LLINF=0x3f3f3f3f3f3f3f3fll;
	ll qread()
	{
		ll ans=0;char c=getchar();int f=1;
		while(c<'0' or c>'9') {if(c=='-') f=-1;c=getchar();}
		while('0'<=c and c<='9') ans=ans*10+c-'0',c=getchar();
		return ans*f;
	}
	void write(ll num)
	{
		if(num<0) {num=-num;putchar('-');}
		if(num>9) write(num/10);
		putchar('0'+num%10);
	}
	void writeln(int num){write(num);puts("");}
	#define FR first
	#define SE second
	#define MP make_pair
	#define pr pair<int,int>
	#define PB push_back
	#define vc vector
	void chmax(int &x,const int y) {x=x>y?x:y;}
	void chmin(int &x,const int y) {x=x<y?x:y;}
	const int MAX_N=1e5+10;
	const int MOD=1e9+7;
	void add(int &x,int y) {x+=y;if(x>=MOD) x-=MOD;if(x<0) x+=MOD;}

	struct DSU
	{
		int fa[MAX_N],siz[MAX_N];
		void clear(){for(int i=1;i<MAX_N;i++) fa[i]=i,siz[i]=1;}
		int findfa(int x) {return x==fa[x]?x:fa[x]=findfa(fa[x]);}
		void merg(int x,int y)
		{
			int fx=findfa(x),fy=findfa(y);
			if(fx==fy) return;
			if(siz[fx]<siz[fy]) swap(fx,fy);
			siz[fx]+=siz[fy];fa[fy]=fx;
		}
		bool check(int x,int y,int z)
		{
			x=findfa(x),y=findfa(y);
			if(x==y) return siz[x]>=z;
			return siz[x]+siz[y]>=z;
		}
	}dsu;
	int ans[MAX_N];
	pr e[MAX_N];struct Qes{int x,y,z,id,nowl,nowr;}q[MAX_N];
	int ct[MAX_N],now[MAX_N];
	void main()
	{
		int n=qread(),m=qread();
		for(int i=1;i<=m;i++) e[i].FR=qread(),e[i].SE=qread();
		int qq=qread();
		for(int i=1;i<=qq;i++)
		{
			int x=qread(),y=qread(),z=qread();
			q[i]=(Qes){x,y,z,i,1,m};
		}
		for(int T=20;T>=0;T--)
		{
			memset(ct,0,sizeof ct);
			for(int i=1;i<=qq;i++) ct[q[i].nowl]++;
			for(int i=1;i<=m;i++) ct[i]+=ct[i-1];
			for(int i=qq;i>=1;i--) now[ct[q[i].nowl]--]=i;
			dsu.clear();

			// for(int i=1;i<=qq;i++) printf("%d ",now[i]);
			// puts("");

			int fl=1,fr=0;
			for(int mid=1;mid<=m;mid++)
			{
				while(fr+1<=qq and (q[now[fr+1]].nowl+q[now[fr+1]].nowr)/2<=mid) fr++;
				dsu.merg(e[mid].FR,e[mid].SE);
				if(fl<=fr)
				{
					// printf("T=%d mid=%d (%d,%d)\n",T,mid,fl,fr);
					for(int i=fl;i<=fr;i++)
					{
						int t=now[i];if(q[t].nowl>q[t].nowr) continue;
						if(dsu.check(q[t].x,q[t].y,q[t].z)) ans[q[t].id]=mid,q[t].nowr=mid-1;
						else q[t].nowl=mid+1;
					}
					fl=fr+1;
				}
			}
		}
		for(int i=1;i<=qq;i++) writeln(ans[i]);
	}
};
int main()
{
	srand(time(0));
	bin[0]=1;for(int i=1;i<=30;i++) bin[i]=bin[i-1]<<1;
	lg[1]=0;for(int i=2;i<(1<<21);i++) lg[i]=lg[i>>1]+1;
	mine::main();
}