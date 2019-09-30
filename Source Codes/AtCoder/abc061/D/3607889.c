#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define INF ((1LL<<62)-(1LL<<31))
#define min(p,q)((p)<(q)?(p):(q))

//?????????????
typedef struct edge{ll s,g,c;}E;
typedef struct graph{
	ll vcnt,ecnt;
	E  e[100010];//?????
	ll id[100010];//?????
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
		ll x,y,c;
		scanf("%lld%lld%lld",&x,&y,&c);
		x--,y--;
		g.e[i].s=x;
		g.e[i].g=y;
		g.e[i].c=-c;
	}
	g.vcnt=n;
	g.ecnt=m;
	qsort(g.e,g.ecnt,sizeof(E),esort);

	int p=0;
	rep(i,0,g.vcnt){
		while(p<g.ecnt&&g.e[p].s<i)p++;
		g.id[i]=p;
	}
	g.id[g.vcnt]=g.ecnt;//????
}

//????????
//?????????????????????
//O(EV)???????OK
ll d[10010];
void berumanfoodo(G g,ll s){
	rep(i,0,g.vcnt)d[i]=i==s?0:INF;
	rep(nnnn,0,g.vcnt-1)rep(i,0,g.ecnt)if(d[g.e[i].s]!=INF)d[g.e[i].g]=min(d[g.e[i].g],d[g.e[i].s]+g.e[i].c);
	rep(nnnn,0,g.vcnt)rep(i,0,g.ecnt)if(d[g.e[i].s]!=INF){
		if(d[g.e[i].g]>d[g.e[i].s]+g.e[i].c)d[g.e[i].g]=-INF;
	}
}

int main(){
	readgraph();
	berumanfoodo(g,0);
	if(d[g.vcnt-1]==-INF)puts("inf");
	else printf("%lld\n",-d[g.vcnt-1]);
	return 0;
} ./Main.c: In function ‘readgraph’:
./Main.c:28:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&m);
  ^
./Main.c:31:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld",&x,&y,&c);
   ^