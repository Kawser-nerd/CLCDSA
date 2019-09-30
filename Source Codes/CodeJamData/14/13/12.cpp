#include <cstdio>

int a[1010];

int main(void) {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	FILE *fin = fopen("log", "w");
	int kase; scanf("%d", &kase); for (int _ = 1; _  <= kase; _++) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		int Ans1 = 0, Ans2 = 0;
		for (int i = 1; i <= n; i++) Ans1 += (i >= a[i]);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j < i; j++) Ans2 += (a[j] > a[i]);
		fprintf(fin, "%d %d ", Ans1, Ans2);
		if (Ans1 < 480 || Ans2 < 235000 || (Ans1 <= 490 && Ans2 < 250000))
			printf("Case #%d: BAD\n", _), fputs("BAD", fin);
		else
			printf("Case #%d: GOOD\n", _), fputs("GOOD", fin);
		fputs("\n", fin);
	}
	return 0;
}

