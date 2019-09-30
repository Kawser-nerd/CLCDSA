#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int tenpower[10];

int calc(int n, int c, int t, int lz) {
	int i[3] = {};
	if (c == 0) {
		while (t > 0) {
			if (t % 10 == 3) i[0] = 1;
			if (t % 10 == 5) i[1] = 1;
			if (t % 10 == 7) i[2] = 1;
			t /= 10;
		}
		if (i[0] + i[1] + i[2] == 3) {
			return 1;
		}
		return 0;
        }
	int r = 0;
	if (lz) r = calc(n, c - 1, t, 1);
	if (n >= t + 3 * tenpower[c - 1]) {
		r += calc(n, c - 1, t + 3 * tenpower[c - 1], 0);
	}
	if (n >= t + 5 * tenpower[c - 1]) {
		r += calc(n, c - 1, t + 5 * tenpower[c - 1], 0);
	}
	if (n >= t + 7 * tenpower[c - 1]) {
		r += calc(n, c - 1, t + 7 * tenpower[c - 1], 0);
	}
	return r;
}

int main(int argc, char *argv[]) {
	int n;
	scanf("%d", &n);
	int r, c;
	for (r = n, c = 0; r > 0; c++) r /= 10;
	tenpower[0] = 1;
	for (r = 1; r < 10; r++) tenpower[r] = 10 * tenpower[r - 1];
	printf("%d\n", calc(n, c, 0, 1));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:37:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^