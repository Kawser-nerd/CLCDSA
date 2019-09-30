#include <stdio.h>

int main(int argc, char const *argv[])
{
	long n;
	scanf("%ld",&n);
	if(n % 2)	printf("%ld\n", 2 * n);
	else printf("%ld\n", n);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld",&n);
  ^