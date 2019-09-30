#include <stdio.h>
#include <string.h>
#include <string.h>

void solve_test_case(int case_idx, int d, int n, int *k, int *s) {
	double earliest_finish = 0.;
	for (int i = 0; i < n; ++i) {
		double tmp = ((double) (d - k[i])) / ((double) s[i]);
		if (tmp > earliest_finish)
			earliest_finish = tmp;
	}
	printf("Case #%d: %f\n", case_idx,
			((double) d)/((double) earliest_finish));
}

int main(void) {
	int n_test_cases;
	scanf("%d", &n_test_cases);
	for (int i = 0; i < n_test_cases; ++i) {
		int d, n;
		int k[1000];
		int s[1000];
		memset(s, 0, 30*30);
		scanf("%d%d", &d, &n);
		for (int i = 0; i <n; ++i)
			scanf("%d%d", &(k[i]), &(s[i]));
		solve_test_case(i+1, d, n, k, s);
	}
	return 0;
}
