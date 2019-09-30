#include <stdio.h>
#include <string.h>
int tn, ti, i, j, res, r, c, d, dsum[501][501][2], sum[501][501];
char str[520];
int minn(int s, int t)
{
	return s < t ? s : t;
}
int pla(int x, int y, int s)
{
	return dsum[x][y][s] - dsum[x - 1][y][s] - dsum[x][y - 1][s] + dsum[x - 1][y - 1][s];
}
int single(int x, int y)
{
	return sum[x][y] - sum[x - 1][y] - sum[x][y - 1] + sum[x - 1][y - 1];
}
int can(int x, int y, int l)
{
	int s, t;
	s = sum[x + l - 1][y + l - 1] - sum[x - 1][y + l - 1] - sum[x + l - 1][y - 1] + sum[x - 1][y - 1] - single(x, y) - single(x, y + l - 1) - single(x + l - 1, y) - single(x + l - 1, y + l - 1);
	t = dsum[x + l - 1][y + l - 1][0] - dsum[x - 1][y + l - 1][0] - dsum[x + l - 1][y - 1][0] + dsum[x - 1][y - 1][0] - s * x;
	t -= pla(x, y, 0) + pla(x, y + l - 1, 0) + pla(x + l - 1, y, 0) + pla(x + l - 1, y + l - 1, 0);
	if (t * 2 != s * (l - 1))
		return 0;
	t = dsum[x + l - 1][y + l - 1][1] - dsum[x - 1][y + l - 1][1] - dsum[x + l - 1][y - 1][1] + dsum[x - 1][y - 1][1] - s * y;
	t -= pla(x, y, 1) + pla(x, y + l - 1, 1) + pla(x + l - 1, y, 1) + pla(x + l - 1, y + l - 1, 1);
	if (t * 2 != s * (l - 1))
		return 0;
	return 1;
}
int main()
{
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti) {
		printf("Case #%d: ", ti);
		scanf("%d%d%d", &r, &c, &d);
		memset(dsum, 0, sizeof(dsum));
		memset(sum, 0, sizeof(sum));
		for (i = 1; i <= r; ++i) {
			scanf("%s", str);
			for (j = 1; j <= c; ++j) {
				sum[i][j] = str[j - 1] - '0' + d + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
				dsum[i][j][0] = (str[j - 1] - '0' + d) * i + dsum[i - 1][j][0] + dsum[i][j - 1][0] - dsum[i - 1][j - 1][0];
				dsum[i][j][1] = (str[j - 1] - '0' + d) * j + dsum[i - 1][j][1] + dsum[i][j - 1][1] - dsum[i - 1][j - 1][1];
			}
		}
		for (res = minn(r, c); res >= 3; --res) {
			for (i = 1; i + res - 1 <= r; ++i) {
				for (j = 1; j + res - 1 <= c; ++j)
					if (can(i, j, res))
						break;
				if (j + res - 1 <= c)
					break;
			}
			if (i + res - 1 <= r)
				break;
		}
		if (res >= 3)
			printf("%d\n", res);
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}
