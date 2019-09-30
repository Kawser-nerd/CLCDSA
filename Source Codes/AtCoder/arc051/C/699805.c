#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007LL

int comp(const void *a,const void *b)
{
	int c = *(long long *) a - *(long long *) b;
	
	return (c > 0) - (c < 0);
}

long long pow_mod(long long a,long long pow,long long times)
{
	while(times > 0){
		if(times & 1){
			a = (a * pow) % MOD;
		}
		pow = (pow * pow) % MOD;
		times >>= 1;
	}
	
	return a;
}

int main(void)
{
	long long n,a,b,c;
	long long array [50];
	int i;
	
	scanf("%lld %lld %lld",&n,&a,&b);
	for(i = 0;i < n;i++){
		scanf(" %lld",&array [i]);
	}
	qsort(array,n,sizeof(*array),comp);
	
	if(a == 1){
		for(i = 0;i < n;i++){
			printf("%lld\n",array [i]);
		}
		return 0;
	}
	while(b > 0){
		if(array [0] * a >= array [n - 1]){
			break;
		}
		array [0] *= a;
		b--;
		qsort(array,n,sizeof(*array),comp);
	}
	c = b % n;
	b /= n;
	
	for(i = 0;i < n;i++){
		if(i < c){
			array [i] = pow_mod(array [i],a,b + 1);
		}
		else{
			array [i] = pow_mod(array [i],a,b);
		}
	}
	
	for(i = 0;i < n;i++){
		printf("%lld\n",array [(i + c) % n]);
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:31:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld %lld",&n,&a,&b);
  ^
./Main.c:33:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf(" %lld",&array [i]);
   ^