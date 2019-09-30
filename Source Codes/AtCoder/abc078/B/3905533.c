#include <stdio.h>

int main() {
	long long int x, y, z;
	scanf("%lld%lld%lld", &x, &y, &z);
	printf("%lld", (x - z) / (y + z));
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld", &x, &y, &z);
  ^