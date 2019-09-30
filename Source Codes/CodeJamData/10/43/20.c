#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSZ	(1024 * 1024)

static char buf[BUFSZ];

static void getl(void)
{
	fgets(buf, BUFSZ, stdin);
}

#define MAXSZ	500

static int **cell0;
static int **cell1;

static int **cell, **next;

static int tick(void)
{
	int **temp;
	int x, y;
	int b;

	temp = cell;

	b = 0;
	for (x = 0; x < MAXSZ; x++) {
		for (y = 0; y < MAXSZ; y++) {
			int n = cell[y][x];

			if (n) {
				n = 0;
				if (x > 0 && cell[y][x - 1])
					n = 1;
				if (y > 0 && cell[y - 1][x])
					n = 1;
			} else {
				if ((x > 0 && cell[y][x - 1]) &&
						(y > 0 && cell[y - 1][x]))
					n = 1;
			}
			next[y][x] = n;
			b |= n;
		}
	}

	cell = next;
	next = temp;

	return b;
}

static void solve(int c)
{
	int R;
	int r;
	int x1, y1, x2, y2;
	int x, y;
	int t;

	for (y = 0; y < MAXSZ; y++) {
		for (x = 0; x < MAXSZ; x++)
			cell0[y][x] = 0;
	}

	getl();
	R = atoi(buf);
	for (r = 0; r < R; r++) {
		getl();
		sscanf(buf, "%d %d %d %d",
			&x1, &y1, &x2, &y2);

		for (x = x1; x <= x2; x++) {
			for (y = y1; y <= y2; y++)
				cell0[y][x] = 1;
		}
	}

	cell = cell0;
	next = cell1;
	for (t = 1; tick(); t++)
		;

	printf("Case #%d: %d\n", c, t);
}

static int get_cases(void)
{
	getl();

	return atoi(buf);
}

int main(int argc, char **argv)
{
	int i, cases;

	cell0 = malloc(sizeof(int *) * MAXSZ);
	for (i = 0; i < MAXSZ; i++)
		cell0[i] = malloc(sizeof(int) * MAXSZ);

	cell1 = malloc(sizeof(int *) * MAXSZ);
	for (i = 0; i < MAXSZ; i++)
		cell1[i] = malloc(sizeof(int) * MAXSZ);

	cases = get_cases();
	for (i = 1; i <= cases; i++)
		solve(i);

	return 0;
}
