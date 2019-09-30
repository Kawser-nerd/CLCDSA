#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int T, Tn;
	scanf("%d", &Tn);
	for (T = 1; T <= Tn; T++) {
		unsigned long long i, n, t, x = 0;
		int j;
		scanf("%lld", &n);
		i = 1;
		for (j = 0; j < 18; j++) i *= 10;
		while (i > 1) {
			for (j = 9; j > 0; j--) if (x + i / 9 * j <= n) break;
			x += i / 10 * j;
			i /= 10;
		}
		printf("Case #%d: %lld\n", T, x);
	}
	return 0;
}
