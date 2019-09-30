#include <stdio.h>
#include <stdlib.h>

int main() {
	
	
	int num;
	scanf("%d\n", &num);

	int count = 0;
	int * array = malloc(10 * sizeof(int));
	
	int i;
	int j;
	int k;
	int cycle;
	int b;

	while (count < num) {
		scanf("%d\n", &i);
		j = 0;
		count ++;

		if (i) {
			cycle = 0;
			while (cycle < 10) {
				array[cycle] = 0;
				cycle ++;
			}
			b = 1;
			while (b) {
				j = j + i;
				k = j;
				while (k) {
					array[k % 10] = 1;
					k = k / 10;
				}
				cycle = 0;
				b = 0;
				while (cycle < 10) {
					if (!array[cycle]) {
						b = 1;
					}
					cycle ++;
				}
			}
			printf("Case #%d: %d\n", count, j);
		}
		else {
			printf("Case #%d: INSOMNIA\n", count);
		}
	}
}
