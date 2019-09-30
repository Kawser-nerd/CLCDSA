#include <stdio.h>
void f(int a, int b, int u) {
	if (u) {
		int d = (a ^ b) & u;
		d &= -d;
		u ^= d;
		int c = a ^ u & -u;
		f(a, c, u);
		f(c ^ d, b, u);
	} else {
		printf("%d ", a);
	}
}
int main() {
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	if (__builtin_parity(a ^ b)) {
		puts("YES");
		f(a, b, (1 << n) - 1);
	} else {
		puts("NO");
	}
} ./Main.c: In function ‘main’:
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &n, &a, &b);
  ^