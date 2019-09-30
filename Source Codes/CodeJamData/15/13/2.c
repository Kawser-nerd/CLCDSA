#include <stdio.h>
#include <limits.h>
#include <inttypes.h>

int to_cut(int n_trees, int *xs, int *ys, int tree) {
	int n_left_min = INT_MAX;
	int n_right_min = INT_MAX;
	if (n_trees <= 3)
		return 0;
	for (int i = 0; i < n_trees; ++i) {
		int64_t dx1 = xs[i] - xs[tree];
		int64_t dy1 = ys[i] - ys[tree];
		int n_right = 0;
		int n_left = 0;
		if (i == tree)
			continue;
		for (int j = 0; j < n_trees; ++j) {
			int64_t dx2 = xs[j] - xs[tree];
			int64_t dy2 = ys[j] - ys[tree];
			if (j == tree)
				continue;
			int64_t crossp = dx1 * dy2 - dx2 * dy1;
			if (crossp > 0)
				n_left++;
			if (crossp < 0)
				n_right++;
		}
		if (n_left_min > n_left)
			n_left_min = n_left;
		if (n_right_min > n_right)
			n_right_min = n_right;
	}
	return (n_left_min < n_right_min)? n_left_min : n_right_min;
}

void solve_testcase(int tc) {
	int n_trees;
	int xs[3000];
	int ys[3000];
	scanf("%d", &n_trees);
	for (int i = 0; i < n_trees; ++i) {
		scanf("%d %d", &(xs[i]), &(ys[i]));
	}
	printf("Case #%d:\n", tc);
	for (int i = 0; i < n_trees; ++i) {
		printf("%d\n", to_cut(n_trees, xs, ys, i));
	}
}

int main(void) {
	int n_cases;
	scanf("%d", &n_cases);
	for (int i = 0; i < n_cases; ++i) {
		solve_testcase(i+1);
	}
	return 0;
}


