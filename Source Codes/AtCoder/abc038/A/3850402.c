#include <stdio.h>

int main()
{
	char S[51];
	scanf("%s", S);
	int i;
	for (i = 0; S[i] != '\0'; i++) {
		;
	}
	if (S[i-1] == 'T') {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^