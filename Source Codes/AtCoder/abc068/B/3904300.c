#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

int main(){
	ll n;
	scanf("%lld",&n);
	n=log2(n);
	printf("%lld",1LL<<n);
} ./Main.c: In function ‘main’:
./Main.c:12:4: warning: implicit declaration of function ‘log2’ [-Wimplicit-function-declaration]
  n=log2(n);
    ^
./Main.c:12:4: warning: incompatible implicit declaration of built-in function ‘log2’
./Main.c:12:4: note: include ‘<math.h>’ or provide a declaration of ‘log2’
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^