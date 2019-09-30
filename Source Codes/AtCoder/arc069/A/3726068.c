#include<stdio.h>

int main(void)
{
	unsigned long long n, m, s;
	
	scanf("%llu%llu", &n, &m);
	if (m <= 2 * n)
	    s = m / 2;
	else
	    s = n + (m - 2 * n) / 4;
	printf("%llu\n", s);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%llu%llu", &n, &m);
  ^