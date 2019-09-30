#include <stdio.h>
#include <stdbool.h>

bool graph[105][105];

int main()
{
	int n;
	int m = 0;

	scanf("%d", &n);

	if (n % 2 == 0) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (j != (n - (i - 1)) && i != j) {
					if (!graph[i][j]) {
						m++;
						graph[i][j] = true;
						graph[j][i] = true;
					}
				}
			}
		}
	} else {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (j != (n - i) && i != j) {
					if (!graph[i][j]) {
						m++;
						graph[i][j] = true;
						graph[j][i] = true;
					}
				}
			}
		}
	}

	printf("%d\n", m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (graph[i][j]) {
				printf("%d %d\n", i, j);
				graph[i][j] = false;
				graph[j][i] = false;
			}
		}
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^