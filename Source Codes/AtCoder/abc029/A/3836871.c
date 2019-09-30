#include <stdio.h>

int main()
{
	char W[12];
	scanf("%s", W);
	int i;
	for (i = 0; W[i] != '\0'; i++) {
		;
	}
	W[i] = 's';
	W[i+1] = '\0';
	printf("%s\n", W);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", W);
  ^