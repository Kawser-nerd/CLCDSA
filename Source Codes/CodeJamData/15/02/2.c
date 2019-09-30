#include <stdio.h>
#include <stdlib.h>

// I'll assume there always exists an optimal strategy where:
// - all the special minutes happen at the very beginning (since a special
//   minute parallelizes the eating task, it can only help if it happens early)
// - pancakes are moved only to empty plates (since not doing so can only
//   increase eating time)
// - all the pancake transfers involve the same number of pancakes (called the
//   "target eating duration")
// - when a special minute takes place, pancakes are taken from the plate that
//   has the most pancakes *among the diners that were served before that shady 
//   special minute thing began*
// - there is no more need for special minutes when all the originally served
//   diners have at most "target eating duration" pancakes

int cmp_int(const void *a, const void *b) {
	return (*(int *) b) - (*(int *) a);
}

void solve_test_case(int test_case_no) {
	int d, i_max;
	int plates[1000];
	int min_breakbase_time;
	scanf("%d", &d);
	for (int i = 0; i < d; ++i) {
		scanf("%d", &(plates[i]));
	}
	qsort(plates, d, sizeof(int), cmp_int);
	min_breakbase_time = plates[0];
	i_max = plates[0];
	for (int i = 1; i <= i_max; ++i) { // i is the target eating duration
		int breakfast_time = i;
		for (int j = 0; (j < d) && (plates[j] > i); ++j) {
			breakfast_time += (plates[j] - 1) / i;
		}
		if (breakfast_time < min_breakbase_time) {
			min_breakbase_time = breakfast_time;
		}
	}
	printf("Case #%d: %d\n", test_case_no, min_breakbase_time);
}

int main(void) {
	int n_test_cases;
	scanf("%d", &n_test_cases);
	for (int i = 0; i < n_test_cases; ++i) {
		solve_test_case(i+1);
	}
	return 0;
}
