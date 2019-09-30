#include <stdio.h>

enum ACGT {
	A, C, G, T
};

#define LEN 100

int NG(int x, int y, int z) {
	return (x == A && y == G && z == C);
}

int FLAT(int x, int y, int z) {
	return (x * 4 + y) * 4 + z;
}

#define MOD 1000000007

int X[LEN+1][64];
int main() {
	int N;
	scanf("%d\n", &N);

	for (int i1 = 0; i1 < 4; i1++)
	for (int i2 = 0; i2 < 4; i2++)
	for (int i3 = 0; i3 < 4; i3++) {
		if (NG(i1, i2, i3)) continue;
		if (NG(i2, i1, i3)) continue;
		if (NG(i1, i3, i2)) continue;

		X[3][FLAT(i1, i2, i3)] = 1;
	}

	for (int i = 4; i <= N; i++) {
		for (int i1 = 0; i1 < 4; i1++)
		for (int i2 = 0; i2 < 4; i2++)
		for (int i3 = 0; i3 < 4; i3++)
		for (int i4 = 0; i4 < 4; i4++) {
			if (NG(i2, i3, i4)) continue;
			if (NG(i3, i2, i4)) continue;
			if (NG(i2, i4, i3)) continue;

			if (NG(i1, i3, i4)) continue;
			if (NG(i1, i2, i4)) continue;

			X[i][FLAT(i2, i3, i4)] += X[i - 1][FLAT(i1, i2, i3)];
			X[i][FLAT(i2, i3, i4)] %= MOD;
		}
	}
	int sum = 0;
	for (int i1 = 0; i1 < 4; i1++)
	for (int i2 = 0; i2 < 4; i2++)
	for (int i3 = 0; i3 < 4; i3++) {
		sum += X[N][FLAT(i1, i2, i3)];
		sum %= MOD;
	}
	printf("%d\n", sum);
} ./Main.c: In function ‘main’:
./Main.c:22:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d\n", &N);
  ^