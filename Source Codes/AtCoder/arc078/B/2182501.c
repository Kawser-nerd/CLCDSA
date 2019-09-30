#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r) for(ll i=(l);i<(r);i++)

typedef struct edge{ll s,g,c;}E;

ll n;
E e[200010];
ll vnow[100010];
ll epre[200010];

ll que[200010];
ll d[100010];
void bfs(int k){
	ll qcnt=1;
	que[0]=k;
	d[k]=1;
	rep(i,0,qcnt){
		ll v=que[i];
		for(ll t=vnow[v];t!=-1;t=epre[t])if(!d[e[t].g]){
			que[qcnt++]=e[t].g;
			d[e[t].g]=d[v]+1;
		}
	}
}

ll fennec[100010];
ll sunuke[100010];
int main(){
	scanf("%lld",&n);
	rep(i,0,n)vnow[i]=-1;
	
	rep(i,0,n-1){
		ll a,b;
		scanf("%lld%lld",&a,&b);
		a--;b--;
		e[2*i].s=a;
		e[2*i].g=b;
		epre[2*i]=vnow[a];
		vnow[a]=2*i;
		
		e[2*i+1].s=b;
		e[2*i+1].g=a;
		epre[2*i+1]=vnow[b];
		vnow[b]=2*i+1;
	}

	bfs(0);
	rep(i,0,n){
		fennec[i]=d[i];
		d[i]=0;
	}
	bfs(n-1);
	rep(i,0,n)sunuke[i]=d[i];

	ll ans=0;
	rep(i,0,n)if(fennec[i]<=sunuke[i])ans++;
	puts(ans>n-ans?"Fennec":"Snuke");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:31:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:36:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&a,&b);
   ^