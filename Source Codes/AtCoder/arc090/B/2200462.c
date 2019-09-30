#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)

typedef struct edge{ll s,g,c;}E;
 
ll n,m;
E e[400010];
ll vnow[100010];
ll epre[400010];
 
ll d[100010];
ll que[200010];
void bfs(int k){
	ll qcnt=1;
	que[0]=k;
	rep(i,0,qcnt){
		ll v=que[i];
		for(ll t=vnow[v];t!=-1;t=epre[t]){
			if(!d[e[t].g]){
				que[qcnt++]=e[t].g;
				d[e[t].g]=d[v]+e[t].c;
			}else if(d[e[t].g]!=d[v]+e[t].c){
				puts("No");
				exit(0);
			}
		}
	}
}

int main(){
	scanf("%lld%lld",&n,&m);
	rep(i,0,n)vnow[i]=-1;
	
	rep(i,0,m){
		ll a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		a--;b--;
		e[2*i].s=a;
		e[2*i].g=b;
		e[2*i].c=c;
		epre[2*i]=vnow[a];
		vnow[a]=2*i;
		
		e[2*i+1].s=b;
		e[2*i+1].g=a;
		e[2*i+1].c=-c;
		epre[2*i+1]=vnow[b];
		vnow[b]=2*i+1;
	}
	ll cnt=0;
	rep(i,0,n)if(!d[i]){
		d[i]=++cnt<<32;
		bfs(i);
	}
	puts("Yes");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:33:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&m);
  ^
./Main.c:38:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld",&a,&b,&c);
   ^