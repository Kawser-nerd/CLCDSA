#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double P(int diamonds, int placed, int nth)
{
	int was = 0, all = 0;
	for (int bm = 0; bm < (1<<placed); ++bm) {
		int A = 0, B = 0;
		for (int i = 0; i < placed; ++i) {
			if (B == diamonds/2)
				A += 1;
			else if (A == diamonds/2 && B != diamonds/2)
				B += 1;
			else if (((1<<i) & bm) == 0)
				A += 1;
			else if (((1<<i) & bm) != 0)
				B += 1;
			else
				abort();
		}
		if (A > nth)
			was += 1;
		all += 1;
	}
	return was*1.0 / all;
}

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		printf("Case #%d: ", tc);
		int X, Y, N;
		scanf("%d %d %d", &N, &X, &Y);
		int diamond_level = 1 + (abs(X) + Y) / 2;
		int count_level = lrintl(ceill((1.0 + sqrtl(1+8*N)) / 4.0));
		if (diamond_level < count_level) {
			puts("1.0");
			continue;
		} else if (diamond_level > count_level) {
			puts("0.0");
			continue;
		}
		int L = diamond_level;
		int all_diamonds = 4*L - 3;
		int placed_diamonds = N - 2*(L-1)*(L-1) + (L-1);
		printf("%0.9lf\n", P(all_diamonds, placed_diamonds, Y));
	}
	return 0;
}
