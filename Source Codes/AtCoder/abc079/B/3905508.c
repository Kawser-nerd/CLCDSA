#include<stdio.h>
int main() {
	long long int a[1000005] = {};
	a[0] = 2;
  	a[1] = 1;
	int n;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		a[i] = a[i - 1] + a[i - 2];
		
	}
	printf("%lld", a[n]);
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^