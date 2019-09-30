#include <stdio.h>

int main(void)
{
	int sx, sy, tx, ty;
	int cnt;

	scanf("%d %d %d %d", &sx, &sy, &tx, &ty);

	for (cnt = 0; cnt < (tx - sx); cnt++) {
		putchar('R');
	}
	for (cnt = 0; cnt < (ty - sy); cnt++) {
		putchar('U');
	}

	for (cnt = 0; cnt < (tx - sx); cnt++) {
		putchar('L');
	}
	for (cnt = 0; cnt < (ty - sy); cnt++) {
		putchar('D');
	}

	putchar('D');
	for (cnt = 0; cnt < (tx - sx + 1); cnt++) {
		putchar('R');
	}
	for (cnt = 0; cnt < (ty - sy + 1); cnt++) {
		putchar('U');
	}
	putchar('L');

	putchar('U');
	for (cnt = 0; cnt < (tx - sx + 1); cnt++) {
		putchar('L');
	}
	for (cnt = 0; cnt < (ty - sy + 1); cnt++) {
		putchar('D');
	}
	putchar('R');

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d", &sx, &sy, &tx, &ty);
  ^