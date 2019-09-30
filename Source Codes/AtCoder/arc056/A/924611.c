#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define lli long long int
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define true 1
#define false 0



int main(void){
	lli a,b,l,k;
	scanf("%lld%lld%lld%lld",&a,&b,&k,&l);
	lli ll;
	lli aa;
	ll = k / l;
	aa = k % l;
	printf("%lld\n", ll*b + min(aa*a,b));

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld%lld",&a,&b,&k,&l);
  ^