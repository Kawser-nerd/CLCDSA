#include <stdio.h>
#include <stdlib.h>

int N;
int P[26];

int intcmp(void *a, void *b) {
	int *aa = a;
	int *bb = b;
	return *aa - *bb;
}

int main() {
	int T, x = 1;
	scanf("%d\n", &T);
	while (T--) {
		scanf("%d\n", &N);
		int total = 0;
		for (int i = 0 ; i < N; ++i) {
			scanf("%d ", &P[i]);
			total += P[i];
		}
		printf("Case #%d:", x++);
		while (total) {
			int max = 0;
			int maxi = -1;
			int count = 0;
			int otheri = -1;
			for (int i = 0 ; i < N; ++i) {
				if (P[i] > max) {
					max = P[i];
					maxi = i;
					count = 1;
				} else if (P[i] == max) {
					count += 1;
					otheri = i;
				}
			}
			switch (count) {
			case 2:
				printf(" %c%c", 'A'+maxi, 'A'+otheri);
				P[otheri] -= 1;
				total -= 1;
				break;
			case 1:
			default:
				printf(" %c", 'A'+maxi);
				break;
			}
			P[maxi] -= 1;
			total -= 1;
		}
		printf("\n");
	}
	return 0;
}
