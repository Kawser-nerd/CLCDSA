#include <stdio.h>
#include <stdlib.h>

int main() {
	int p_max;
	int p_count;
	int n_max;
	int n_cycle;
	int n_cycle_2;
	int temp;

	int * count = (int *)malloc(2501 * sizeof(int));

	scanf("%d\n", &p_max);

	while (p_count < p_max) {

		n_cycle = 0;
		while (n_cycle < 2501) {
			count[n_cycle] = 0;
			n_cycle ++;
		}

		p_count ++;
		printf("Case #%d:", p_count);

		scanf("%d\n", &n_max);
		n_cycle = 0;
		while (n_cycle < n_max * 2 - 1) {
			n_cycle_2 = 0;
			while (n_cycle_2 < n_max) {
				scanf("%d", &temp);
				count[temp] ++;
				n_cycle_2 ++;
			}
			n_cycle ++;
		}

		n_cycle = 0;
		while (n_cycle < 2501) {
			if (count[n_cycle] % 2) {
				printf(" %d", n_cycle);
			}
			n_cycle ++;
		}
		
		printf("\n");
	}
	
}
