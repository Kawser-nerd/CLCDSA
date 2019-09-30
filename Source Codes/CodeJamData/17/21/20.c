#include <stdio.h>

int pos[1000], spd[1000];
int rem[1000];

int main(void)
{
	int i, j, T;
	scanf("%d", &T);
	for (i = 0; i < T; ++i) {
		int dest, n;
		double ans = 0;
		scanf("%d %d", &dest, &n);
		for (j = 0; j < n; ++j) {
			scanf("%d %d", &pos[j], &spd[j]);
			rem[j] = dest - pos[j];

			if (ans < (double)rem[j] / (double)spd[j])
				ans = (double)rem[j] / (double)spd[j];
		}

		ans = (double)dest / ans;

		printf("Case #%d: %lf\n", i + 1, ans);
	}
}
