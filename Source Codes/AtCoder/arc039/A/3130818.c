#include<stdio.h>

int max(int a, int b) { if (a>b) { return a; }return b; }

int ok(int x, int y) {
	int d = 0;
	if (x / 100 % 10 != y / 100 % 10) d++;
	if (x / 10 % 10 != y / 10 % 10) d++;
	if (x % 10 != y % 10) d++;
	return d <= 1;
}
int main() {
	int A, B;
	int ans = -1;
	scanf("%d%d", &A, &B);
	int ma = A - B;
	for (int x = 100; x <= 999; x++) {
		if (ok(A, x)) { ma = max(ma, x - B); }
	}
	for (int x = 100; x <= 999; x++) {
		if (ok(B, x)) { ma = max(ma, A - x); }
	}
	ans = ma;
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &A, &B);
  ^