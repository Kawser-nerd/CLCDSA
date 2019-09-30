#include <stdio.h>

int main()
{
	char s[51], X;
	scanf("%c", &X);
	scanf("%s", s);
	int i;
	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] == X) {
			continue;
		} else {
			printf("%c", s[i]);
		}
	}
	printf("\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%c", &X);
  ^
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", s);
  ^