#include <stdio.h>

#define CSIZE 10000

int cache[CSIZE][CSIZE] = {0};

void set_cache(int A, int B, int n){
	if (A >= 0 && B >= 0 && A < CSIZE && B < CSIZE)
		cache[A][B] = n;
}

int can_win(int A, int B) {
	int C;
	if (A <= 0 || B <= 0) return 0;
	if (A > B) {
		C = A;
		A = B;
		B = C;
	}
	if (A < CSIZE && B < CSIZE && cache[A][B] > 0) {
		return cache[A][B] - 1;
	}
	if (A == B) return 0;
	if (A == 1 && B == 1) return 0;
	if (A == 1 || B == 1) return 1;

	int i;
	for(i = A/B; i > 0; i--) {
		if (!can_win(A-i*B, B)) {
			set_cache(A, B, 2);
			return 1;
		}
	}
	for(i = B/A; i > 0; i--) {
		if (!can_win(A, B-i*A)) {
			set_cache(A, B, 2);
			return 1;
		}
	}
	set_cache(A, B, 1);
	return 0;
}

int main(void) {
	int c, cases;
	int A1, A2, A, B1, B2, B;
	long long total;
	scanf("%d", &cases);
	for(c = 1; c < cases+1; c++) {
		total = 0;
		scanf("%d %d %d %d", &A1, &A2, &B1, &B2);
		for (A = A1; A < A2+1; A++){
			for (B = B1; B < B2+1; B++){
				if (can_win(A, B)) total += 1;
			}
		}
		printf("Case #%d: %d\n", c, total);
	}
}
