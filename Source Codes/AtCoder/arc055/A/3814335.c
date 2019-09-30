#include <stdio.h>
#include <math.h>

int main()
{
	int N;
	scanf("%d", &N);
	char ans[101];
	int i;
	for (i = 0; i <= N; i++) {
		if (i == 0) {
			ans[i] = '1';
		} else {
			ans[i] = '0';
		}
	}
	ans[i] = '\0';
	ans[i-1] = '7';
	printf("%s\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^