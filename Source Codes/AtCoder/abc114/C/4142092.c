#include<stdio.h>
long long N, ans;
int num(long long a, long long b3, long long b5, long long b7) {
	if (a > N) { return; }
	if (b3 + b5 + b7 == 3) { ans++; }
	num(a * 10 + 3, 1, b5, b7);
	num(a * 10 + 5, b3, 1, b7);
	num(a * 10 + 7, b3, b5, 1);
}

int main() {
	scanf("%lld", &N);
	num(0, 0, 0, 0);
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘num’:
./Main.c:4:15: warning: ‘return’ with no value, in function returning non-void
  if (a > N) { return; }
               ^
./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^