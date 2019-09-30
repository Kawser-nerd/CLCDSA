#include <stdio.h>
#include <string.h>
#include <algorithm>

int h, n;
int res[2048][16];
int price[2048];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt<=tests; tt++) {
		scanf("%d", &h);
		n = 1<<h;

		memset(res, 63, sizeof(res));
		for (int i = 0; i<n; i++) {
			int m;
			scanf("%d", &m);
			res[n-1 + i][m] = 0;
		}	
		for (int j = 1; j<=h; j++) {
			int s = (1<<(h-j)) - 1;
			int t = (1<<(h-j+1)) - 1;
			for (int i = s; i<t; i++) scanf("%d", price + i);
		}
		for (int j = n-2; j>=0; j--) {
			int l = (j<<1) + 1;
			int r = (j<<1) + 2;
			for (int u = 0; u<=h; u++) if (res[l][u] < 1000000000)
				for (int v = 0; v<=h; v++) if (res[r][v] < 1000000000) {
					int mm = std::min(u, v);
					int tres = res[l][u] + res[r][v];

					if (res[j][mm] > tres + price[j])
						res[j][mm] = tres + price[j];
					if (mm>0 && res[j][mm-1] > tres)
						res[j][mm-1] = tres;
				}
		}
		int ans = 1000000000;
		for (int u = 0; u<=h; u++) if (ans > res[0][u]) ans = res[0][u];

		printf("Case #%d: %d\n", tt, ans);
	}
	return 0;
}
