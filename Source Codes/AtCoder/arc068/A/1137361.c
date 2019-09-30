#include<stdio.h>
int main(void) {
	//????????????????????????
	long long int N,ans;
	scanf("%lld", &N);
	ans = (N / 11)*2;
	N %= 11;
	if (N > 0) { ans++; }
	if (N > 6) { ans++; }
	printf("%lld", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^