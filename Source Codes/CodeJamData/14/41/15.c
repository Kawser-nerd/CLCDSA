#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

int main(void) {
	int i, j;
	int t;

	scanf("%d", &t);

	for (i = 1; i <= t; i++) {
		int n, x, s[10000], l, r, ans;

		scanf("%d %d", &n, &x);
		for (j = 0; j < n; j++)
			scanf("%d", s + j);

		qsort(s, n, sizeof(int), &compare);

		l = 0;
		r = n - 1;
		ans = 0;
		while (l <= r)
			if (s[l] + s[r] <= x) {
				l++;
				r--;
				ans++;
			} else {
				r--;
				ans++;
			}

		printf("Case #%d: %d\n", i, ans);
	}

	return 0;
}
