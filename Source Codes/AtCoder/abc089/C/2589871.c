#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}

//next_combination
void nexc(ll*a,int n,int r){
	int t=r,s=r;
	ll temp;
	while(--t>=0)if(a[t]<a[n-1])break;
	if(t<0){sortup(a,n);return;}
	while(a[s]<a[t])s++;
	temp=a[t];a[t]=a[s];a[s]=temp;
	rep(k,1,min(n-s,r-t)){temp=a[r-k];a[r-k]=a[s+k];a[s+k]=temp;}
	sortup(a,r);sortup(a+r,n-r);
}


ll a[128];
ll c[5]={'M','A','R','C','H'};
ll n;

int main(){
	scanf("%lld\n",&n);
	rep(i,0,n){
		char s[99];
		scanf("%s",s);
		a[*s]++;
	}
	ll ans=0;
	rep(i,0,10){
		ans+=a[c[0]]*a[c[1]]*a[c[2]];
		nexc(c,5,3);
	}
	printf("%lld\n",ans);
} ./Main.c: In function ‘sortup’:
./Main.c:11:25: warning: implicit declaration of function ‘qsort’ [-Wimplicit-function-declaration]
 void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}
                         ^
./Main.c: In function ‘main’:
./Main.c:31:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld\n",&n);
  ^
./Main.c:34:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^