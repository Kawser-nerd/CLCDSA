#include<stdio.h>

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	int c = a + b, d = a - b, e = a * b;
	if(c > d && c > e) printf("%d\n", c);
	else if(d > e) printf("%d\n", d);
	else printf("%d\n", e);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &a, &b);
  ^