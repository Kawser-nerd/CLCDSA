#include<stdio.h>

int main() {
	long long int a, b, c, d, n, m, num[2000][2] = {}, result = 0;
	char str[200005];
	scanf("%lld", &n);
	if (n >= 64) { printf("64"); }
	else if (n >= 32) { printf("32"); }
	else if (n >= 16) { printf("16"); }
	else if (n >= 8) { printf("8"); }
	else if (n >= 4) { printf("4"); }
	else if (n >= 2) { printf("2"); }
	else if (n >= 1) { printf("1"); }
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &n);
  ^