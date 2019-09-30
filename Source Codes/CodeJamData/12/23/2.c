#include <stdio.h>

typedef int bool;
#define false	(0)
#define true	(1)
typedef long long LL;

int N;
LL S[1000];
int own[1000];

bool doit(int lev, LL sumA, LL sumB) {
	if (sumA && sumA == sumB) {
		int i;
		bool first = true;
		for (i = 0; i < N; i++) {
			if (own[i] == 1) {
				if (first)
					first = false;
				else
					printf(" ");
				printf("%lld", S[i]);
			}
		}
		printf("\n");
		first = true;
		for (i = 0; i < N; i++) {
			if (own[i] == 2) {
				if (first)
					first = false;
				else
					printf(" ");
				printf("%lld", S[i]);
			}
		}
		printf("\n");
		return true;
	}
	if (lev >= N) return false;

	own[lev] = 1;
	if (doit(lev+1, sumA+S[lev], sumB)) return true;
	own[lev] = 2;
	if (doit(lev+1, sumA, sumB+S[lev])) return true;
	own[lev] = 0;
	return doit(lev+1, sumA, sumB);
}

int main() {
	int ntc, tc;
	scanf("%d", &ntc);

	int i, j, k;
	for (tc = 1; tc <= ntc; tc++) {
		scanf("%d", &N);
		for (i = 0; i < N; i++)
			scanf("%lld", &S[i]);
		printf("Case #%d:\n", tc);
		if (!doit(0, 0, 0))
			printf("Impossible\n");
	}

	return 0;
}

