#include <stdio.h>
#include <string.h>

int T, Ac, Aj, C, D, J, K;
char minutes[1440];
unsigned char swaps[1441][2][1443];

static inline int min(int a, int b) { return a < b ? a : b; }

int main() {
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		memset(minutes, 0, sizeof(minutes));
		scanf("%d %d", &Ac, &Aj);
		for (int i = 0; i < Ac; i++) {
			scanf("%d %d", &C, &D);
			for (int j = C; j < D; j++)
				minutes[j] = 1;
		}
		for (int i = 0; i < Aj; i++) {
			scanf("%d %d", &J, &K);
			for (int j = J; j < K; j++)
				minutes[j] += 2;
		}
		
		// probably the least efficient way to solve it :D
		memset(swaps, 255, sizeof(swaps));
		swaps[0][0][721] = swaps[0][1][721] = 0;
		for (int m = 0; m < 1440; m++) {
			for (int imba = -720; imba <= 720; imba++) { // >0 in favor of Cameron
				for (int jamieFirst = 0; jamieFirst <= 1; jamieFirst++) {
					int swap = swaps[m][jamieFirst][721 + imba];
					if (swap == 255)
						continue;
					int isJamie = jamieFirst ^ (swap & 1);
					if (!(minutes[m] & 1)) {
						swaps[m + 1][jamieFirst][722 + imba] = min(swaps[m + 1][jamieFirst][722 + imba], swap + isJamie);
					}
					if (!(minutes[m] & 2)) {
						swaps[m + 1][jamieFirst][720 + imba] = min(swaps[m + 1][jamieFirst][720 + imba], swap + !isJamie);
					}
				}
			}
		}
		printf("Case #%d: %d\n", t, (min(swaps[1440][0][721], swaps[1440][1][721]) + 1) & -2);
	}
	return 0;
}
