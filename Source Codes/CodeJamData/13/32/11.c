#include <stdio.h>

int main() {
	int t, x, y, i, j;
	scanf("%d", &t);
	for(i = 0; j < t; i++) {
		scanf("%d %d", &x, &y);
		printf("Case #%d: ", i + 1);
		j = 0;
		while(j != x) {
			if(j > x) {
				printf("EW");
				j--;
			}
			else {
				printf("WE");
				j++;
			}
		}
		j = 0;
		while(j != y) {
			if(j > y) {
				printf("NS");
				j--;
			}
			else {
				printf("SN");
				j++;
			}
		}
		printf("\n");
	}
	return 0;
}
