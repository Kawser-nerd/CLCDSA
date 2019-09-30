#include <stdio.h>
#include <stdlib.h>

int main () {
	long long int i, j, k, l, m, n, o, p, q, r, s, t;
	
	scanf("%I64d", &t);
	for (o = 1; o <= t; o++) {
		scanf("%I64d %I64d %I64d", &n, &i, &j);
		
		if (j == 100) {
			if(i == 100) {
				printf("Case #%I64d: Possible\n", o);
			} else {
				printf("Case #%I64d: Broken\n", o);
			}
		} else if (j == 0) {
			if(i == 0) {
				printf("Case #%I64d: Possible\n", o);
			} else {
				printf("Case #%I64d: Broken\n", o);
			}
		} else {
			if (n >= 100) {
				printf("Case #%I64d: Possible\n", o);
			} else {
				j = 100;
				while (i%2 == 0 && j%2 == 0) {
					i = i/2;
					j = j/2;	
				}
				k = 3;
				while (i > 1 && i >= k) {
					while (i%k == 0 && j%k == 0) {
						i = i/k;
						j = j/k;	
					}	
					k = k + 2;
				}
				if (j <= n) {
					printf("Case #%I64d: Possible\n", o);
				} else {
					printf("Case #%I64d: Broken\n", o);
				}
			}
		}
	}

	return 0;	
}
