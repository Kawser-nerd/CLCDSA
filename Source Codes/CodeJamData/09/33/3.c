#include <stdio.h>

#define MAX 111

int d[MAX][MAX], a[MAX];

int main() {
	int t, T, i, j, k, p, q, min, tmp;

	scanf("%d", &T);

	for(t = 1; t <= T; t++) {
		scanf("%d %d", &p, &q);
		for(i = 1; i <= q; i++)
			scanf("%d", &a[i]);
		a[0] = 0;
		a[q+1] = p+1;
		
		for(i = q+1; i >= 0; i--) {
			//d[i][i] = 0;
			for(j = 0; j <= q+1; j++) {
				min = -1;
				for(k = i+1; k < j; k++) {
					tmp = d[i][k] + d[k][j] + a[k]-a[i]-1 + a[j]-a[k]-1;
					if(min == -1 || tmp < min)
						min = tmp;
				}
				d[i][j] = min == -1 ? 0 : min;
				//printf("%d ", d[i][j]);
			}
			//printf("\n");
		}
		
		printf("Case #%d: %d\n", t, d[0][q+1]);
	}
	return 0;
}