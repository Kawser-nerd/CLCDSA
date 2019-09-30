#include <stdio.h>

int main(void)
{
	unsigned int ck_a, ck_b, ck_c;
	unsigned int ck_d;				/* ?????????????		*/

	scanf("%d %d %d", &ck_a, &ck_b, &ck_c);

	if ((ck_a + ck_b + 1) >= ck_c) {
		ck_d = ck_b + ck_c;
	} else {
		ck_d = ck_b + ck_a + ck_b + 1;
	}

	printf("%d\n", ck_d);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d", &ck_a, &ck_b, &ck_c);
  ^