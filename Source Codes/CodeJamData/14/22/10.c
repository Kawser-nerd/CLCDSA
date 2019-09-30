#include <stdio.h>
#include <stdlib.h>

int main()
{
	int T, t;
	long long int A, B, K, ans;
	int i, j;
	scanf("%d", &T);
	for(t = 1; t <= T; t++) {
		scanf("%lld %lld %lld", &A, &B, &K);
		if(A <= K || B <= K) {
			ans = A*B;
		} else {
			ans = (A - K + B)*K;
			for(i = K; i < A; i++) {
				for(j = K; j < B; j++) {
					if((i&j) < K)
						ans++;
				}
			}
		}
		printf("Case #%d: %lld\n", t, ans);
	}
	return 0;
}

