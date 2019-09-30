#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define min(p,q)((p)<(q)?(p):(q))
#define INF ((1LL<<62)-(1LL<<31))

typedef struct edge{ll s,g,c;}E;
E e[2010];
ll d[1010];
int n,m;

void berumanfoodo(ll n,ll s){
	rep(i,0,n)d[i]=i==s?0:INF;
	rep(nnnn,0,n-1)rep(i,0,m)if(d[e[i].s]!=INF)d[e[i].g]=min(d[e[i].g],d[e[i].s]+e[i].c);
	rep(nnnn,0,n)rep(i,0,m)if(d[e[i].s]!=INF){
		if(d[e[i].g]>d[e[i].s]+e[i].c)d[e[i].g]=-INF;
	}
}

int main(){
	scanf("%d%d",&n,&m);
	rep(i,0,m){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		a--;
		b--;
		e[i].s=a;
		e[i].g=b;
		e[i].c=-c;
	}
	berumanfoodo(n,0);
	if(d[n-1]==-INF)puts("inf");
	else printf("%lld\n",-d[n-1]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&a,&b,&c);
   ^