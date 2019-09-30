#include <stdio.h>

long long R, B;
long long x, y;

int check(long long K);

int main() {


	scanf("%lld %lld", &R, &B);
	scanf("%lld %lld", &x, &y);

	long long low = 0;
	long long high = 1ll << 60;

	while (high - low > 1) {
		long long mid = (high + low)/2;
		if (check(mid) == 1) { low = mid; }
		else { high = mid; }
	}
	printf("%lld\n",low);

	return 0;
}
int check(long long K) {
	if (R - K < 0) { return 0; }
	if (B - K < 0) { return 0; }

	long long maxR = (R - K) / (x - 1);
	long long maxB = (B - K) / (y - 1);

	if (maxR + maxB >= K) { return 1; }
	else { return 0; }

} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld", &R, &B);
  ^
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld", &x, &y);
  ^