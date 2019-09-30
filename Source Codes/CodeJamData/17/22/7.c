#include <stdio.h>
#include <string.h>
#include <string.h>
#include <assert.h>

#define IMPOSSIBLE	"IMPOSSIBLE"

int aux(int n, int n_single, int n_double, char s, char d) {
	if ((n_double > 0) && (n_double >= n_single)) {
		if ((n_double == n_single) && (n == (n_double + n_single))) {
			for (int i = 0; i < n_double; ++i)
				printf("%c%c", s, d);
			printf("\n");
		} else {
			printf("%s\n", IMPOSSIBLE);
		}
		return 1;
	}
	return 0;
}

void solve_test_case(
		int case_idx,
		int n, int r, int o, int y, int g, int b, int v
) {
	int s[3];
	int d[3];
	char sc[3];
	char dc[3];
	int highest_number = 0;
	printf("Case #%d: ", case_idx);
	if (aux(n, b, o, 'B', 'O')) return;
	if (aux(n, r, g, 'R', 'G')) return;
	if (aux(n, y, v, 'Y', 'V')) return;
	if ((b - o) > ((r - g) + (y - v))) {printf("%s\n", IMPOSSIBLE); return;}
	if ((r - g) > ((b - o) + (y - v))) {printf("%s\n", IMPOSSIBLE); return;}
	if ((y - v) > ((r - g) + (b - o))) {printf("%s\n", IMPOSSIBLE); return;}
	if ((r - g)> highest_number) {
		int i = 0;
		highest_number = r - g;
		s[i] = r; sc[i] = 'R'; d[i] = g; dc[i] = 'G'; i++;
		s[i] = y; sc[i] = 'Y'; d[i] = v; dc[i] = 'V'; i++;
		s[i] = b; sc[i] = 'B'; d[i] = o; dc[i] = 'O'; i++;
	}
	if ((y - v) > highest_number) {
		int i = 0;
		highest_number = y - v;
		s[i] = y; sc[i] = 'Y'; d[i] = v; dc[i] = 'V'; i++;
		s[i] = r; sc[i] = 'R'; d[i] = g; dc[i] = 'G'; i++;
		s[i] = b; sc[i] = 'B'; d[i] = o; dc[i] = 'O'; i++;
	}
	if ((b - o) > highest_number) {
		int i = 0;
		highest_number = b - o;
		s[i] = b; sc[i] = 'B'; d[i] = o; dc[i] = 'O'; i++;
		s[i] = y; sc[i] = 'Y'; d[i] = v; dc[i] = 'V'; i++;
		s[i] = r; sc[i] = 'R'; d[i] = g; dc[i] = 'G'; i++;
	}
	char prev = -1;
	while (1) {
		int highest_number = 0;
		int highest_idx = 0;
		for (int i = 0; i < 3; ++i) {
			if (i == prev)
				continue;
			if ((s[i] - d[i]) > highest_number) {
				highest_number = s[i] - d[i];
				highest_idx = i;
			}
		}
		if (highest_number == 0)
			break;
		printf("%c", sc[highest_idx]);
		s[highest_idx]--;
		assert(s[highest_idx] >= 0);
		prev = highest_idx;
		while (d[highest_idx] > 0) {
			printf("%c%c", dc[highest_idx], sc[highest_idx]);
			s[highest_idx]--;
			d[highest_idx]--;
			assert(s[highest_idx] >= 0);
			assert(d[highest_idx] >= 0);
		}
	}
	printf("\n");
}

int main(void) {
	int n_test_cases;
	scanf("%d", &n_test_cases);
	for (int i = 0; i < n_test_cases; ++i) {
		int n, r, o, y, g, b, v;
		scanf("%d%d%d%d%d%d%d", &n, &r, &o, &y, &g, &b, &v);
		solve_test_case(i+1, n, r, o, y, g, b, v);
	}
	return 0;
}
