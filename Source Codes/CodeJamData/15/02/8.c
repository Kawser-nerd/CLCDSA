#include <stdio.h>
#include <stdlib.h>

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
	FILE *in = fopen("B-large.in", "rt");
	int N = read('\n', in);
	int m, j, k, D, t, time, max;
	int *d;
	for (j = 0; j < N; j++) {
		D = read('\n', in);
		d = (int *)malloc(D * sizeof(int));
		time = 1000000000;
		max = 0;
		for (k = 0; k < D; k++) {
			if (k == D - 1) d[k] = read('\n', in);
			else d[k] = read(' ', in);
			if (d[k] > max) max = d[k];
		}
		max++;
		for (k = 1; k < max; k++) {
			t = 0;
			for (m = 0; m < D; m++) {
				t += (d[m] % k) ? (d[m] / k) : (d[m] / k - 1);
			}
			if (t + k < time) time = t + k;
		}
		if (j != N - 1) fprintf(out, "Case #%d: %d\n", j + 1, time);
		else fprintf(out, "Case #%d: %d", j + 1, time);
		free(d);
	}
	fclose(in);
	fclose(out);
	return 0;
}