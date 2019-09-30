#include <stdio.h>
#include <stdlib.h>
long long int min(long long int a, long long int b) { return a < b ? a : b; }
long long int max(long long int a, long long int b) { return a > b ? a : b; }
void swap(long long int *a, long long int *b) {
	long long int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(void) {
	long long int H, W, i, tmp, ans;
	scanf("%lld%lld", &H, &W);

	ans = H * W;
	if (H % 3 == 0 || W % 3 == 0) {
		printf("0\n");
		return 0;
	}
	if (H == 1 || W == 1) {
		printf("0\n");
		return 0;
	}

	for (i = 1; i < W / 2 + 1; i++) {
		if (H % 2 == 0)
			tmp = llabs(i * H - H / 2 * (W - i));
		else 
			tmp = max(llabs(i * H - H / 2 * (W - i)), llabs(i * H - (H / 2 + 1) * (W - i)));
		ans = min(tmp, ans);
	}
	ans = min(H, ans);
	
	swap(&H, &W);
	for (i = 1; i < W / 2 + 1; i++) {
		if (H % 2 == 0)
			tmp = llabs(i * H - H / 2 * (W - i));
		else 
			tmp = max(llabs(i * H - H / 2 * (W - i)), llabs(i * H - (H / 2 + 1) * (W - i)));
		ans = min(tmp, ans);
	}
	ans = min(H, ans);

	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &H, &W);
  ^