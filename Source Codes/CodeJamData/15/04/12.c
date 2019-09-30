#include <stdio.h>
#include <stdlib.h>

int read(char dlm, FILE *input) {
	char a, buffer[3];
	int j, ret = 0, i = 0, k = 1;
	while ((a = fgetc(input)) != dlm) {
		buffer[i] = a;
		i++;
	}
	for (j = i - 1; j > -1; j--, k *= 10) {
		ret += (buffer[j] - '0') * k;
	}
	return ret;
}

int main(void) {
	FILE *out = fopen("ouput.out", "wt");
	FILE *in = fopen("D-small-attempt0.in", "rt");
	int N = read('\n', in);
	int i, x, r, c, res;
	for (i = 0; i < N; i++) {
		x = read(' ', in);
		r = read(' ', in);
		c = read('\n', in);
		res = 0;
		if (x == 1);
		else if ((r * c) % x != 0) res = 1;
		else if (x > r && x > c) res = 1;
		else {
			if (x % 2 == 1) {
				if (x / 2 + 1 > r) res = 1;
				else if (x / 2 + 1 > c) res = 1;
			}
			else {
				if (x / 2 > r) res = 1;
				else if (x / 2 > c) res = 1;
			}
			if (res == 0) {
				if (x > 6) res = 1;
				else if (x == 4 && (r == 2 || c == 2)) res = 1;
				else if (x == 6 && (r == 3 || c == 3)) res = 1;
			}
		}
		if (res == 1) fprintf(out, "Case #%d: RICHARD", i + 1);
		else fprintf(out, "Case #%d: GABRIEL", i + 1);
		if (i < N - 1) fprintf(out, "\n");
	}
	fclose(in);
	fclose(out);
	return 0;
}