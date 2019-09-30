#include<stdio.h>

int main(void) {
	int n,sum;
	scanf("%d",&n);
	while(n) {
		sum += n%10;
		n /= 10;
	}
	printf("%d\n",sum);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^