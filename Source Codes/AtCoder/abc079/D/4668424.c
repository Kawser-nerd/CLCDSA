#include <stdio.h>

int main(int argc, char* argv[]) {

	int costs[10][10];
	int i, j, k, h, w;
	int sum = 0;
	scanf("%d %d", &h, &w);

	for(i = 0; i < 10; i++) {
		for(j = 0; j < 10; j++) {
			scanf("%d", &costs[i][j]);
		}
	}

	int a[h][w];

	for(i = 0; i < h; i++) {
		for(j = 0; j < w; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	for(k = 0; k < 10; k++) {
		for(i = 0; i < 10; i++) {
			for(j = 0; j < 10; j++) {
				if(costs[i][j] > costs[i][k] + costs[k][j])
					costs[i][j] = costs[i][k] + costs[k][j];
			}
		}
	}

	for(i = 0; i < h; i++) {
		for(j = 0; j < w; j++) {
			if(a[i][j] == -1 || a[i][j] == 1)
				continue;
			sum += costs[a[i][j]][1];
		}
	}

	printf("%d", sum);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &h, &w);
  ^
./Main.c:12:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d", &costs[i][j]);
    ^
./Main.c:20:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d", &a[i][j]);
    ^