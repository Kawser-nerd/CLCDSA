#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void compute(int n, int m, long long* nn, long long* mm, long long* ans, long long sum) {
	if (n == 0 || m == 0) {
		if (*ans < sum)
			*ans = sum;
		return;
	}
	int i;
	if (nn[1] == mm[1]) {
		if (mm[0] == nn[0]) {
			long long summ = sum;
			summ += nn[0];
			long long* nnc = malloc(sizeof(long long) * (2 * n));
			long long* mmc = malloc(sizeof(long long) * (2 * m));
			for (i = 0; i < 2 * n; i++)
				nnc[i] = nn[i];
			for (i = 0; i < 2 * m; i++)
				mmc[i] = mm[i];
			for (i = 0; i < n-1; i++) {
				nnc[2 * i] = nnc[2 * i + 2];
				nnc[2 * i + 1] = nnc[2 * i + 3];
			}
			for (i = 0; i < m-1; i++) {
				mmc[2 * i] = mmc[2 * i + 2];
				mmc[2 * i + 1] = mmc[2 * i + 3];
			}
			compute(n - 1, m - 1, nnc, mmc, ans, summ);
			free(nnc);
			free(mmc);
		} else if (mm[0] > nn[0]) {
			long long summ = sum;
			summ += nn[0];
			long long* nnc = malloc(sizeof(long long) * (2 * n));
			long long* mmc = malloc(sizeof(long long) * (2 * m));
			for (i = 0; i < 2 * n; i++)
				nnc[i] = nn[i];
			for (i = 0; i < 2 * m; i++)
				mmc[i] = mm[i];
			mmc[0] -= nn[0];
			for (i = 0; i < n-1; i++) {
				nnc[2 * i] = nnc[2 * i + 2];
				nnc[2 * i + 1] = nnc[2 * i + 3];
			}
			compute(n - 1, m, nnc, mmc, ans, summ);
			free(nnc);
			free(mmc);
		} else if (mm[0] < nn[0]) {
			long long summ = sum;
			summ += mm[0];

			long long* nnc = malloc(sizeof(long long) * (2 * n));
			long long* mmc = malloc(sizeof(long long) * (2 * m));
			for (i = 0; i < 2 * n; i++)
				nnc[i] = nn[i];
			for (i = 0; i < 2 * m; i++)
				mmc[i] = mm[i];
			nnc[0] -= mm[0];
			for (i = 0; i < m-1; i++) {
				mmc[2 * i] = mmc[2 * i + 2];
				mmc[2 * i + 1] = mmc[2 * i + 3];
			}
			compute(n, m - 1, nnc, mmc, ans, summ);
			free(nnc);
			free(mmc);
		}
		return;
	}
	long long* nnc = malloc(sizeof(long long) * (2 * n));
	long long* mmc = malloc(sizeof(long long) * (2 * m));
	for (i = 0; i < 2 * n; i++)
		nnc[i] = nn[i];
	for (i = 0; i < 2 * m; i++)
		mmc[i] = mm[i];
	for (i = 0; i < m-1; i++) {
		mmc[2 * i] = mmc[2 * i + 2];
		mmc[2 * i + 1] = mmc[2 * i + 3];
	}
	compute(n, m - 1, nnc, mmc, ans, sum);
	free(nnc);
	free(mmc);

	 nnc = malloc(sizeof(long long) * (2 * n));
		 mmc = malloc(sizeof(long long) * (2 * m));
		for (i = 0; i < 2 * n; i++)
			nnc[i] = nn[i];
		for (i = 0; i < 2 * m; i++)
			mmc[i] = mm[i];
		for (i = 0; i < n-1; i++) {
			nnc[2 * i] = nnc[2 * i + 2];
			nnc[2 * i + 1] = nnc[2 * i + 3];
		}
		compute(n-1, m, nnc, mmc, ans, sum);
		free(nnc);
		free(mmc);
}

int main() {
	int testcase, it;
	scanf("%d", &testcase);
	for (it = 1; it <= testcase; it++) {
		int n, m;
		scanf("%d %d", &n, &m);
		long long* nn = malloc(sizeof(long long) * (2 * n));
		long long* mm = malloc(sizeof(long long) * (2 * m));
		int i;
		for (i = 0; i < n; i++) {
			scanf("%lld %lld", &nn[2 * i], &nn[2 * i + 1]);
		}
		for (i = 0; i < m; i++) {
			scanf("%lld %lld", &mm[2 * i], &mm[2 * i + 1]);
		}
		long long * ans = malloc(sizeof(long long)*1);
		ans[0] = 0;
		compute(n, m, nn, mm, ans, 0);

		printf("Case #%d: %lld\n", it, *ans);
		free(nn);
		free(mm);
	}
	return 0;
}
