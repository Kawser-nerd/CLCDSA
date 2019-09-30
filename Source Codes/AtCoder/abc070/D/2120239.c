#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))

typedef struct edge{ll s,g,c;}E;
int edgehikaku(const void*a,const void*b){
	E*p=(E*)a,*q=(E*)b;
	if((*p).s<(*q).s)return -1;
	if((*p).s>(*q).s)return  1;
	if((*p).g<(*q).g)return -1;
	return 1;
}

E e[200010];
ll es[200010];
ll d[100010];
int n;

void dfs(int v,ll c){
	if(d[v])return;
	d[v]=c;
	for(int t=es[v];t<2*n-2&&e[t].s==v;t++)dfs(e[t].g,c+e[t].c);
}

int main(){
	scanf("%d",&n);
	rep(i,0,n-1){
		ll a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		a--;
		b--;
		e[i].s=e[i+n-1].g=a;
		e[i].g=e[i+n-1].s=b;
		e[i].c=e[i+n-1].c=c;
	}
	qsort(e,2*n-2,sizeof(E),edgehikaku);
	es[0]=0;
	ll t=0;
	rep(i,1,n){
		while(t<2*n-2&&e[t].s<i)t++;
		es[i]=t;
	}
	
	int q,k;
	scanf("%d%d",&q,&k);
	k--;
	dfs(k,1);
	while(q--){
		int a,b;
		scanf("%d%d",&a,&b);
		a--;
		b--;
		printf("%lld\n",d[a]+d[b]-2);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:28:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:31:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld",&a,&b,&c);
   ^
./Main.c:47:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&q,&k);
  ^
./Main.c:52:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a,&b);
   ^