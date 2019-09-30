#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define debug(fmt, ...) fprintf(stderr, (fmt), ##__VA_ARGS__)

static int calc(int N, int M, int A, int t[3][2])
{
#define area_x2(t) ({ \
	int _a = (\
	(t)[0][0] * (t)[1][1] + \
	(t)[1][0] * (t)[2][1] + \
	(t)[2][0] * (t)[0][1] - \
	(t)[0][0] * (t)[2][1] - \
	(t)[1][0] * (t)[0][1] - \
	(t)[2][0] * (t)[1][1]); \
	_a > 0 ? _a : -_a; \
})

	int *x1, *y1, *x2, *y2;

#if 1
	debug("%d %d %d\n", N, M, A);
#endif

	t[0][0] = t[0][1] = 0;
	x1 = &t[1][0];
	y1 = &t[1][1];
	x2 = &t[2][0];
	y2 = &t[2][1];

	for (*x1 = 0; *x1 <= N; (*x1)++)
		for (*y1 = 0; *y1 <= M; (*y1)++)
			for (*x2 = 0; *x2 <= N; (*x2)++)
				for (*y2 = 0; *y2 <= M; (*y2)++)
					if (area_x2(t) == A)
						return 1;
	return 0;
}

int main(void)
{
	int tri[3][2];
	int c, C, N, M, A;

	scanf("%d", &C);
	for (c = 1; c <= C; c++)
	{
		scanf("%d %d %d", &N, &M, &A);

		if (calc(N, M, A, tri))
			printf("Case #%d: %d %d %d %d %d %d\n", c, tri[0][0], tri[0][1], tri[1][0], tri[1][1], tri[2][0], tri[2][1]);
		else
			printf("Case #%d: IMPOSSIBLE\n", c);
	}

	return 0;
}
