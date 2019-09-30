#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define bit(n,m)(((n)>>(m))&1)
int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
int downll(const void*a, const void*b){return*(ll*)a<*(ll*)b?1:*(ll*)a>*(ll*)b?-1:0;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}
void sortdown(ll*a,int n){qsort(a,n,sizeof(ll),downll);}
ll pom(ll a,ll n,int m){ll x=1;for(a%=m;n;n/=2)n&1?x=x*a%m:0,a=a*a%m;return x;}
//#define MOD 998244353
#define MOD 1000000007
#define invp(a,p)pom(a,p-2,p)



//?????????????
typedef struct edge{ll s,g;}E;
typedef struct graph{
	ll vcnt,ecnt;
	E  e[200010];//?????
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
	ll n;
	scanf("%lld",&n);
	rep(i,0,n-1){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		x--,y--;
		g.e[2*i].s=x;
		g.e[2*i].g=y;
		g.e[2*i+1].s=y;
		g.e[2*i+1].g=x;
	}
	g.vcnt=n;
	g.ecnt=2*n-2;
	qsort(g.e,g.ecnt,sizeof(E),esort);

	int p=0;
	rep(i,0,g.vcnt){
		while(p<g.ecnt&&g.e[p].s<i)p++;
		g.id[i]=p;
	}
	g.id[g.vcnt]=g.ecnt;//????
}

ll ue[100010],sita[100010];
int flag[100010];
int q[100010],qcnt;
int vq[100010];
void toposo(ll r){
	//???
	flag[r]=2-ue[r]%2;
	q[qcnt]=r;
	vq[r]=qcnt;
	qcnt++;
	rep(i,0,g.vcnt){
		ll v=q[i];
		rep(j,g.id[v],g.id[v+1])if(!flag[g.e[j].g]){
			ll vv=g.e[j].g;
			flag[vv]=3-flag[v];
			q[qcnt]=vv;
			vq[vv]=qcnt;
			qcnt++;
			if(ue[vv]==sita[vv]&&ue[vv]%2!=flag[vv]%2){
				//?????????????
				puts("No");
				exit(0);
			}
		}
	}
}

int main(){
	readgraph();
	rep(i,0,g.vcnt){
		sita[i]=-INF;
		ue[i]=INF;
	}
	
	ll k;
	scanf("%lld",&k);
	ll r;
	rep(i,0,k){
		ll a,b;
		scanf("%lld%lld",&a,&b);
		a--;
		sita[a]=ue[a]=b;
		r=a;
	}
	toposo(r);

	//???????
	for(ll i=g.vcnt-1;i>=0;i--){
		ll v=q[i];
		rep(j,g.id[v],g.id[v+1]){
			ll vv=g.e[j].g;
			if(vq[v]>vq[vv]){
				ue[vv]=min(ue[vv],ue[v]+1);
				sita[vv]=max(sita[vv],sita[v]-1);
			}
		}
	}

	//???????
	rep(i,0,g.vcnt){
		ll v=q[i];
		rep(j,g.id[v],g.id[v+1]){
			ll vv=g.e[j].g;
			if(vq[v]<vq[vv]){
				ue[vv]=min(ue[vv],ue[v]+1);
				sita[vv]=max(sita[vv],sita[v]-1);
			}
		}
	}
	
	//????????????
	rep(i,0,g.vcnt)if(ue[i]<sita[i]){
		puts("No");
		return 0;
	}
	
	puts("Yes");
	rep(i,0,g.vcnt)printf("%lld\n",sita[i]);
} ./Main.c: In function ‘readgraph’:
./Main.c:42:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:45:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&x,&y);
   ^
./Main.c: In function ‘main’:
./Main.c:99:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&k);
  ^
./Main.c:103:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&a,&b);
   ^