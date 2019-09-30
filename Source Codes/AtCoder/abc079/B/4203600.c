#include <stdio.h>
#define LL long long
int main(void){
	LL N[100];
	N[0] = 2;
	N[1] = 1;
	for (int i = 2; i < 87; i++) {
		N[i] = N[i-1] + N[i-2];
	}
	int i;
	scanf("%d", &i);
	printf("%lld\n", N[i]);

} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &i);
  ^