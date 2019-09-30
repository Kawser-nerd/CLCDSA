#include<stdio.h>

int main() {
	char S[102];
	long long K, i;
	char ans = '1';
	scanf("%s", S);
	scanf("%lld", &K);
	for (i = 0; i < K; i++) {
		if (S[i] != '1') {
			ans = S[i];
			break;
		}
	}
	printf("%c\n", ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &K);
  ^