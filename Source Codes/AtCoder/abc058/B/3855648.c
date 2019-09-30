#include <stdio.h>

int main()
{
	char O[51], E[51];
	scanf("%s%s", O, E);
	char ans[101];
	int i, j;
	for (i = 0; O[i] != '\0'; i++) {
		;
	}
	for (j = 0; E[j] != '\0'; j++) {
		;
	}
	int max = i+j;
	for (i = 0, j = 0; max / 2+1 > i; i++) {
		ans[j] = O[i];
		j++;
		ans[j] = E[i];
		j++;
	}
	ans[++j] = '\0';
	printf("%s\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s%s", O, E);
  ^