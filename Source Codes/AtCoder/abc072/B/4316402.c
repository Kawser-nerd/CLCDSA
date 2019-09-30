#include <stdio.h>

int main()
{
	char s[100001];
	scanf("%s", s);
	int i;
	for (i = 0; s[i] != '\0'; i++) {
		if (i % 2 == 0) {
			putchar(s[i]);
		}
	}
	putchar('\n');
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", s);
  ^