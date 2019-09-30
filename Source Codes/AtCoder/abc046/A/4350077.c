#include <stdio.h>
int main()
{
	int a,b,c,ans=1;
	scanf("%d%d%d", &a, &b, &c);
	if(a!=b)ans++;
	if(c!=a && c!=b)ans++;
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &a, &b, &c);
  ^