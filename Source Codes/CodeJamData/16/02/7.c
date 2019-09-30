#include <stdio.h>
#include <string.h>

void solve_test_case(int c, char *s) {
	int i = 0;
	int l = strlen(s);
	int n_flips = 0;
	char prev = s[0];
	for (i = 0; i < l; ++i) {
		if (s[i] != prev) {
			prev = s[i];
			n_flips++;
		}
	}
	if (s[l-1] == '-')
		n_flips++;
	printf("Case #%d: %d\n", c, n_flips);
}

int main(void) {
	int n_test_cases;
	scanf("%d", &n_test_cases);
	for (int i = 0; i < n_test_cases; ++i) {
		char s[102];
		scanf("%s", s);
		solve_test_case(i+1, s);
	}
	return 0;
}
