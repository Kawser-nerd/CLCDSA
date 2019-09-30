#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int complete(int c) {
	if (c < 3) return 0;
	int r = 1, a = 1 << c, b = complete(c - 1);
	while (c-- > 0) r *= 3;
	return r - 3 * a + 3 + b;
}
 
static int tenpower[10];
 
int calc(int n, int c, char f[], int t) {
	if (c == 1 && (f[0] + f[1] + f[2] < 2)) return 0;
	if (c == 0 && (f[0] + f[1] + f[2] == 3)) return 1;
	if (c == 0) return 0;
	int max = 0, i, r = 0;
	if (t == 0) {
		for (i = 0; i < c; i++) max += 7 * tenpower[i];
		if (n > max) return complete(c);
		r = complete(c - 1);
	}
	char backup;
	if (n >= t + 3 * tenpower[c - 1]) {
		backup = f[0];
		f[0] = 1;
		r += calc(n, c - 1, f, t + 3 * tenpower[c - 1]);
		f[0] = backup;
	}
	if (n >= t + 5 * tenpower[c - 1]) {
		backup = f[1];
		f[1] = 1;
		r += calc(n, c - 1, f, t + 5 * tenpower[c - 1]);
		f[1] = backup;
	}
	if (n >= t + 7 * tenpower[c - 1]) {
		backup = f[2];
		f[2] = 1;
		r += calc(n, c - 1, f, t + 7 * tenpower[c - 1]);
		f[2] = backup;
	}
	return r;
}
 
int main(int argc, char *argv[]) {
	int n;
	scanf("%d", &n);
	int r, c;
	char f[3] = {};
	if (n < 357) {
      printf("0\n");
      return 0;
    }
	for (r = n, c = 0; r > 0; c++) r /= 10;
	tenpower[0] = 1;
	for (r = 1; r < 10; r++) tenpower[r] = 10 * tenpower[r - 1];
	printf("%d\n", calc(n, c, f, 0));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:48:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^