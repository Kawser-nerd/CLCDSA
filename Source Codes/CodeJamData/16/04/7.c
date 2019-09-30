#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>

void solve_test_case(int tc, int64_t k, int64_t c, int64_t s) {
	int64_t prev_tile = -1;
	printf("Case #%d:", tc);
	if (k > s*c) {
		printf(" IMPOSSIBLE\n");
		return;
	}
	for (int64_t i = 0; i < s; ++i) {
		int64_t tile = 0;
		for (int64_t j = 0; j < c; ++j) {
			int64_t t = c*i + j;
			tile *= k;
			tile += (t < k)? t : (k-1);
		}
		if (tile != prev_tile) {
			printf(" %"PRId64, tile + 1);
			prev_tile = tile;
		} else {
			break;
		}
	}
	printf("\n");
}

int main(void) {
	int n_test_cases;
	scanf("%d", &n_test_cases);
	for (int i = 0; i < n_test_cases; ++i) {
		int64_t k, c, s;
		scanf("%"SCNd64"%"SCNd64"%"SCNd64, &k, &c, &s);
		solve_test_case(i + 1, k, c, s);
	}
	return 0;
}
