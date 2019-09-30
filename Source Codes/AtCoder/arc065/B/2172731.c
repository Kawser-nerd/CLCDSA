#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r) for(ll i=(l);i<(r);i++)
#define min(p,q)((p)<(q)?(p):(q))

int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}

//union-find
int uniroot[200010];
void ufinit(int n){for(int i=0;i<n;i++){uniroot[i]=i;}}
int root(int x){return uniroot[x]!=x?uniroot[x]=root(uniroot[x]):x;}
int same(int x,int y){return root(x)==root(y);}
void uni(int x,int y){if((x=root(x))==(y=root(y)))return;uniroot[x]=y;}

ll K[200010];
ll L[200010];

ll KL[200010];
ll KL2[200010];
ll cnt[200010];
ll num;


int bserch(int i){
	ll l=0,r=num;
	while(r-l>1){
		int m=(l+r)/2;
		if(KL2[m]>KL[i])r=m;
		else l=m;
	}
	return l;
}

int main(){
	int n,k,l;
	scanf("%d%d%d",&n,&k,&l);
	
	ufinit(n+1);
	rep(i,0,k){
		ll a,b;
		scanf("%lld%lld",&a,&b);
		uni(a,b);
	}
	rep(i,1,n+1)K[i]=root(i);
	
	ufinit(n+1);
	rep(i,0,l){
		ll a,b;
		scanf("%lld%lld",&a,&b);
		uni(a,b);
	}
	rep(i,1,n+1)L[i]=root(i);
	
	rep(i,1,n+1)KL[i]=K[i]<<32|L[i];
	sortup(KL+1,n);
		
	num=1;
	KL2[0]=KL[1];
	cnt[0]=1;
	rep(i,2,n+1){
		if(KL[i]==KL2[num-1])cnt[num-1]++;
		else{
			KL2[num]=KL[i];
			cnt[num]=1;
			num++;
		}
	}

	rep(i,1,n+1)KL[i]=K[i]<<32|L[i];
	
	rep(i,1,n+1)printf("%d%c",cnt[bserch(i)],i==n?'\n':' ');
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:73:21: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
  rep(i,1,n+1)printf("%d%c",cnt[bserch(i)],i==n?'\n':' ');
                     ^
./Main.c:38:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&n,&k,&l);
  ^
./Main.c:43:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&a,&b);
   ^
./Main.c:51:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&a,&b);
   ^