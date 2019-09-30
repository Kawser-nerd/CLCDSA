#include <stdio.h>
typedef long long ll;

ll n;
ll a[100005];

int main()
{
	ll ans = 1;
	ll s = 0;

	scanf("%lld", &n);
	for (ll i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}

	for (ll i = 1; i < n; i++) {
		if (s != 0) {
			if (s > 0 && a[i] - a[i - 1] < 0) {
				s = 0;
				ans++;
			} else if (s < 0 && a[i] - a[i - 1] > 0) {
				s = 0;
				ans++;
			}
		} else {
			if (a[i] - a[i - 1] > 0) {
				s = 1;
			} else if (a[i] - a[i - 1] < 0) {
				s = -1;
			} else {
				s = 0;
			}
		}
	}

	printf("%lld\n", ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &n);
  ^
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &a[i]);
   ^