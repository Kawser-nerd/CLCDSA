#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int get_T(void)
{
	char buf[80];

	fgets(buf, 80, stdin);

	return atoi(buf);
}

static int M, N;
static int b[512][512];
static int nr_c;

static void set(int m, int n, int b0, int b1, int b2, int b3)
{
	b[m][n] = b0;
	b[m][n + 1] = b1;
	b[m][n + 2] = b2;
	b[m][n + 3] = b3;
}

static void parse(char *p, int m)
{
	int n;

	for (n = 0; n < N; n += 4) {
		switch(*p) {
		case '0': set(m, n, 0, 0, 0, 0); break;
		case '1': set(m, n, 0, 0, 0, 1); break;
		case '2': set(m, n, 0, 0, 1, 0); break;
		case '3': set(m, n, 0, 0, 1, 1); break;
		case '4': set(m, n, 0, 1, 0, 0); break;
		case '5': set(m, n, 0, 1, 0, 1); break;
		case '6': set(m, n, 0, 1, 1, 0); break;
		case '7': set(m, n, 0, 1, 1, 1); break;
		case '8': set(m, n, 1, 0, 0, 0); break;
		case '9': set(m, n, 1, 0, 0, 1); break;
		case 'A': set(m, n, 1, 0, 1, 0); break;
		case 'B': set(m, n, 1, 0, 1, 1); break;
		case 'C': set(m, n, 1, 1, 0, 0); break;
		case 'D': set(m, n, 1, 1, 0, 1); break;
		case 'E': set(m, n, 1, 1, 1, 0); break;
		case 'F': set(m, n, 1, 1, 1, 1); break;
		}
		++p;
	}
}

static int nr_size[512];

void put(void)
{
	int n, m;

	fprintf(stderr, "-----\n");
	for (m = 0; m < M; m++) {
		for (n = 0; n < N; n++) {
			fprintf(stderr, "%c",
				(b[m][n] == -1) ? ' ' : b[m][n] + '0');
		}
		fprintf(stderr, "\n");
	}
	fprintf(stderr, "-----\n");
}

static inline int try(int m, int n, int size)
{
	int y, x;
	int yy, xx;
	int c, c0;

	size++;
	yy = m + size;
	xx = n + size;

	c0 = b[m][n];
	for (y = m; y < yy; y++) {
		c = c0;
		for (x = n; x < xx; x++) {
			if (b[y][x] != c)
				return 0;
			c = 1 - c;
		}
		c0 = 1 - c0;
	}
	return 1;
}

static inline int clear(int m, int n, int size)
{
	int y, x;
	int yy, xx;

	size++;
	yy = m + size;
	xx = n + size;
	for (y = m; y < yy; y++) {
		for (x = n; x < xx; x++)
			b[y][x] = -1;
	}
	nr_c += size * size;
}

static inline int cut(int size)
{
	int n, m;
	int nn, mm;
	int y;

	//fprintf(stderr, "cut size=%d\n", size + 1);
	//put();

	y = 0;

	if (size == 0)
		return (M * N) - nr_c;

	mm = M - size;
	nn = N - size;
	for (m = 0; m < mm; m++) {
		for (n = 0; n < nn; n++) {
			if (b[m][n] >= 0) {
				if (try(m, n, size)) {
					clear(m, n, size);
					++y;
				}
			}
		}
	}

	return y;
}

static void solve(int x)
{
	char buf[512];
	int y;
	int m, n;
	int large;

	fgets(buf, 512, stdin);
	sscanf(buf, "%d %d", &M, &N);

	for (m = 0; m < M; m++) {
		fgets(buf, 512, stdin);
		parse(buf, m);
	}

	large = N;
	if (M > N)
		large = M;

	nr_c = 0;
	y = 0;
	for (m = large - 1; m >= 0; m--) {
		n = cut(m);
		nr_size[m] = n;
		if (n > 0)
			++y;
	}

	printf("Case #%d: %d\n", x, y);
	for (m = large - 1; m >= 0; m--) {
		n = nr_size[m];
		if (n > 0)
			printf("%d %d\n", m + 1, n);
	}
}

int main(int argc, char **argv)
{
	int i, T;

	T = get_T();
	for (i = 1; i <= T; i++)
		solve(i);

	return 0;
}
