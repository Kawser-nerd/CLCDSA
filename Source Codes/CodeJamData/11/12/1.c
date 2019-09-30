#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ti, tn;
int a[10000][28], b[30], n, m, i, j, k, res, rsc;
char word[10000][12], str[30];
int cmp(const void *s, const void *t)
{
	int *x = (int *)s, *y = (int *)t, i;
	if (x[27] != y[27])
		return x[27] < y[27] ? -1 : 1;
	for (i = 0; i < 26; ++i)
		if (x[str[i] - 'a'] != y[str[i] - 'a'])
			break;
	if (i == 26)
		return x[26] < y[26] ? -1 : 1;
	else
		return x[str[i] - 'a'] < y[str[i] - 'a'] ? -1 : 1;
}
void check(int f, int t, int cur, int sc)
{
	int i;
	if (cur == 26 || f == t) {
		if (res == -1 || sc > rsc || (sc == rsc && a[f][26] < res)) {
			res = a[f][26];
			rsc = sc;
		}
		return;
	}
	for (i = f; i <= t; ++i)
		if (a[i][str[cur] - 'a'])
			break;
	if (i == t + 1) {
		check(f, t, cur + 1, sc);
		return;
	}
	if (i > f)
		check(f, i - 1, cur + 1, sc + 1);
	for (f = i; f <= t; f = i) {
		for (i = f; i <= t && a[i][str[cur] - 'a'] == a[f][str[cur] - 'a']; ++i);
		check(f, i - 1, cur + 1, sc);
	}
}
int main()
{
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti) {
		printf("Case #%d:", ti);
		scanf("%d%d", &n, &m);
		memset(a, 0, sizeof(a));
		for (i = 0; i < n; ++i) {
			scanf("%s", word[i]);
			a[i][26] = i;
			for (a[i][27] = 0; word[i][a[i][27]]; ++a[i][27])
				a[i][word[i][a[i][27]] - 'a'] |= (1 << a[i][27]);
		}
		for (i = 0; i < m; ++i) {
			scanf("%s", str);
			for (j = 0; str[j]; ++j)
				b[str[j] - 'a'] = j;
			qsort(a, n, sizeof(a[0]), cmp);
			res = -1;
			for (j = 0; j < n; j = k) {
				for (k = j; k < n && a[k][27] == a[j][27]; ++k);
				check(j, k - 1, 0, 0);
			}
			printf(" %s", word[res]);
		}
		printf("\n");
	}
	return 0;
}
