#include<stdio.h>
int change_plus(int a) {
	if (a < 0) { return -a; }
	if (a >= 0) { return a; }
}
int big(int a,  int b) {
	if (a >= b) {
		return a;
	}
	else {
		return b;
	}
}

int main() {
	int n;
	int check;
	int x[150], y[150], h[150];
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &x[i],&y[i],&h[i]);
	}
	for (int i =0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			for (int k= h[1]; k <= h[1] +200;k++) {
				for (int p = 1; p <= n; p++) {
					if (h[p] != big(0, k - change_plus(x[p] - i) - change_plus(y[p] - j))) { goto next; }
				}
				printf("%d %d %d", i, j, k);
			next:
				check++;
			}
		}
	}

} ./Main.c: In function ‘main’:
./Main.c:19:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &x[i],&y[i],&h[i]);
   ^