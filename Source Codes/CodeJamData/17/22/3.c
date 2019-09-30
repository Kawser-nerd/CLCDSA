#include <stdio.h>

const char *str = "ROYGBV";

int main(void) {
	int i, j;
	int t, c;

	scanf("%d", &t);
	for (c = 1; c <= t; c++) {
		int n, color[6];
		char ans[1001] = "";

		scanf("%d", &n);
		for (i = 0; i < 6; i++)
			scanf("%d", color + i);

		printf("Case #%d: ", c);
		if (color[0] > color[2] + color[4] || color[2] > color[4] + color[0] || color[4] > color[0] + color[2])
			puts("IMPOSSIBLE");
		else {
			int bef_idx;

			bef_idx = -1;
			for (i = 0; i < n; i++) {
				int max, max_idx;

				max = 0;
				max_idx = -1;
				for (j = 0; j < 6; j++) {
					if (j != bef_idx && color[j] > max) {
						max = color[j];
						max_idx = j;
					}
				}

				ans[i] = str[max_idx];
				color[max_idx]--;

				bef_idx = max_idx;
			}

			if (ans[0] == ans[n - 1]) {
				int tmp = ans[n - 2];
				ans[n - 2] = ans[n - 1];
				ans[n - 1] = tmp;
			}

			puts(ans);
		}
	}

	return 0;
}
