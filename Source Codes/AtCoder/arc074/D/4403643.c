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


//s??t????? O(E flow)?????O(VV flow)
#define VMAX 210
int vcnt;
int foodoflag[VMAX];
int resflow[VMAX][VMAX];

int foododfs(int s,int t){
	if(s==t)return 1;
	foodoflag[s]=1;
	rep(i,0,vcnt)if(!foodoflag[i]&&resflow[s][i]>0){
		if(foododfs(i,t)){
			resflow[s][i]--;
			resflow[i][s]++;
			return 1;
		}
	}
	return 0;
}
int foodo(int s,int t){
	int ans=0;
	while(foododfs(s,t)){
		ans++;
		rep(i,0,vcnt)foodoflag[i]=0;
	}
	return ans;
}
#undef VMAX

char s[110][110];
int main(){
	int h,w;
	scanf("%d%d",&h,&w);
	rep(i,0,h)scanf(" %s",s[i]);
	//??1?h???h+1?h+w
	rep(i,0,h)rep(j,0,w){
		if(s[i][j]=='o'){
			resflow[i+1][h+j+1]=1;
			resflow[h+j+1][i+1]=1;
		}else if(s[i][j]=='S'){
			resflow[0][i+1]=1000;
			resflow[0][h+j+1]=1000;
		}else if(s[i][j]=='T'){
			resflow[i+1][h+w+1]=1000;
			resflow[h+j+1][h+w+1]=1000;
		}
	}
	vcnt=h+w+2;
	int ans=foodo(0,h+w+1);
	printf("%d",ans>=1000?-1:ans);
} ./Main.c: In function ‘main’:
./Main.c:52:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&h,&w);
  ^
./Main.c:53:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,h)scanf(" %s",s[i]);
            ^