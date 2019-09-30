#include <stdio.h>
#include <string.h>

static inline
int min(int a, int b)
{
	return a < b ? a : b;
}

static inline
int max(int a, int b)
{
	return a > b ? a : b;
}

void print_field(char field[64][64], int R, int C, int rotate)
{
	int i, j;
	field[0][0] = 'c';
	if (rotate) {
		for (i = 0; i < C; i++) {
			for (j = 0; j < R; j++)
				printf("%c", field[j][i]);
			printf("\n");
		}
	} else {
		for (i = 0; i < R; i++) {
			for (j = 0; j < C; j++)
				printf("%c", field[i][j]);
			printf("\n");
		}
	}
}

void fill_field(char field[64][64], int r, int c, int ar, int ac)
{
	int r1, c1;
	memset(field, '*', 64 * 64 * sizeof(char));
	for (r1 = 0; r1 < r; r1++)
		for (c1 = 0; c1 < c; c1++)
			field[r1][c1] = '.';
	for (c1 = 0; c1 < ar; c1++)
		field[r][c1] = '.';
	for (r1 = 0; r1 < ac; r1++)
		field[r1][c] = '.';
}

void fill_field1(char field[64][64], int r, int c, int left)
{
	int ar = c;
	if (left - ar == 1)
		ar--;
	fill_field(field, r, c, ar, left - ar);
}

int main(int argc, const char* argv[])
{
	int T, t;
	char field[64][64];

	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		int R, C, M;
		int i, j, r, d;
		int rotate;
		char found;

		scanf("%d %d %d", &R, &C, &M);
		printf("Case #%d:\n", t);
		d = C * R - M;
		if (d == 1) {
			memset(field, '*', sizeof(field));
			print_field(field, R, C, 0);
			continue;
		}
		if (C < R) {
			C ^= R; R ^= C; C ^= R;
			rotate = 1;
		} else {
			rotate = 0;
		}

		if (R == 1) {
			for (i = 1; i < C; i++)
				field[0][i] = i < d ? '.' : '*';
			print_field(field, R, C, rotate);
			continue;
		} else if (R == 2) {
			for (i = 1; i < C * R; i++)
				field[i % 2][i / 2] = i < d ? '.' : '*';
			if (d != 2 && d % 2 == 0)
				print_field(field, R, C, rotate);
			else
				printf("Impossible\n");
			continue;
		} else if (d < 4 || d == 5 || d == 7) {
			printf("Impossible\n");
			continue;
		}

		found = 0;
		for (r = 2; r <= R && !found; r++) {
			int c = d / r;			
			if (c > C)
				c = C;
			for (; c >= 2; c--) {
				int left = d - c * r;

				if (left == 1)
					continue;
				if (left >= r + c + 1)
					break;
				if (left == 0)
					fill_field(field, r, c, 0, 0);
				else if (left <= c && r < R)
					fill_field(field, r, c, left, 0);
				else if (left <= r && c < C)
					fill_field(field, r, c, 0, left);
				else if (r < R && c < C)
					fill_field1(field, r, c, left);
				else
					continue;
				print_field(field, R, C, rotate);
				found = 1;
				break;
			}
		}

		if (!found) {
			printf("Impossible\n");
			fprintf(stderr, "Oops\n");
		}
	}
    return 0;
}
