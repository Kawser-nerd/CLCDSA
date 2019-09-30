#include <stdio.h>

int main(void)
{
	char s[200000 + 1] = {'\0'};
	long cnt_turn = 0;
	long num_b = 0;
	char *sp = &s[0];

	scanf("%s", sp);

	while (*sp != '\0') {
		if (*sp == 'B') {
			num_b++;
		}
		if (*sp == 'W') {
			cnt_turn += num_b;
		}
		sp++;
	}

	printf("%ld\n", cnt_turn);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", sp);
  ^