#include <stdio.h>
#include <stdlib.h>
int big(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

void work(int * data, int * max, int * visited, int current, int count) {
	if (data[data[current]] == current) {
		max[current] = big(max[current], count);
		return ;
	}
	if (visited[current]) {
		max[current] = big(max[current], count - visited[current]);
		return;
	}

	visited[current] = count;
	work(data, max, visited, data[current], count + 1);
	visited[current] = 0;
	return;
}

int main() {
	int p_max;
	int p_count;
	int n_max;
	int n_cycle;

	int ans;
	int pairs;

	int * data = (int *)malloc(1000 * sizeof(int));
	int * max = (int *)malloc(1000 * sizeof(int));
	int * visited = (int *)malloc(1000 * sizeof(int));

	scanf("%d\n", &p_max);
	p_count = 0;

	while (p_count < p_max) {

		p_count ++;
		printf("Case #%d: ", p_count);

		scanf("%d\n", &n_max);
		n_cycle = 0;
		while (n_cycle < n_max) {
			scanf("%d", &data[n_cycle]);
			data[n_cycle] --;
			n_cycle ++;
		}

		n_cycle = 0;
		while (n_cycle < n_max) {
			max[n_cycle] = 0;
			visited[n_cycle] = 0;
			n_cycle ++;
		}

		n_cycle = 0;
		while (n_cycle < n_max) {
			work(data, max, visited, n_cycle, 1);
			n_cycle ++;
		}

		ans = -1;
		n_cycle = 0;
		pairs = 0;
		while (n_cycle < n_max) {
			if (data[data[n_cycle]] == n_cycle) {
				pairs = pairs + max[n_cycle];
			}
			ans = big(ans, max[n_cycle]);
			n_cycle ++;
		}
		ans = big(ans, pairs);
		printf("%d", ans);
		
		printf("\n");
	}
	
}
