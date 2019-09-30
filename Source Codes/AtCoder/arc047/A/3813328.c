#include <stdio.h>

int main()
{
	int N, L;
	scanf("%d%d", &N, &L);
	char S[N+1];
	scanf("%s", S);
	int count=1,crash=0;
	int i, j;
	for (i = 0; i < N; i++) {
		if (S[i] == '+') {
			count++;
		} else if (S[i] == '-') {
			count--;
		}
		if (count > L) {
			crash++;
			count = 1;
		}
	}
	printf("%d\n", crash);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &L);
  ^
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^