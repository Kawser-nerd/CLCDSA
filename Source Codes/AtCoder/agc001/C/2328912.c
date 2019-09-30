#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r) for(ll i=(l);i<(r);i++)
#define min(p,q)((p)<(q)?(p):(q))

typedef struct edge{ll s,g,c;}E;

ll n,k,ans;
E e[4010];
ll vnow[2010];
ll epre[4010];

ll que[4010];
ll d[2010][2010];
void bfs(int k){
	ll qcnt=1;
	que[0]=k;
	d[k][k]=1;
	rep(i,0,qcnt){
		ll v=que[i];
		for(ll t=vnow[v];t!=-1;t=epre[t])if(!d[k][e[t].g]){
			que[qcnt++]=e[t].g;
			d[k][e[t].g]=d[k][v]+1;
		}
	}
}

int main(){
	scanf("%lld%lld",&n,&k);
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

	rep(i,0,n)bfs(i);
	ans=n;
	
	if(k%2==0){
		//k??????
		//??i??????????k/2??????????????????
		rep(i,0,n){
			ll temp=0;
			rep(j,0,n)if(d[i][j]-1>k/2)temp++;
			ans=min(ans,temp);
		}
	}else{
		//k??????
		//?i??????????k/2.0??????????????????
		//???????????????k/2????????
		rep(i,0,n-1){
			ll temp=0;
			rep(j,0,n)if(min(d[e[2*i].s][j],d[e[2*i].g][j])-1>k/2)temp++;
			ans=min(ans,temp);
		}
	}
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:30:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&k);
  ^
./Main.c:35:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&a,&b);
   ^