#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
	return *((int*)a) - *((int*)b);
}

int main() {
	int T, t, N, len[105], c[105][105], size, sort[105], ans, i, j, k;
	char str[105][105], tmp[105][105];
	scanf("%d", &T);
	for (t = 0; t < T; t++) {
		printf("Case #%d: ", t + 1);
		scanf("%d", &N);
		for (i = 0; i < N; i++) {
			scanf("%s", str[i]);
			len[i] = strlen(str[i]);
		}
		for (i = 0; i < N; i++) {
			memset(tmp[i], 0, sizeof(tmp[i]));
			tmp[i][0] = str[i][0];
			for (j = 0, k = 0; j < len[i]; j++) {
				if (str[i][j] != tmp[i][k])
					tmp[i][++k] = str[i][j];
			}
		}
		size = k + 1;
		for (i = 1; i < N; i++) {
			if (strcmp(tmp[i], tmp[0]) != 0)
				break;
		}
		if (i < N) {
			printf("Fegla Won\n");
			continue;
		}
		/*printf("tmp: %s\n", tmp);*/
		for (i = 0; i < N; i++) {
			c[i][0] = 1;
			for (j = 1, k = 0; j < len[i]; j++) {
				if (str[i][j] != str[i][j - 1])
					c[i][++k] = 1;
				else
					c[i][k]++;
			}
		}
		/*
		for (i = 0; i < N; i++) {
			for (j = 0; j < size; j++) {
				printf("%d ", c[i][j]);
			}
			printf("\n");
		}
		*/
		ans = 0;
		for (i = 0; i < size; i++) {
			for (j = 0; j < N; j++) {
				sort[j] = c[j][i];
			}
			qsort(sort, N, sizeof(int), cmp);
			for (j = 0; j < N; j++) {
				if (sort[j] > sort[N / 2])
					ans += (sort[j] - sort[N / 2]);
				else
					ans += (sort[N / 2] - sort[j]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
