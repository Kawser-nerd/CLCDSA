#include <stdio.h>
#include <stdlib.h>

int main() {
	int T;
	int t, i,j,k;
	
	int L, P, C, R;
	long long int longP, longL;

	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		scanf("%d %d %d", &L, &P, &C);
		longP = P;
		longL = L;
		int N = 0;
		
		while (longL * C < longP) {
			longL *= C;
			N++;
		}	
		
		R = 0;
		while (N > 0) { R++; N/= 2;}
		
		printf("Case #%d: %lld\n", t, R);
	}
	
	return 0;
}
