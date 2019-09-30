#include <stdio.h>
#define MAXN 20000
#define MAX(i, j) (((i)>(j))?(i):(j))
#define MIN(i, j) (((i)<(j))?(i):(j))

int a[MAXN], l[MAXN], d[MAXN], D, n, cc, t, ans;

int main() {
	int i, j, k;
	scanf("%d\n", &t);
	for (cc = 1; cc <= t; cc ++) {
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
			scanf("%d %d", d + i, l + i);
		scanf("%d", &D);
		ans = 0;
		a[1] = d[1];
		for (i = 2; i <= n; i++) {
			a[i] = 0;
			for (j = 1; j < i; j ++)
				if (a[j] + d[j] >= d[i])
					a[i] = MAX(a[i], d[i] - d[j]);
			a[i] = MIN(a[i], l[i]);
			if (a[i] + d[i] >= D) ans = 1;
		}
		if (a[1] + d[1] >= D) ans = 1;
		printf("Case #%d: %s\n", cc, (ans)?"YES":"NO");
	}
}
