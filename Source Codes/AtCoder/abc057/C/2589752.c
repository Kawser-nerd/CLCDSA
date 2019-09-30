#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))


ll f(ll k){
	int ans=0;
	while(k){
		ans++;
		k/=10;
	}
	return ans;
}

ll n;
int main(){
	scanf("%lld",&n);
	ll k=sqrt(n);
	while(1){
		if(n%k==0){
			printf("%lld\n",f(n/k));
			return 0;
		}
		k--;
	}
} ./Main.c: In function ‘main’:
./Main.c:23:7: warning: implicit declaration of function ‘sqrt’ [-Wimplicit-function-declaration]
  ll k=sqrt(n);
       ^
./Main.c:23:7: warning: incompatible implicit declaration of built-in function ‘sqrt’
./Main.c:23:7: note: include ‘<math.h>’ or provide a declaration of ‘sqrt’
./Main.c:22:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^