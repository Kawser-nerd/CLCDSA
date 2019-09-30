#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;
int count[6];
char *color = "ROYGBV";

int findmax() {
	int max = 0, maxp = -1;
	for (int i = 0 ; i < 6; ++i) {
		if (count[i] > max) {
			max = count[i];
			maxp = i;
		}
	}
	return maxp;
}

int main() {
	int t, x = 1;
	scanf("%d\n", &t);
	while (t--) {
		scanf("%d ", &N);
		for (int i = 0; i < 6; ++i)	
			scanf("%d ", &count[i]);
		int imp = 0;
		for (int i = 0; i < 6; i += 2) {
			if (count[i] > N / 2)
				imp = 1;
		}
		if (imp) {
			printf("Case #%d: IMPOSSIBLE\n", x++);
			continue;
		}

		char sol[N+1];
		for (int i = 0; i < N; i++) {
			sol[i] = '_';
		}
		sol[N] = '\0';

		int k = findmax();
		//printf("Max is %d: count %d color %c\n", k, count[k], color[k]);
		for (int i = 0; i < count[k]; i++) {
			sol[2*i] = color[k];
		}

		int holes = count[k] - 1;
		int endgap = count[k] + holes;
		//printf("holes %d endgap %d\n", holes, endgap);
		count[k] = 0;

		k = findmax();
		int placed = 0;
		//printf("Max is %d: count %d color %c\n", k, count[k], color[k]);
		for (int i = 0; i < count[k] && endgap + 2*i < N; ++i) {
			sol[endgap + 2*i] = color[k];
			placed++;
		}

		//printf("placing %d remaining %c\n", count[k] - placed, color[k]);
		for (int i = 0; i < N && placed < count[k]; ++i) {
			if (sol[i] == '_') {
				placed++;
				sol[i] = color[k];
			}
		}
		count[k] = 0;

		k = findmax();
		placed = 0;
		for (int i = 0; i < N && placed < count[k]; ++i) {
			if (sol[i] == '_') {
				placed++;
				sol[i] = color[k];
			}
		}
		count[k] = 0;

		printf("Case #%d: %s\n", x++, sol);
	}
	return 0;
}
