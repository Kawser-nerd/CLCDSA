#include <stdio.h>
int main()
{
	int n,k;
	unsigned long long ans=1;
	scanf("%d%d", &n, &k);
	n--;
	ans*=k;
	k--;
	while(n>0){
		ans*=k;
		n--;
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &n, &k);
  ^