#include <stdio.h>

long long m;

long long gcd(long long a,long long b)
{
	a = a % b;
	if(!a){
		return b;
	}
	else if(a == 1){
		return 1;
	}

	return gcd(b,a);
}

long long power(long long x,long long n)
{
	long long ret;

	for(ret = 1;n >= 1;n >>= 1,x = (x * x) % m){
		if(n & 1){
			ret = (ret * x) % m;
		}
	}

	return ret;
}

long long one_mod(long long a,long long d)
{
	if(a == 1){
		return 1;
	}
	else if(!(a % 2)){
		return ((1 + power(10,d * a / 2)) * one_mod(a / 2,d)) % m;
	}
	else{
		return (1 + power(10,d) * one_mod(a - 1,d)) % m;
	}
}

int main(void)
{
	long long a,b;
	long long div;

	scanf("%lld %lld %lld",&a,&b,&m);

	div = gcd(a,b);

	printf("%lld\n",(one_mod(a,1) * one_mod(b / div,div)) % m);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:49:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld %lld",&a,&b,&m);
  ^