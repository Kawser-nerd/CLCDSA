#include <stdio.h>

int main()
{
	char N[1000];
	scanf("%s", N);

	int i, j, k;
	for (i = 0; N[i] != '\0'; i++) {
		;
	}

	int flag = 0;
	for (j = 0, k = i - 1; j <= i / 2; j++, k--) {
		if (N[j] != N[k]) {
			flag = 1;
			break;
		}
	}

	if (flag == 0) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", N);
  ^