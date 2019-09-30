// AtCoder Regular Contest 080 D - Grid Coloring
// 2018.1.12 bal4u

#include <stdio.h>

int map[101][102];

//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0;
	int c = getchar_unlocked();
	do n = (n<<3)+(n<<1) + (c & 0xf), c = getchar_unlocked();
	while (c >= '0');
	return n;
}

int main()
{
	int H, W, N, a;
	int r, c, k;
	
	H = in(), W = in(), N = in();
	r = c = k = 0;
	while (N--) {
		a = in(), k++;
		while (a--) {
			map[r][c] = k;
			if (r & 1) { if (--c  < 0) r++, c =   0; }
			else       { if (++c == W) r++, c = W-1; }
		}
	}
	for (r = 0; r < H; r++) {
		printf("%d", map[r][0]);
		for (c = 1; c < W; c++) printf(" %d", map[r][c]);
		putchar('\n');
	}
	return 0;
}