#include <stdio.h>

long long int n,ans=1;

int main(void)
{
	int i;
	scanf("%lld",&n);
	
	printf("1");
	for(i=0;i<n-1;i++){
		printf("0");
	}
	printf("7\n");
	
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^