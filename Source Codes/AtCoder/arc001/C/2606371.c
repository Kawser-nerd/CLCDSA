#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define BIG 2000000007

typedef uint64_t ull;
typedef  int64_t sll;

ull udiff (ull a, ull b) {
	if (a >= b) {
		return a - b;
	} else {
		return b - a;
	}
}

char s[3010][3010];

ull dp[8];

ull datum[8];
bool func (ull x) {
	sll i, j;
	for (i = 0; i < 8; i++) {
		datum[i] = (x >> (i * 3)) & 7;
		if (dp[i] != BIG && datum[i] != dp[i]) return false;
	}
	for (i = 0; i < 8; i++) {
		for (j = 1; j < 8; j++) {
			ull jj = (i + j) % 8;

			if (datum[i] == datum[jj] || udiff(datum[i], datum[jj]) == udiff(i, jj)) return false;
		}
	}

	return true;
}

void outans (ull x) {
	sll i, j;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			putchar(datum[i] == j ? 'Q' : '.');
		}
		putchar('\n');
	}
}

ull solve () {
	sll i, j, ki, li;
	// ull result = 0;
	sll result = 0;
	double dresult = 0;
	// ull maybe = 0;
	sll maybe = 0;
	// ull sum = 0;
	sll sum = 0;
	sll item;
	ull *dpcell;

	for (i = 0; i < 8; i++) {
		scanf("%s", s[i]);
	}
	for (i = 0; i < 8; i++) {
		dp[i] = BIG;
		for (j = 0; j < 8; j++) {
			if (s[i][j] == 'Q') {
				if (dp[i] == BIG) {
					dp[i] = j;
				} else {
					goto fail;
				}
			}
		}
	}

	i = (1ULL << 24);
	while (i--) {
		if (func(i)) {
			outans(i);
			return 0;
		}
	}

	fail:
	puts("No Answer");
	return 1;
}

int32_t main (void) {
	int32_t i, j;
	int32_t x, y;

	solve();

	return 0;
} ./Main.c: In function ‘solve’:
./Main.c:63:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s[i]);
   ^