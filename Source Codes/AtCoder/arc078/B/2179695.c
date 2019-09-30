#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r) for(ll i=(l);i<(r);i++)
ll heapN,heap[1<<20],heapinv[1<<20];
int PQhikaku(int i,int j);
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

typedef struct edge{ll s,g,c;}E;
int edgehikaku(const void*a,const void*b){
	E*p=(E*)a,*q=(E*)b;
	if((*p).s<(*q).s)return -1;
	if((*p).s>(*q).s)return  1;
	if((*p).g<(*q).g)return -1;
	return 1;
}

ll daikusutorappp[100010];
void daikusutora2(ll n,ll s,E*e,ll ecnt){
	qsort(e,ecnt,sizeof(E),edgehikaku);

	ll*es=(ll*)malloc(n*sizeof(ll));
	es[0]=0;
	ll t=0;
	rep(i,1,n){
		while(t<ecnt&&e[t].s!=i)t++;
		es[i]=t;
	}
	rep(i,0,n)daikusutorappp[i]=i==s?0:(1LL<<62)-10;
	rep(i,0,n)PQpush(i);
	while(heapN){
		ll mv=PQpop();
		ll t=es[mv];
		while(e[t].s==mv){
			if(daikusutorappp[e[t].g]>daikusutorappp[mv]+e[t].c){
				daikusutorappp[e[t].g]=daikusutorappp[mv]+e[t].c;
				daikusutorappp[n+e[t].g]=mv;
				PQchange(e[t].g);
			}
			t++;
		}
	}
	free(es);
}
int PQhikaku(int i,int j){return daikusutorappp[heap[i]]>daikusutorappp[heap[j]];}
void PQchange(int n){if(heapinv[n])heap_dtou(heapinv[n]);}


E e[200010];
ll fennec[100010];
ll sunuke[100010];
int main(){
	int n;
	scanf("%d",&n);
	rep(i,0,n-1){
		ll a,b;
		scanf("%lld%lld",&a,&b);
		a--;b--;
		e[2*i].s=a;
		e[2*i].g=b;
		e[2*i].c=1;		
		e[2*i+1].s=b;
		e[2*i+1].g=a;
		e[2*i+1].c=1;
	}
	daikusutora2(n,0,e,2*n-2);
	rep(i,0,n){
		fennec[i]=daikusutorappp[i];
		daikusutorappp[i]=0;
	}
	daikusutora2(n,n-1,e,2*n-2);
	rep(i,0,n){
		sunuke[i]=daikusutorappp[i];
		daikusutorappp[i]=0;
	}
	ll ans=0;
	rep(i,0,n)if(fennec[i]<=sunuke[i])ans++;
	puts(ans>n-ans?"Fennec":"Snuke");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:88:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:91:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&a,&b);
   ^