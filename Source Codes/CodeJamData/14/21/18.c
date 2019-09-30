#include <stdio.h>

int ti, tn, n, i, j, k, ans;
struct node {
	int n;
	char ch[100];
	int cnt[100];
} a[100];
char str[120];
int tmp[100];

int
main() {
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti) {
		printf("Case #%d: ", ti);
		scanf("%d", &n);
		for (i = 0; i < n; ++i) {
			scanf("%s", str);
			a[i].n = 0;
			for (j = 0; str[j]; ++j)
				if (j == 0 || str[j] != str[j - 1]) {
					a[i].ch[a[i].n] = str[j];
					a[i].cnt[a[i].n] = 1;
					++a[i].n;
				} else
					++a[i].cnt[a[i].n - 1];
		}
		for (i = 1; i < n; ++i)
			if (a[i].n != a[0].n)
				break;
			else {
				for (j = 0; j < a[i].n; ++j)
					if (a[i].ch[j] != a[0].ch[j])
						break;
				if (j != a[i].n)
					break;
			}
		if (i != n) {
			printf("Fegla Won\n");
			continue;
		}
		for (ans = i = 0; i < a[0].n; ++i) {
			for (j = 0; j < n; ++j)
				tmp[j] = a[j].cnt[i];
			for (j = 0; j < n; ++j)
				for (k = j + 1; k < n; ++k)
					if (tmp[j] > tmp[k]) {
						tmp[j] ^= tmp[k];
						tmp[k] ^= tmp[j];
						tmp[j] ^= tmp[k];
					}
			for (j = 0; j < n; ++j)
				ans += (j <= (n >> 1) ? tmp[n >> 1] - tmp[j] : tmp[j] - tmp[n >> 1]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
