#include <stdio.h>

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	int x;
	if ((M+1)>N) {
		printf("%d", M-1);
	} else {
		printf("%d", M+1);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &M);
  ^