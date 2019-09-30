#include <cstdio>

int tests, L, P, C;

int main(int argc, char *argv[]) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &tests);
	for (int cases = 1; cases <= tests; ++ cases) {
		scanf("%d%d%d", &L, &P, &C);
		int x = 0, ans = 0;
		long long tmp = L;
		while (tmp < P) {
			tmp *= C;
			++ x;
		}
		while (x > 1) {
			++ ans;
			x = (x + 1) / 2;
		}
		printf("Case #%d: %d\n", cases, ans);
	}
	return 0;
}
