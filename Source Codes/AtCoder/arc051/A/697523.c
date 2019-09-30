#include <stdio.h>
#include <math.h>

int max(int a, int b) {
	if (a >= b) { return a; }
	else { return b; }
}

int main() {

	int x1, y1, r, x2, y2, x3, y3;

	scanf("%d %d %d", &x1, &y1, &r);
	scanf("%d %d %d %d", &x2, &y2, &x3, &y3);

	int red = 0;

	if (x1 + r > x3 || x1 - r<x2 || y1 + r>y3 || y1 - r < y2) { red = 1; }

	if (red == 1) { printf("YES\n"); }
	else { printf("NO\n"); }

	int dx = max(abs(x2 - x1), abs(x3 - x1));
	int dy = max(abs(y2 - y1), abs(y3 - y1));

	int blue = 0;

	if (dx*dx + dy*dy > r*r) { blue = 1; }

	if (blue == 1) { printf("YES\n"); }
	else { printf("NO\n"); }

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:23:15: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
  int dx = max(abs(x2 - x1), abs(x3 - x1));
               ^
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d", &x1, &y1, &r);
  ^
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d", &x2, &y2, &x3, &y3);
  ^