#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define abs(x, y)	((x) > (y) ? ((x) - (y)) : ((y) - (x)))

typedef int (Board) [100][256];
Board board;
int arr[100];

int D, I, M, t, n;

int _solve(int pos, int val) {
	if (pos < 0)
		return 0;
	if (board[pos][val] >= 0)
		return board[pos][val];
	int mintmp, min, delta;
	int i, j, k;
	// Delete
	min = _solve(pos - 1, val) + D;

	// Preserve
	if (pos == 0) {
		mintmp = abs(val, arr[pos]);
		if (mintmp < min)
			min = mintmp;
	} else {
		for (i = 0; i <= 255; i++) {
			delta = abs(i, val);
			mintmp = _solve(pos - 1, i);
			if (mintmp != pos * D) {
				if (delta > M && M != 0) {
					mintmp += ((delta - 1) / M) * I;
				} else if (M == 0 && delta > 0) {
					continue;
				}
			}
			mintmp += abs(val, arr[pos]);
			if (mintmp < min)
				min = mintmp;
		}
	}
	board[pos][val] = min;
	return min;
}

int solve() {
	int mintmp;
	int min;
	int j;
	min = -1;
	for (j = 0; j <= 255; j++) {
		mintmp = _solve(n - 1, j);
		if (min == -1 || mintmp < min)
			min = mintmp;
	}
	return min;
}

int main() {
	int i, j, k, tmp;
	int min;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%d %d %d %d", &D, &I, &M, &n);
		for (j = 0; j < n; j++) {
			scanf("%d", &arr[j]);
			for (k = 0; k <= 255; k++) {
				board[j][k] = -1;
			}
		}
		min = solve();
		printf("Case #%d: %d\n", i + 1, min);
	}
	return 0;
}
