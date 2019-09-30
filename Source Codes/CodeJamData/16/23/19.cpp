#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <string>
#include <iostream>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int inf=0x20202020;
typedef int flowt;
namespace flow {
	const int M=100000,N=1000;
	int y[M],nxt[M],gap[N],fst[N],c[N],pre[N],q[N],dis[N];
	flowt f[M];
	int S,T,tot,Tn;
	void init(int s,int t,int tn) {
		tot=1; assert(tn<N);
		rep(i,0,tn) fst[i]=0;
		S=s;T=t;Tn=tn;
	}
	void add(int u,int v,flowt c1,flowt c2=0) {
		tot++;y[tot]=v;f[tot]=c1;nxt[tot]=fst[u];fst[u]=tot;
		tot++;y[tot]=u;f[tot]=c2;nxt[tot]=fst[v];fst[v]=tot;
	}
	flowt sap() {
		int u=S,t=1;flowt flow=0;
		rep(i,0,Tn) c[i]=fst[i],dis[i]=Tn,gap[i]=0;
		q[0]=T;dis[T]=0;pre[S]=0;
		rep(i,0,t) {
			int u=q[i];
			for (int j=fst[u];j;j=nxt[j]) if (dis[y[j]]>dis[u]+1&&f[j^1]) 
				q[t++]=y[j],dis[y[j]]=dis[u]+1;
		}
		rep(i,0,Tn) gap[dis[i]]++;
		while (dis[S]<=Tn) {
			while (c[u]&&(!f[c[u]]||dis[y[c[u]]]+1!=dis[u])) c[u]=nxt[c[u]];
			if (c[u]) {
				pre[y[c[u]]]=c[u]^1;
				u=y[c[u]];
				if (u==T) {
					flowt minf=inf;
					for (int p=pre[T];p;p=pre[y[p]]) minf=min(minf,f[p^1]);
					for (int p=pre[T];p;p=pre[y[p]]) f[p^1]-=minf,f[p]+=minf;
					flow+=minf;u=S;
				}
			} else {
				if (!(--gap[dis[u]])) break;
				int mind=Tn;
				c[u]=fst[u];
				for (int j=fst[u];j;j=nxt[j]) if (f[j]&&dis[y[j]]<mind) 
					mind=dis[y[j]],c[u]=j;
				dis[u]=mind+1;
				gap[dis[u]]++;
				if (u!=S) u=y[pre[u]];
			}
		}
		return flow;
	}
};

const int N=10100;
int _,__,n;
PII p[N];
string s1,s2;
map<string,int> hs1,hs2;
int main() {
	for (scanf("%d",&_);_;_--) {
		printf("Case #%d: ",++__);
		scanf("%d",&n);
		hs1.clear(); hs2.clear();
		int l=0,r=0;
		rep(i,0,n) {
			cin>>s1>>s2;
			if (!hs1.count(s1)) hs1[s1]=l++;
			if (!hs2.count(s2)) hs2[s2]=r++;
			p[i]=mp(hs1[s1],hs2[s2]);
		}
		flow::init(l+r,l+r+1,l+r+2);
		rep(i,0,l) flow::add(l+r,i,1);
		rep(i,0,r) flow::add(i+l,l+r+1,1);
		rep(i,0,n) flow::add(p[i].fi,p[i].se+l,1);
		int ret=l+r-flow::sap();
		printf("%d\n",n-ret);
	}
}
