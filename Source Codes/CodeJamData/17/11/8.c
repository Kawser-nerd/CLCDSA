#include <stdio.h>
#include <string.h>
#include <string.h>

void aux(char *s, int i, int incr) {
	int prev = '?';
	while (s[i]) {
		if (s[i] == '?')
			s[i] = prev;
		prev = s[i];
		i += incr;
	}
}

void solve_test_case(int case_idx, int r, int c, char *s) {
	for (int i = 0; i < r; ++i) {
		aux(s, 30*i, 1);
		aux(s, 30*i+c-1, -1);
	}
	for (int i = 0; i < c; ++i) {
		aux(s, i, 30);
		aux(s, 30*(r-1)+i, -30);
	}
	for (int i = 0; i < r; ++i) {
		aux(s, 30*i, 1);
		aux(s, 30*i+c-1, -1);
	}
	printf("Case #%d:\n", case_idx);
	for (int i = 0; i < r; ++i) {
		printf("%s", &(s[30*i]));
		printf("\n");
	}
}

int main(void) {
	int n_test_cases;
	scanf("%d", &n_test_cases);
	for (int i = 0; i < n_test_cases; ++i) {
		int r, c;
		char s[30*30];
		memset(s, 0, 30*30);
		scanf("%d%d", &r, &c);
		for (int i = 0; i < r; ++i)
			scanf("%s", &(s[30*(i+1)]));
		solve_test_case(i+1, r, c, &(s[30]));
	}
	return 0;
}
