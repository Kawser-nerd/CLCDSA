#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define min(p,q)((p)<(q)?(p):(q))
ll pom(ll a,ll n,int m){ll x=1;for(a%=m;n;n/=2)n&1?x=x*a%m:0,a=a*a%m;return x;}
#define MOD 1000000007
#define invp(a,p)pom(a,p-2,p)


//??,????
ll fact[10010];
ll invfact[10010];
void makefact(int n,ll m){
	fact[0]=1;
	rep(i,0,n)fact[i+1]=fact[i]*(i+1)%m;
	invfact[n]=invp(fact[n],m);
	for(int i=n;i>0;i--)invfact[i-1]=invfact[i]*i%m;
}
ll choose(int n,int r,int m){return n<0||r<0||n-r<0?0:fact[n]*invfact[r]%m*invfact[n-r]%m;}


typedef struct edge{ll s,g,c;}E;
typedef struct graph{
	ll vcnt,ecnt;
	E  e[10010];//?????
	ll id[5010];//?????
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
	g.id[g.vcnt]=g.ecnt;//??
}

//*
int csize[5010];
int ccnt;
int Gc[2];
void Gcenter_dfs(int v,int pre){
	int flag=1;
	csize[v]=1;
	rep(i,g.id[v],g.id[v+1])if(g.e[i].g!=pre){
		int s=g.e[i].g;
		Gcenter_dfs(s,v);
		csize[v]+=csize[s];
		flag&=csize[s]<=g.vcnt/2;
	}
	if(flag&&g.vcnt-csize[v]<=g.vcnt/2)Gc[ccnt++]=v;
}
int Gcenter(int root){
	Gcenter_dfs(root,-1);
	return ccnt;
}
//*/

ll dp[5010][5010];
int main(){
	makefact(10005,MOD);
	readgraph();
	Gcenter(0);
	if(ccnt==2){
		printf("%lld",fact[g.vcnt/2]*fact[g.vcnt/2]%MOD);
		return 0;
	}
	Gcenter(Gc[0]);
	ll K=g.id[Gc[0]+1]-g.id[Gc[0]];
	ll N=g.vcnt;
	dp[0][0]=1;
	dp[0][1]=0;
	rep(k,0,K)rep(x,0,N+1){
		ll Tk=csize[g.e[g.id[Gc[0]]+k].g];
		rep(y,0,min(x,Tk)+1)dp[k+1][x]=(dp[k+1][x]+choose(Tk,y,MOD)*choose(Tk,y,MOD)%MOD*fact[y]%MOD*dp[k][x-y])%MOD;
	}
	ll ans=0;
	rep(x,0,N+1)ans=(ans+(x%2?-1:1)*fact[N-x]*dp[K][x])%MOD;
	printf("%lld",(ans+MOD)%MOD);
} ./Main.c: In function ‘readgraph’:
./Main.c:42:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:45:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&x,&y);
   ^