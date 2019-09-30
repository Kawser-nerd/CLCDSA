#include <stdio.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)

#define bool int
#define T 1
#define LIMIT 1000000
bool prime[LIMIT+10];
void makep(ll n){prime[0]=prime[1]=T;for(int i=2;i*i<=n;i++)if(!prime[i])for(int j=i*i;j<=n;j+=i)prime[j]=T;}

int main(){
	makep(55555);
	ll n;
	scanf("%lld",&n);
	
	ll p=1;
	rep(i,0,n){
		while(prime[p])p+=10;
		printf("%lld\n",p);
		p+=10;
	}
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^