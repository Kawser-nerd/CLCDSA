#include <stdio.h>
#include <assert.h>
#include <string.h>

unsigned T, N, x;

char map_[100][100];
char pmap_[100][100];

char ds_[200];
char dd_[200];

char rows_[100];
char cols_[100];

#define map(i, j) map_[j][i]
#define pmap(i, j) pmap_[j][i]
#define ds(i, j) ds_[(i) + (j)]
#define dd(i, j) dd_[(N + (i)) - (j)]
#define rows(i, j) rows_[i]
#define cols(i, j) cols_[j]

void zero()
{
	N = 0;
	memset(map_, '.', sizeof (map_));
	memset(pmap_, '.', sizeof (pmap_));
	memset(ds_, 0, sizeof (ds_));
	memset(dd_, 0, sizeof (dd_));
	memset(rows_, 0, sizeof (rows_));
	memset(cols_, 0, sizeof (cols_));
}

#define hit_p(i, j) (ds(i, j) || dd(i, j))
#define hit_x(i, j) (rows(i, j) || cols(i, j))

#define has_o(i, j) (map(i, j) == 'o')
#define has_p(i, j) (has_o(i, j) || map(i, j) == '+')
#define has_x(i, j) (has_o(i, j) || map(i, j) == 'x')
#define is_empty(i, j) (map(i, j) == '.')

#define could_p(i, j) (has_p(i, j) || !hit_p(i, j))
#define could_x(i, j) (has_x(i, j) || !hit_x(i, j))
#define could_o(i, j) (could_p(i, j) && could_x(i, j))

#define can_p(i, j) (is_empty(i, j) && could_p(i, j))
#define can_x(i, j) (is_empty(i, j) && could_x(i, j))
#define can_o(i, j) (could_o(i, j))

#define mark_p(i, j) { ds(i, j) = 1; dd(i, j) = 1; }
#define mark_x(i, j) { rows(i, j) = 1; cols(i, j) = 1; }

#define put_p(i, j) { mark_p(i, j); map(i, j) = '+'; }
#define put_x(i, j) { mark_x(i, j); map(i, j) = 'x'; }
#define put_o(i, j) { mark_p(i, j); mark_x(i, j); map(i, j) = 'o'; }

#define safe_put_p(i, j) { if (can_p(i, j)) put_p(i, j); }
#define safe_put_x(i, j) { if (can_x(i, j)) put_x(i, j); }
#define safe_put_o(i, j) { if (can_o(i, j)) put_o(i, j); }

#if 0
void print_map()
{
	unsigned i, j;
	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			putchar(map(i, j));
		}
		putchar('\n');
	}
}
#endif

void test_case()
{
	unsigned i, j, y, z, M;

	++x;

	zero();
	y = 0;
	z = 0;
	scanf("%u %u", &N, &M);

	++M;
	while (--M)
	{
		unsigned R, C;
		char c;
		scanf(" %c %u %u \n", &c, &R, &C);

		--R;
		--C;

		switch (c)
		{
		case '+': assert (can_p(R, C)); put_p(R, C); break;
		case 'x': assert (can_x(R, C)); put_x(R, C); break;
		case 'o': assert (can_o(R, C)); put_o(R, C); break;
		case '.': break;
		default: assert (0);
		}
	}

	memcpy(pmap_, map_, sizeof (pmap_));

	for (j = 0; j < N; ++j)
		safe_put_p(0, j);

	for (j = 0; j < N; ++j)
		safe_put_p(N-1, j);

	for (i = 0; i < N; ++i)
		safe_put_p(i, 0);

	for (i = 0; i < N; ++i)
		safe_put_p(i, N-1);

	for (i = 0; i < N; ++i)
		safe_put_x(i, i);

	for (i = 0; i < N; ++i)
		safe_put_x(N-1-i, N-1-i);

	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j)
			safe_put_p(i, j);

	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j)
			safe_put_x(i, j);

	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j)
			safe_put_o(i, j);

	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			switch (map(i, j))
			{
			case 'o': ++y;
			case '+':
			case 'x': ++y; break;
			case '.': break;
			default: assert (0);
			}

			if (map(i, j) != pmap(i, j))
				++z;
		}
	}

	printf("Case #%u: %u %u\n", x, y, z);

	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j)
			if (map(i, j) != pmap(i, j))
				printf("%c %u %u\n", map(i, j), i + 1, j + 1);
}

int main(int argc, char* argv[])
{
	scanf("%u", &T);

	++T;
	while (--T)
		test_case();

	return 0;
}
