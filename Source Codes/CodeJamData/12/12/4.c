#include <stdio.h>

#define MAXN 2000

int a[MAXN], b[MAXN], o[MAXN], n, times, star;

int try2() {
	int i;
	for (i = 1; i <= n; i++)
		if (b[i] <= star && o[i] < 2) {
			star += 2 - o[i];
			o[i] = 2;
			times++;
			return 1;
		}
	return 0;
}

int try1() {
	int i;
	for (i = n; i >= 1; i--)
		if (a[i] <= star && o[i] < 1) {
			star += 1;
			o[i] = 1;
			times++;
			return 1;
		}
	return 0;
}

int main() {
	int cc, t, i, j, k;
	scanf("%d", &cc);
	for (t = 1; t <= cc; t++) {
		scanf("%d", &n);
		for (i = 1; i <= n; i++) 
			scanf("%d %d", a + i, b + i);
		for (i = 1; i <= n; i++)
			for (j = i + 1; j <= n; j++) 
			if (b[i] > b[j])
			{
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
				tmp = b[i];
				b[i] = b[j];
				b[j] = tmp;
			}
		for (i = 1; i <= n; i++) o[i] = 0;
		times = 0;
		star = 0;
		while (star < n + n) {
			while (try2());
			if (!try1()) break;
		}
		printf("Case #%d: ", t);
		if (star == n + n)
			printf("%d\n", times);
		else printf("Too Bad\n");
	}
}
