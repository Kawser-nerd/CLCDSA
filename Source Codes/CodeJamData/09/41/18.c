#include <stdio.h>
#include <stdlib.h>

int main () {
	int i, j, k, l, m, n, o, p, q, r, s, t;
	char mat[45][45];
	int vet[45]; 
	
	
	scanf("%d", &t);
	for (o = 1; o <= t; o++) {
		scanf(" %d ", &n);
		for (i = 0; i < n; i++) {
			scanf(" %s ", mat[i]);
			vet[i] = 0;	
			for (j = n - 1; j >= 0; j--) {
				if (mat[i][j] == '1') {
					vet[i] = j+1;
					break;	
				}
			}
		}
		
		k = 0;
		
		for (i = 0; i < n; i++) {
			/*for (j = 0; j < n; j++) {
				printf("%d ", vet[j]);	
			}
			printf(" %d \n", k);*/
			m = vet[i];
			p = i;
			if (m > i+1) {
				for (j = i+1; j < n; j++) {
					if (vet[j] <= i+1) {
						m = vet[j];	
						p = j;
						break;
					}
				}
				for (l = p; l > i; l--) {
					k++;
					m = vet[l];
					vet[l] = vet[l-1];
					vet[l-1] = m;
				}	
			}
		}	
		
		printf("Case #%d: %d\n", o, k);
	}
	
	return 0;	
}
