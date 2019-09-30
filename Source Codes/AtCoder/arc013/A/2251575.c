/*
tCoder Regular Contest 013  A – ???????? ??:
*/

#include<stdio.h>

//#define DEBUG1

int max(int a, int b) {
	return a >= b ? a : b;
}

int main() {
	int n, m, l, p, q, r, ans = 0;
	scanf("%d %d %d", &n, &m, &l);
	scanf("%d %d %d", &p, &q, &r);
#ifdef DEBUG1
	printf("%d %d %d %d %d %d", n, m, l, p, q, r);
#endif
	ans = max(ans, (n / p)*(m / q)*(l / r));
	ans = max(ans, (n / p)*(m / r)*(l / q));
	ans = max(ans, (n / q)*(m / p)*(l / r));
	ans = max(ans, (n / q)*(m / r)*(l / p));
	ans = max(ans, (n / r)*(m / q)*(l / p));
	ans = max(ans, (n / r)*(m / p)*(l / q));

	printf("%d\n", ans);
//	getch();
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d", &n, &m, &l);
  ^
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d", &p, &q, &r);
  ^