#include <stdio.h>
#include <string.h>

int main(void) {
	char X, s[51];
	scanf("%c%s", &X, s);
	for (int i = 0; i < strlen(s); ++i) {
		if (X != s[i]) printf("%c", s[i]);
	}
	puts("");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%c%s", &X, s);
  ^