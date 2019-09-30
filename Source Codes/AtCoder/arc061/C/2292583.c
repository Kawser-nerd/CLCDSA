#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))

typedef struct edge{ll s,g,c;}E;
typedef struct vertex{ll eki,rosen;}V;

int edgehikaku(const void*a,const void*b){
	E*p=(E*)a,*q=(E*)b;
	if((*p).s<(*q).s)return -1;
	if((*p).s>(*q).s)return  1;
	if((*p).g<(*q).g)return -1;
	return 1;
}


int vsort(const void*a,const void*b){
	V*p=(V*)a,*q=(V*)b;
	if((*p).eki<(*q).eki)return -1;
	if((*p).eki>(*q).eki)return  1;
	if((*p).rosen<(*q).rosen)return -1;
	return 1;
}
int unique(V*a,int cnt){
	qsort(a,cnt,sizeof(V),vsort);
	int c=0;
	rep(i,1,cnt)if(a[i].eki!=a[c].eki||a[i].rosen!=a[c].rosen)a[++c]=a[i];
	return c+1;
}



//??????????????????????????
ll heapN,heap[1210000],heapinv[1210000];
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

//???????????????????????????????
//????????????????????????
//O((E+V)logV)
ll daikusutorappp[1<<21];
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
	rep(i,0,n)PQpush(i);
	while(heapN){
		ll mv=PQpop();
		ll t=es[mv];
		while(e[t].s==mv){
			if(daikusutorappp[e[t].g]>daikusutorappp[mv]+e[t].c){
				daikusutorappp[e[t].g]=daikusutorappp[mv]+e[t].c;
				PQchange(e[t].g);
			}
			t++;
		}
	}
	free(es);
}
int PQhikaku(int i,int j){return daikusutorappp[heap[i]]>daikusutorappp[heap[j]];}
void PQchange(int n){if(heapinv[n])heap_dtou(heapinv[n]);}



E e[1200010];
V v[800010];
ll vcnt,ecnt;

int bs(int eki,int rosen){
	int l=0,r=vcnt;
	while(r-l>1){
		int m=(l+r)/2;
		if(v[m].eki<eki||(v[m].eki==eki&&v[m].rosen<=rosen))l=m;
		else r=m;
	}
	return l;
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,0,m){
		int p,q,c;
		scanf("%d%d%d",&p,&q,&c);
		v[vcnt].eki=p;v[vcnt].rosen=c;vcnt++;
		v[vcnt].eki=q;v[vcnt].rosen=c;vcnt++;
		v[vcnt].eki=p;v[vcnt].rosen=-1;vcnt++;
		v[vcnt].eki=q;v[vcnt].rosen=-1;vcnt++;
		
		//??????
		e[ecnt].s=p;e[ecnt].g=q;e[ecnt].c=c;ecnt+=6;
	}

	v[vcnt].eki=1;v[vcnt].rosen=-1;vcnt++;
	v[vcnt].eki=n;v[vcnt].rosen=-1;vcnt++;
	vcnt=unique(v,vcnt);
	
	//??????
	repp(i,0,ecnt,6){
		int p=e[i].s,q=e[i].g,c=e[i].c;
		int v1=bs(p,-1);
		int v2=bs(p,c);
		int v3=bs(q,c);
		int v4=bs(q,-1);
		e[i  ].s=v1;e[i  ].g=v2;e[i  ].c=1;
		e[i+1].s=v2;e[i+1].g=v1;e[i+1].c=0;
		e[i+2].s=v2;e[i+2].g=v3;e[i+2].c=0;
		e[i+3].s=v3;e[i+3].g=v2;e[i+3].c=0;
		e[i+4].s=v3;e[i+4].g=v4;e[i+4].c=0;
		e[i+5].s=v4;e[i+5].g=v3;e[i+5].c=1;
	}
	
	daikusutora2(vcnt,0,e,ecnt);
	ll ans=daikusutorappp[bs(n,-1)];
	printf("%lld\n",ans==INF?-1:ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:125:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:128:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&p,&q,&c);
   ^