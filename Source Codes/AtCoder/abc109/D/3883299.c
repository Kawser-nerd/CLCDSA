#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>


int main() {
	int h, w,m=0, a[505][505],b[505][505];
	scanf("%d%d", &h, &w);
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			scanf("%d", &a[i][j]);
			b[i][j] = a[i][j];
		}
	}
	for (int i = 1; i <= h-1; i++) {
		for (int j = 1; j <= w-1; j++) {
			if (a[i][j] % 2 == 1) {m++; a[i][j + 1]++; }
		}
		if (a[i][w] % 2 == 1) { m++; a[i + 1][w]++; }
	}
	for (int j = 1; j <= w - 1; j++) {
		if (a[h][j] % 2 == 1) { m++; a[h][j + 1]++; }
	}
	printf("%d\n", m);
	for (int i = 1; i <= h - 1; i++) {
		for (int j = 1; j <= w - 1; j++) {
			if (b[i][j] % 2 == 1) { printf("%d %d %d %d\n", i, j, i, j+1); b[i][j+1]++; }
		}
		if (b[i][w] % 2 == 1) { printf("%d %d %d %d\n", i, w, i+1,w); b[i+1][w]++; }
	}
	for (int j = 1; j <= w - 1; j++) {
		if (b[h][j] % 2 == 1) { printf("%d %d %d %d\n", h,j, h, j+1); b[h][j+1]++; }
	}
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &h, &w);
  ^
./Main.c:11:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d", &a[i][j]);
    ^