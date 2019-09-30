#include <stdio.h>
#include <inttypes.h>

void solve_test_case(int c, int n) {
	uint64_t seen_digits = 0;
	int r = n;
	if (n == 0) {
		printf("Case #%d: INSOMNIA\n", c);
		return;
	}
	while (1) {
		int denom = 1;
		for (int j = 0; j < 9; ++j) {
			if ((r / denom) == 0)
				break;
			int d = (r / denom) % 10;
			seen_digits |= 1ULL << d;
			denom *= 10;
		}
		if (seen_digits == ((1ULL << 10) - 1))
			break;
		r += n;
	}
	printf("Case #%d: %d\n", c, r);
}

int main(void) {
	int n_test_cases;
	scanf("%d", &n_test_cases);
	for (int i = 0; i < n_test_cases; ++i) {
		int n;
		scanf("%d", &n);
		solve_test_case(i+1, n);
	}
}
