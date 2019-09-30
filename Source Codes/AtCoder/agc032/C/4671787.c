#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define bit(n,m)(((n)>>(m))&1)
int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
int downll(const void*a, const void*b){return*(ll*)a<*(ll*)b?1:*(ll*)a>*(ll*)b?-1:0;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}
void sortdown(ll*a,int n){qsort(a,n,sizeof(ll),downll);}
ll pom(ll a,ll n,int m){ll x=1;for(a%=m;n;n/=2)n&1?x=x*a%m:0,a=a*a%m;return x;}
//#define MOD 998244353
#define MOD 1000000007
#define invp(a,p)pom(a,p-2,p)


ll deg[100010];
//?????????????
typedef struct edge{ll s,g;}E;
typedef struct graph{
	int vcnt,ecnt;
	E  e[200010];//?????
	int id[100010];//?????
}G;

int esort(const void*a,const void*b){
	E*p=(E*)a,*q=(E*)b;
	if((*p).s<(*q).s)return -1;
	if((*p).s>(*q).s)return  1;
	if((*p).g<(*q).g)return -1;
	return 1;
}
G g;
void readgraph(){
	//?????
	ll n,m;
	scanf("%lld%lld",&n,&m);
	rep(i,0,m){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		x--,y--;
		g.e[2*i].s=x;
		g.e[2*i].g=y;
		g.e[2*i+1].s=y;
		g.e[2*i+1].g=x;
		deg[x]++;
		deg[y]++;
	}
	g.vcnt=n;
	g.ecnt=2*m;
	qsort(g.e,g.ecnt,sizeof(E),esort);

	int p=0;
	rep(i,0,g.vcnt){
		while(p<g.ecnt&&g.e[p].s<i)p++;
		g.id[i]=p;
	}
	g.id[g.vcnt]=g.ecnt;//??
}

int f(int v1,int v2){
	int cnt=0;//????
	rep(i,0,4){
		int pre=v1;
		int t=g.e[g.id[v1]+i].g;
		while(t!=v1&&t!=v2){
			if(g.e[g.id[t]].g!=pre){
				pre=t;
				t=g.e[g.id[t]].g;
			}else{
				pre=t;
				t=g.e[g.id[t]+1].g;
			}
		}
		if(t==v2)cnt++;
	}
	return cnt==2;
}

int main(){
	readgraph();
	
	int flag=0;
	rep(i,0,g.vcnt){
		if(deg[i]%2){
			puts("No");
			return 0;
		}
		if(deg[i]==4)flag++;
		if(deg[i]>=6)flag=3;
	}
	
	if(flag>=3)puts("Yes");
	else if(flag<=1)puts("No");
	else {
		//4?????2??????
		int v1=-1,v2=-1;
		rep(i,0,g.vcnt){
			if(deg[i]==4){
				if(v1==-1)v1=i;
				else{
					v2=i;
					puts(f(v1,v2)?"Yes":"No");
					return 0;
				}
			}
		}
	}
} ./Main.c: In function ‘readgraph’:
./Main.c:41:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&m);
  ^
./Main.c:44:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&x,&y);
   ^