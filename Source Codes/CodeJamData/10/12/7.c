#include <stdio.h>
int ti, tn, i, j, k, l, s, t, res, I, n, m, d, am, a[200], ans[200][500];
int myabs(int s)
{
	return s > 0 ? s : -s;
}
int calc(int x, int y)
{
	int s = myabs(x - y), ret;
	if (s <= m)
		return 0;
	if (m == 0)
		return s;
	ret = s - m;
	if (((s - 1) / m) * I < ret)
		ret = ((s - 1) / m) * I;
	return ret;
}
int main()
{
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti) {
		printf("Case #%d: ", ti);
		scanf("%d%d%d%d", &d, &I, &m, &n);
		am = 0;
		for (i = 0;i < n; ++i) {
			scanf("%d", &a[i]);
			if (a[i] > am) {
				am = a[i];
			}
		}
		for (i = 0; i <= am; ++i)
			ans[0][i] = myabs(i - a[0]) + (n - 1) * d;
		res = ans[0][a[0]];
		for (i = 1; i < n; ++i)
			for (j = 0; j <= am; ++j) {
				t = myabs(a[i] - j);
				ans[i][j] = t + (n - 1) * d;
				for (k = 0; k < i; ++k)
					for (l = 0; l <= am; ++l) {
						s = calc(l, j);
						if (ans[k][l] + t - d + s < ans[i][j])
							ans[i][j] = ans[k][l] - d + s + t;
					}
				if (ans[i][j] < res)
					res = ans[i][j];
			}
		printf("%d\n", res);
	}
	return 0;
}
