#include <stdio.h>

#define STR_MAX	100

int main(void)
{
	char w[STR_MAX + 1] = {'\0'};
	int num['z' - 'a' + 1] = {0};
	char *wp = w;
	int cnt;

	scanf("%s", wp);

	while (*wp != '\0') {
		num[*wp - 'a']++;
		wp++;
	}

	for (cnt = 0; cnt < ('z' - 'a' + 1); cnt++) {
		if ((num[cnt] % 2) != 0) {
			printf("No\n");
			return 0;
		}
	}

	printf("Yes\n");

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", wp);
  ^