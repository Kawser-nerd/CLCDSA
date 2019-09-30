#include <cstdio>
#include <algorithm>

using namespace std;

char s[2002];
int a[2002];

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int T, Tn;
	scanf("%d", &Tn);
	for (T = 1; T <= Tn; T++) {
		int i, j, n, m, r = 0;
		scanf("%s%d", s, &m);
		n = strlen(s);
		for (i = 0; i < n; i++) a[i] = 0;
		for (i = j = 0; i + m <= n; i++) {
			if ((s[i] == '-') != j) {
				r++;
				a[i] ^= 1;
				a[i + m - 1] ^= 1;
			}
			j ^= a[i];
		}
		while (i < n) {
			if ((s[i] == '-') != j) break;
			j ^= a[i];
			i++;
		}
		printf(i == n ? "Case #%d: %d\n" : "Case #%d: IMPOSSIBLE\n", T, r);
	}
	return 0;
}
