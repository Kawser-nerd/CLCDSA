#include <stdio.h>
int ti, tn, i, j, k, l, n, a[60][60], s[60], max[2];
char str[60];
int main()
{
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti) {
		printf("Case #%d: ", ti);
		scanf("%d%d", &n, &k);
		for (i = 0; i < n; ++i) {
			scanf("%s", str);
			for (j = 0; j < n; ++j)
				if (str[j] == '.')
					a[i][j] = -1;
				else if (str[j] == 'R')
					a[i][j] = 0;
				else
					a[i][j] = 1;
		}
		for (i = 0; i < n; ++i) {
			s[0] = 0;
			for (j = n - 1; j >= 0; --j) {
				if (a[i][j] != -1)
					s[++s[0]] = a[i][j];
				a[i][j] = -1;
			}
			for (j = 1; j <= s[0]; ++j)
				a[i][n - j] = s[j];
		}
		max[0] = max[1] = 0;
		for (i = 0; i < n; ++i)
			for (j = 0; j < n; ++j)
				if (a[i][j] != -1) {
					for (l = j + 1; l < n; ++l)
						if (a[i][l] != a[i][j])
							break;
					if (l - j > max[a[i][j]])
						max[a[i][j]] = l - j;
				}
		for (j = 0; j < n; ++j)
			for (i = 0; i < n; ++i)
				if (a[i][j] != -1) {
					for (l = i + 1; l < n; ++l)
						if (a[l][j] != a[i][j])
							break;
					if (l - i > max[a[i][j]])
						max[a[i][j]] = l - i;
				}
		for (i = 0; i < n; ++i)
			for (j = 0; j < n; ++j)
				if (a[i][j] != -1) {
					for (l = 1; i + l < n && j + l < n; ++l)
						if (a[i + l][j + l] != a[i][j])
							break;
					if (l > max[a[i][j]])
						max[a[i][j]] = l;
					for (l = 1; i + l < n && j - l >= 0; ++l)
						if (a[i + l][j - l] != a[i][j])
							break;
					if (l > max[a[i][j]])
						max[a[i][j]] = l;
				}
		if (max[0] < k && max[1] < k)
			printf("Neither\n");
		else if (max[0] >= k && max[1] >= k)
			printf("Both\n");
		else if (max[0] >= k)
			printf("Red\n");
		else
			printf("Blue\n");
	}
	return 0;
}
