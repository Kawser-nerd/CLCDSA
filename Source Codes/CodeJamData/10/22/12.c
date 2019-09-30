#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 51
#define INF 100



void solve()
{
	int i, j, n, k, b, t;
	int x[MAX], v[MAX], swaps[MAX];

	scanf("%d%d%d%d", &n, &k, &b, &t);
	for (i = 0; i < n; i++)
		scanf("%d", &x[i]);
	for (i = 0; i < n; i++)
		scanf("%d", &v[i]);

	for (i = 0; i < n; i++) {
		if (x[i] + t*v[i] >= b) {
			swaps[i] = 0;
			for (j = i+1; j < n; j++) {
				if (v[i] > v[j]) {
					if (x[j] + t*v[j] < b)
						swaps[i]++;
				}
			}
		} else {
			swaps[i] = INF;
		}
	}

	for (i = 0; i < n-1; i++) {
		int min = i;
		for (j = i+1; j < n; j++) {
			if (swaps[min] > swaps[j])
				min = j;
		}
		int tmp = swaps[i];
		swaps[i] = swaps[min];
		swaps[min] = tmp;
	}

	int sum = 0;
	for (i = 0; i < k; i++) {
		if (swaps[i] == INF) {
			printf("IMPOSSIBLE");
			return;
		}
		sum += swaps[i];
	}
	printf("%d", sum);
}


int main()
{
	freopen("B-large.in", "r", stdin);

	int i, t;

	scanf("%d", &t);
	for (i = 0; i < t; i++) {

		printf("Case #%d: ", i+1);
		solve();
		printf("\n");

	}

	return 0;
}
