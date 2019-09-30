#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#ifdef __MINGW32__
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#else
#define getchar_unlocked _getchar_nolock
#define putchar_unlocked _putchar_nolock
#endif
#endif

static inline int read()
{
	char c;
	while (c = getchar_unlocked(), c <= ' ');
	_Bool sign = c == '-';
	int x = sign ? 0 : c - '0';
	while (c = getchar_unlocked(), '0' <= c && c <= '9')
		x = x * 10 + (c - '0');
	return sign ? -x : x;
}

static inline void write(unsigned x)
{
	char buf[10], *p = buf;
	do
	{
		*p++ = '0' + x % 10;
		x /= 10;
	}
	while (x);
	do
	{
		putchar_unlocked(*--p);
	}
	while (p > buf);
	putchar_unlocked('\n');
}

static int tree[536870911];

struct tribe
{
	int d, n, w, e, s, delta_d, delta_p, delta_s;
};

static inline int min(int a, int b)
{
	return a < b ? a : b;
}

static inline int max(int a, int b)
{
	return a > b ? a : b;
}

static int min_range_impl(int left, int right, int i, int st, int en)
{
	if (left <= st && right >= en)
		return tree[i];
	else if (right <= st + en >> 1)
		return max(tree[i], min_range_impl(left, right, 2*i+1, st, st + en >> 1));
	else if (left >= st + en >> 1)
		return max(tree[i], min_range_impl(left, right, 2*i+2, st + en >> 1, en));
	else
		return max(tree[i],
		           min(min_range_impl(left, right, 2*i+1, st, st + en >> 1),
		               min_range_impl(left, right, 2*i+2, st + en >> 1, en)));
}

static inline int min_range(int left, int right)
{
	int st = 0, en = sizeof tree / sizeof tree[0] + 1 >> 1;
	return min_range_impl(left, right, 0, st, en);
}

static void raise_range_impl(int left, int right, int h, int i, int st, int en)
{
	if (left <= st && right >= en)
		tree[i] = max(tree[i], h);
	else if (right <= st + en >> 1)
	{
		raise_range_impl(left, right, h, 2*i+1, st, st + en >> 1);
		tree[i] = max(tree[i], min(tree[2*i+1], tree[2*i+2]));
	}
	else if (left >= st + en >> 1)
	{
		raise_range_impl(left, right, h, 2*i+2, st + en >> 1, en);
		tree[i] = max(tree[i], min(tree[2*i+1], tree[2*i+2]));
	}
	else
	{
		raise_range_impl(left, right, h, 2*i+1, st, st + en >> 1);
		raise_range_impl(left, right, h, 2*i+2, st + en >> 1, en);
		tree[i] = max(tree[i], min(tree[2*i+1], tree[2*i+2]));
	}
}

static inline void raise_range(int left, int right, int h)
{
	int st = 0, en = sizeof tree / sizeof tree[0] + 1 >> 1;
	return raise_range_impl(left, right, h, 0, st, en);
}

int main(void)
{
	int T = read();
	
	for (int iT = 1; iT <= T; ++iT)
	{
		int N = read();
		
		static struct tribe tribes[1000];
		for (int i = 0; i < N; ++i)
		{
			tribes[i].d = read();
			tribes[i].n = read();
			tribes[i].w = read() + 100900000;
			tribes[i].e = read() + 100900000;
			tribes[i].s = read();
			tribes[i].delta_d = read();
			tribes[i].delta_p = read();
			tribes[i].delta_s = read();
		}
		
		memset(tree, 0, sizeof tree);
		int answer = 0;
		
		for (int d = 0; d <= 676060; ++d)
		{
			for (int i = 0; i < N; ++i)
			{
				if (d >= tribes[i].d && (d - tribes[i].d) % tribes[i].delta_d == 0 && (d - tribes[i].d) / tribes[i].delta_d + 1 <= tribes[i].n)
				{
					int j = (d - tribes[i].d) / tribes[i].delta_d;
					// printf("day %d, tribe %d's %dth attack, ", d, i, j);
					// printf("wall height is %d, ", min_range(tribes[i].w + tribes[i].delta_p * j, tribes[i].e + tribes[i].delta_p * j));
					// printf("attack height is %d, ", tribes[i].s + tribes[i].delta_s * j);
					if (min_range(tribes[i].w + tribes[i].delta_p * j, tribes[i].e + tribes[i].delta_p * j) < tribes[i].s + tribes[i].delta_s * j)
					{
						// printf("success\n");
						++answer;
					}
					// else printf("fail\n");
				}
			}
			for (int i = 0; i < N; ++i)
			{
				if (d >= tribes[i].d && (d - tribes[i].d) % tribes[i].delta_d == 0 && (d - tribes[i].d) / tribes[i].delta_d + 1 <= tribes[i].n)
				{
					int j = (d - tribes[i].d) / tribes[i].delta_d;
					raise_range(tribes[i].w + tribes[i].delta_p * j, tribes[i].e + tribes[i].delta_p * j, tribes[i].s + tribes[i].delta_s * j);
				}
			}
		}
		
		printf("Case #%d: %d\n", iT, answer);
	}
}
