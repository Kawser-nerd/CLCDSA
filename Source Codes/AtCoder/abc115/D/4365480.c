#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LLD long long

LLD n,x;
LLD *a,*p;

LLD burger(LLD n,LLD x){
	if(!n)	return (x <= 0 ? 0 : 1);
	else if(x <= 1 + a[n - 1])	return burger(n - 1,x - 1);
	else return p[n - 1] + 1 + burger(n - 1,x - 2 - a[n - 1]);
}

int main(int argc, char const *argv[])
{	
	scanf("%lld%lld",&n,&x);
	a = (LLD *)malloc(sizeof(LLD) * n);
	p = (LLD *)malloc(sizeof(LLD) * n);
	a[0] = 1;	p[0] = 1;

	for (LLD i = 1; i < n; ++i){
		a[i] = a[i - 1] * 2 + 3;
		p[i] = p[i - 1] * 2 + 1;
	}
	printf("%lld\n", burger(n,x));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&x);
  ^