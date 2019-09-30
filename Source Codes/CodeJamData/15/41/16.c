#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static char fall(int R, int C, char *G, int oi, int oj, int d)
{
	int ns = d % 2 ? 2 - d : 0;
	int we = d % 2 ? 0 : 1 - d;
	int i = oi + ns;
	int j = oj + we;
	while (0 <= i && i < R && 0 <= j && j < C) {
		if (G[i * C + j] != '.')
			return 0;
		i += ns;
		j += we;
	}
	return 1;
}

static void solve(int R, int C, char *G)
{
	int y = 0;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			int d;
			switch (G[i * C + j]) {
			case '.': continue;
			case '>': d = 0; break;
			case 'v': d = 1; break;
			case '<': d = 2; break;
			case '^': d = 3; break;
			default: assert(0);
			}
			if (fall(R, C, G, i, j, d)) {
				if (fall(R, C, G, i, j, (d + 1) % 4)
				    && fall(R, C, G, i, j, (d + 2) % 4)
				    && fall(R, C, G, i, j, (d + 3) % 4)) {
					printf("IMPOSSIBLE\n");
					return;
				}
				y++;
			}
		}
	printf("%d\n", y);
}

int main(void) {
	int T_;
	assert(scanf("%d", &T_) == 1);
	for (int t_ = 1; t_ <= T_; t_++) {
		int R, C;
		assert(scanf("%d %d", &R, &C) == 2);
		char *G = malloc((size_t)R * (size_t)C + 1U);
		for (int i = 0; i < R; i++) {
			assert(scanf("%s", &G[i * C]) == 1);
			assert(strlen(&G[i * C]) == (size_t)C);
		}
		printf("Case #%d: ", t_);
		solve(R, C, G);
		free(G);
	}
	return 0;
}
