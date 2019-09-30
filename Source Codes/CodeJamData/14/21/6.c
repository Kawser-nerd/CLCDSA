#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int main(void) {
	int i, j, k, l;
	int t;

	scanf("%d", &t);
	for (i = 1; i <= t; i++) {
		int n, len[100], num[100][100] = {0}, tnum, tmpLen, ok;
		char str[100][101], tmp1[101] = "";

		scanf("%d ", &n);
		for (j = 0; j < n; j++)
			scanf("%s%n ", str[j], len + j);

		tmpLen = 0;
		tnum = 1;
		for (j = 1; j <= len[0]; j++)
			if (str[0][j] == str[0][j - 1])
				tnum++;
			else {
				num[0][tmpLen] = tnum;
				tmp1[tmpLen] = str[0][j - 1];
				tmpLen++;

				tnum = 1;
			}

		ok = 1;
		for (j = 1; j < n; j++) {
			char tmp2[101] = "";

			tmpLen = 0;
			tnum = 1;
			for (k = 1; k <= len[j]; k++)
				if (str[j][k] == str[j][k - 1])
					tnum++;
				else {
					num[j][tmpLen] = tnum;
					tmp2[tmpLen] = str[j][k - 1];
					tmpLen++;

					tnum = 1;
				}

			if (strcmp(tmp1, tmp2)) {
				ok = 0;
				break;
			}
		}

		if (ok) {
			int ans, sum, min;

			ans = 0;
			for (j = 0; j < tmpLen; j++) {
				min = 1000000000;
				for (k = 1; k <= 100; k++) {
					sum = 0;
					for (l = 0; l < n; l++)
						sum += abs(k - num[l][j]);

					min = min(min, sum);
				}

				ans += min;
			}

			printf("Case #%d: %d\n", i, ans);
		} else
			printf("Case #%d: Fegla Won\n", i);
	}

	return 0;
}
