#include<stdio.h>
int main() 
{
	long long n, m;
	scanf("%lld%lld", &n, &m);
	if (2 * n <= m)
		printf("%lld\n", (m - n * 2) / 4 + n);
	else
		printf("%lld\n", m / 2);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &n, &m);
  ^