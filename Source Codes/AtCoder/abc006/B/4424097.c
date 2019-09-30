#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int b[1000000];
	b[0] = 0;
	b[1] = 0;
	b[2] = 1;
	int i;
	for(i=3;i<=n-1;i++)
	{
		b[i] = (b[i-1] + b[i-2] + b[i-3]) % 10007;
	}
	printf("%d\n",b[n-1]);
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^