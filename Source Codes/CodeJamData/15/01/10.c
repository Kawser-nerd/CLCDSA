#include <stdio.h>

int read(char dlm, FILE *input) {
	char a, buffer[4];
	int j, ret = 0, i = 0, k = 1;
	while ((a = fgetc(input)) != dlm) {
		buffer[i] = a;
		i++;
	}
	for (j = i - 1; j > -1; j--) {
		ret += (buffer[j] - 48) * k;
		k *= 10;
	}
	return ret;
}

int main(void) {
	FILE *out = fopen("ouput.out", "wt");
	FILE *in = fopen("A-large.in", "rt");
	int N = read('\n', in);
	int k, j, t, f, sMax = 0, n = 0;
	for (j = 0; j < N; j++) {
		sMax = read(' ', in) + 1;
		n = fgetc(in) - 48;
		f = 0;
		for (k = 1; k < sMax; k++) {
			t = fgetc(in) - 48;
			if (n < k) {
				f += k - n;
				n = k + t;
			}
			else {
				n += t;
			}
		}
		if (j != N - 1) fprintf(out, "Case #%d: %d\n", j + 1, f);
		else fprintf(out, "Case #%d: %d", j + 1, f);
		fgetc(in);
	}
	fclose(in);
	fclose(out);
	return 0;
}