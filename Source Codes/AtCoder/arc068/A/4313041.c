//#include<stdio.h>
//int main() {
//	long long X, cnt = 0, ans = 0;
//	scanf("%lld", &X);
//	while (X>=0) {
//		if (cnt == 0)
//		{
//			X -= 6;
//			ans++;
//			cnt = 1;
//		}
//		else
//		{
//			X -= 5;
//			ans++;
//			cnt = 0;
//		}
//	}
//	printf("%lld\n", ans);
//
//	return 0;
//}

#include<stdio.h>
int main() {
	long long X, a = 0, b = 0, ans = 0;
	scanf("%lld", &X);
	a = X / 11;
	ans += 2 * a;
	b = X % 11;
	if (b > 0 && b <= 6)
	{
		ans += 1;
	}
	else if (b > 6 && b < 11)
	{
		ans += 2;
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:27:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &X);
  ^