#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define type long long int

int read(char dlm, FILE *input) {
	char a, buffer[5];
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

type read2(char dlm, FILE *input) {
	char a, buffer[13];
	type ret = 0, k = 1;
	int j, i = 0;
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
	FILE *in = fopen("C-large.in", "rt");
	int N = read('\n', in);
	type x, l, n;
	char mat[8][4] = { { -4, -3, 2, 1 }, { -3, 4, 1, -2 }, { -2, 1, -4, 3 }, { -1, -2, -3, -4 }, { 1, 2, 3, 4 }, { 2, -1, 4, -3 }, { 3, -4, -1, 2 }, { 4, 3, -2, -1 } };
	char a, b, c, h;
	char *s;
	int res, i;
	char **m = (char **)malloc(9 * sizeof(char *));
	type j, k, temp;
	m = &m[4];
	for (i = -4; i < 5; i++) {
		if (i < 0) m[i] = mat[i + 4];
		else if (i > 0) m[i] = mat[i + 3];
	}
	for (i = 0; i < N; i++) {
		l = (type)read(' ', in);
		x = read2('\n', in);
		n = l * x;
		res = 0;
		a = 1;
		s = (char *)malloc(l * sizeof(char));
		for (j = 0; j < l; j++) {
			s[j] = fgetc(in) - 104;
		}
		fgetc(in);
		for (j = 0; j < n; j++) {
			a = m[a][s[j % l]];
			if (a == 2) {
				temp = j + 1;
				b = 1;
				for (k = j + 1; k < n; k++) {
					b = m[b][s[k % l]];
					if (b == 3) {
						c = 1;
						res = 1;
						temp = k + 1;
						break;
					}
					else if ((k - temp) % l == 0 && k != temp) {
						if (b == s[temp % l] + 1) {
							break;
						}
					}
				}
				break;
			}
			else if (j % l == 0 && j != 0) {
				if (a == s[0] + 1) {
					break;
				}
			}
		}
		if (res == 1) {
			res = 0;
			for (j = temp; j < n; j++) {
				c = m[c][s[j % l]];
				if (j % l == l - 1) {
					temp = j + 1;
					break;
				}
			}
			h = 1;
			for (j = temp; j < temp + l; j++) {
				h = m[h][s[j % l]];
			}
			temp = x - (temp / l);
			temp %= 4;
			if (h < 0) {
				h = -h;
				for (j = 0; j < temp; j++) {
					c = -m[c][h - 1];
				}
			}
			else {
				for (j = 0; j < temp; j++) {
					c = m[c][h - 1];
				}
			}
			if (c == 4) res = 1;
		}
		if (res == 1) fprintf(out, "Case #%d: YES", i + 1);
		else fprintf(out, "Case #%d: NO", i + 1);
		if (i < N - 1) fprintf(out, "\n");
		free(s);
	}
	free(&m[-4]);
	fclose(in);
	fclose(out);
	return 0;
}