#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define INF ((1LL<<62)-(1LL<<31))
#define MOD 1000000007

typedef struct edge{ll s,g,c;}E;
int edgehikaku(const void*a,const void*b){
	E*p=(E*)a,*q=(E*)b;
	if((*p).s<(*q).s)return -1;
	if((*p).s>(*q).s)return  1;
	if((*p).g<(*q).g)return -1;
	return 1;
}


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



//????????????????????????????
//????????????????????????
//O((E+V)logV)
ll daikusutorappp[100010];
ll daikusutora222[100010];//??
void daikusutora2(ll n,ll s,E*e,ll ecnt){
	qsort(e,ecnt,sizeof(E),edgehikaku);

	ll*es=(ll*)malloc(n*sizeof(ll));
	es[0]=0;
	ll t=0;
	rep(i,1,n){
		while(t<ecnt&&e[t].s<i)t++;
		es[i]=t;
	}
	rep(i,0,n)daikusutorappp[i]=i==s?0:INF;
	rep(i,0,n)daikusutora222[i]=i==s?1:0;//??	
	rep(i,0,n)PQpush(i);
	while(heapN){
		ll mv=PQpop();
		for(ll t=es[mv];e[t].s==mv;t++){
			if(daikusutorappp[e[t].g]>daikusutorappp[mv]+e[t].c){
				daikusutorappp[e[t].g]=daikusutorappp[mv]+e[t].c;
				daikusutora222[e[t].g]=daikusutora222[mv];//??
				PQchange(e[t].g);
			}else if(daikusutorappp[e[t].g]==daikusutorappp[mv]+e[t].c){//??
				daikusutora222[e[t].g]+=daikusutora222[mv];//??
				daikusutora222[e[t].g]%=MOD;
			}
		}
	}
	free(es);
}
int PQhikaku(int i,int j){return daikusutorappp[heap[i]]>daikusutorappp[heap[j]];}
void PQchange(int n){if(heapinv[n])heap_dtou(heapinv[n]);}


ll scost[100010];
ll tcost[100010];
ll scnt[100010];
ll tcnt[100010];
E e[400010];
ll n,m;
int main(){
	scanf("%lld%lld",&n,&m);
	ll s,t;
	scanf("%lld%lld",&s,&t);
	s--,t--;
	rep(i,0,m){
		ll a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		a--,b--;
		e[2*i].s=a;e[2*i+1].s=b;
		e[2*i].g=b;e[2*i+1].g=a;
		e[2*i].c=c;e[2*i+1].c=c;
	}
	daikusutora2(n,s,e,2*m);
	rep(i,0,n){
		scost[i]=daikusutorappp[i];
		scnt[i]=daikusutora222[i];
//		printf("%lld %lld %lld\n",i,scost[i],scnt[i]);
	}
	daikusutora2(n,t,e,2*m);
	rep(i,0,n){
		tcost[i]=daikusutorappp[i];
		tcnt[i]=daikusutora222[i];
//		printf("%lld %lld %lld\n",i,tcost[i],tcnt[i]);
	}
	
	ll d=scost[t];//????
	ll ans=scnt[t]*tcnt[s]%MOD;
	//??i?????s-i-t????
	rep(i,0,n)if(scost[i]*2==d)ans=(ans-scnt[i]*tcnt[i]%MOD*tcnt[i]%MOD*scnt[i]%MOD+MOD)%MOD;
	//?i????????x,y????s-x-y-t??????
	rep(i,0,2*m){
		if(scost[e[i].s]+e[i].c+tcost[e[i].g]==d&&scost[e[i].s]*2<d&&tcost[e[i].g]*2<d){
			ans=(ans-scnt[e[i].s]*tcnt[e[i].g]%MOD*tcnt[e[i].g]%MOD*scnt[e[i].s]%MOD+MOD)%MOD;
//			printf("%lld %lld %lld %lld %lld\n",e[i].s,e[i].g,e[i].c,scost[e[i].s],tcost[e[i].g]);
		}
	}
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:103:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&m);
  ^
./Main.c:105:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&s,&t);
  ^
./Main.c:109:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld",&a,&b,&c);
   ^