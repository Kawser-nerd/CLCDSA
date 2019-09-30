#include <stdio.h>
#include <stdlib.h>

int A, N;
int motes[110];

int intcmp(const void *a, const void *b)
{
	int x = *(const int*)a;
	int y = *(const int*)b;
	return x - y;
}

int delcnt(int insert_count)
{
	long long sz = A;
	int i = 0;
	for (i = 0; i < N; ++i) {
		if (motes[i] < sz) {
			sz += motes[i];
		} else {
			if (insert_count == 0)
				break;
			sz += sz-1;
			insert_count -= 1;
			i -= 1;
		}
	}
	return N-i;
}

int main(void)
{
	int tc;
	scanf("%d", &tc);
	for (int ctc = 1; ctc <= tc; ++ctc) {
		scanf("%d %d", &A, &N);
		for (int i = 0; i < N; ++i)
			scanf("%d", &motes[i]);
		qsort(motes, N, sizeof motes[0], intcmp);
		int best_sol = 1000;
		for (int ic = 0; ic <= 110; ++ic) {
			int sol = delcnt(ic) + ic;
			if (sol < best_sol)
				best_sol = sol;
		}
		printf("Case #%d: %d\n", ctc, best_sol);
	}
	return 0;
}
