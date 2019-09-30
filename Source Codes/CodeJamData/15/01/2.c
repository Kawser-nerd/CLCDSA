#include <stdio.h>

void solve_test_case(int test_case_no) {
	char shynesses[1002];
	int s_max;
	int n_friends_required = 0;
	int n_people_standing = 0;
	scanf("%d %s", &s_max, shynesses);
	for (int i = 0; i <= s_max; ++i) {
		int n = shynesses[i] - '0';
		int diff = i - n_people_standing;
		if (diff > n_friends_required) {
			n_friends_required = diff;
		}
		n_people_standing += n;
	}
	printf("Case #%d: %d\n", test_case_no, n_friends_required);
}

int main(void) {
	int n_test_cases;
	scanf("%d", &n_test_cases);
	for (int i = 0; i < n_test_cases; ++i) {
		solve_test_case(i+1);
	}
	return 0;
}
