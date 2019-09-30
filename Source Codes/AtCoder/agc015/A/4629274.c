#include<stdio.h>

int main() {
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	if (a > b || n == 1 && a != b) {
		printf("0");
	}
	else if (n == 1 && a == b)
		printf("1");
	else {
		printf("%lld",(long long) (b - a)*(n - 2) + 1);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &n, &a, &b);
  ^