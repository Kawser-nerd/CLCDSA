#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define INF ((1LL<<62)-(1LL<<31))
#define MOD 1000000007

//??????????????????????????
ll heapN,heap[1<<20],heapinv[1<<20];
int PQhikaku(int i,int j);//j???????????true???
void PQchange(int n);
void heap_utod(int n){
	if(2*n>heapN)return;
	int rflag=(2*n+1<=heapN)&&(PQhikaku(2*n,2*n+1));
	if(PQhikaku(n,2*n+rflag)){
		ll temp=heap[2*n+rflag];
		heap[2*n+rflag]=heap[n];
		heap[n]=temp;
		heapinv[heap[n]]=n;
		heapinv[heap[2*n+rflag]]=2*n+rflag;	
		heap_utod(2*n+rflag);
	}
}
void heap_dtou(int n){
	if(n==1||PQhikaku(n,n/2))return;
	ll temp=heap[n];
	heap[n]=heap[n/2];
	heap[n/2]=temp;
	heapinv[heap[n]]=n;
	heapinv[heap[n/2]]=n/2;
	heap_dtou(n/2);
}
ll PQpop(){
	ll rr=heap[1];
	heapinv[heap[1]]=0;
	heap[1]=heap[heapN--];
	heapinv[heap[1]]=1;
	heap_utod(1);
	return rr;
}
void PQpush(ll n){
	heap[++heapN]=n;
	heapinv[heap[heapN]]=heapN;
	heap_dtou(heapN);
}


//?????????????
typedef struct edge{ll s,g,c;}E;
typedef struct graph{
	ll vcnt,ecnt;
	E  e[400010];//?????
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
ll s,t;
void readgraph(){
	//?????
	ll n,m;
	scanf("%lld%lld",&n,&m);
	scanf("%lld%lld",&s,&t);
	s--,t--;
	rep(i,0,m){
		ll x,y,c;
		scanf("%lld%lld%lld",&x,&y,&c);
		x--,y--;
		g.e[2*i].s=x;
		g.e[2*i].g=y;
		g.e[2*i].c=c;
		g.e[2*i+1].s=y;
		g.e[2*i+1].g=x;
		g.e[2*i+1].c=c;
	}
	g.vcnt=n;
	g.ecnt=2*m;
	qsort(g.e,g.ecnt,sizeof(E),esort);

	int p=0;
	rep(i,0,g.vcnt){
		while(p<g.ecnt&&g.e[p].s<i)p++;
		g.id[i]=p;
	}
	g.id[g.vcnt]=g.ecnt;//????
}



//??????????
//??????????????????????????
//????
//????????
//O((E+V)logV)
ll daikusutorappp[1<<20];
ll daikusutora222[1<<20];
void daikusutora2(G g,ll s){
	rep(i,0,g.vcnt)daikusutorappp[i]=i==s?0:INF;
	rep(i,0,g.vcnt)daikusutora222[i]=i==s?1:0;//??
	rep(i,0,g.vcnt)PQpush(i);
	while(heapN){
		ll mv=PQpop();
		for(ll t=g.id[mv];g.e[t].s==mv;t++){
			if(daikusutorappp[g.e[t].g]>daikusutorappp[mv]+g.e[t].c){
				daikusutorappp[g.e[t].g]=daikusutorappp[mv]+g.e[t].c;
				daikusutora222[g.e[t].g]=daikusutora222[mv];//??
				PQchange(g.e[t].g);
			}else if(daikusutorappp[g.e[t].g]==daikusutorappp[mv]+g.e[t].c){//??
				daikusutora222[g.e[t].g]+=daikusutora222[mv];//??
				daikusutora222[g.e[t].g]%=MOD;
			}
		}
	}
}
int PQhikaku(int i,int j){return daikusutorappp[heap[i]]>daikusutorappp[heap[j]];}
void PQchange(int n){if(heapinv[n])heap_dtou(heapinv[n]);}


ll scost[100010],scnt[100010];
ll tcost[100010],tcnt[100010];
int main(){
	readgraph();
	daikusutora2(g,s);
	rep(i,0,g.vcnt){
		scost[i]=daikusutorappp[i];
		scnt[i]=daikusutora222[i];
	}
	daikusutora2(g,t);
	rep(i,0,g.vcnt){
		tcost[i]=daikusutorappp[i];
		tcnt[i]=daikusutora222[i];
	}
	
	ll d=scost[t];
	ll ans=scnt[t]*tcnt[s]%MOD;
	rep(i,0,g.vcnt)if(scost[i]*2==d)ans=(ans-scnt[i]*tcnt[i]%MOD*tcnt[i]%MOD*scnt[i]%MOD+MOD)%MOD;
	rep(i,0,g.ecnt){
		if(scost[g.e[i].s]+g.e[i].c+tcost[g.e[i].g]==d&&scost[g.e[i].s]*2<d&&tcost[g.e[i].g]*2<d){
			ans=(ans-scnt[g.e[i].s]*tcnt[g.e[i].g]%MOD*tcnt[g.e[i].g]%MOD*scnt[g.e[i].s]%MOD+MOD)%MOD;
		}
	}
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘readgraph’:
./Main.c:69:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&m);
  ^
./Main.c:70:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&s,&t);
  ^
./Main.c:74:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld",&x,&y,&c);
   ^