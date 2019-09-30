#include <stdio.h>

int main()
{
	char N[5];
	scanf("%s", N);
	int i, flag=0;
	for (i = 0; i < 3; i++) {
		if (N[i] != N[i+1]) {
			flag = 1;
			break;
		}
	}
	if (flag == 1) {
		printf("DIFFERENT\n");
	} else {
		printf("SAME\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", N);
  ^