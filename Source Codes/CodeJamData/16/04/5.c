#include <stdio.h>

typedef long long ll;

int main() {
	int t, T;
	ll K, C, S, a, i, j, k;
	scanf("%d", &T);
	for(t = 1; t <= T; t++) {
		scanf("%lld %lld %lld", &K, &C, &S);
		printf("Case #%d:", t);
		if(S * C < K) {
			printf(" IMPOSSIBLE");
		} else {
			a = 0;
			i = 0;
			while(i < K) {
				k = 0;
				for(j = 0; j < C; j++) {
					k *= K;
					k += i;
					i++;
					if(i >= K) break;
				} 
				printf(" %lld", k + 1);
			}
		}
		printf("\n");
	}
}
