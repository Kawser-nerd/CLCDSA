#include <stdio.h>

typedef long long ll;

ll N;

ll a[2005];

ll f(ll A, ll B);
ll min(ll A, ll B);

ll b[2005][2005];

int main() {


	ll x;

	scanf("%lld %lld",&N,&x);

	ll i,k;

	for (i = 0; i < N; i++) {
		scanf(" %lld",&a[i]);
	}
	for (i = 0; i < N; i++) {
		b[i][0] = f(i, 0);
		for (k = 0; k < N - 1; k++) {
			if (i - k - 1 < 0) { b[i][k + 1] = min(b[i][k], a[i - k - 1 + N]); }
			else {
				b[i][k + 1] = min(b[i][k], a[i - k - 1]);
			}
		}
	}
	ll ans = (1ll << 60);
	for (k = 0; k < N; k++) {
		ll sum = k*x;
		for (i = 0; i < N; i++) {
			sum += b[i][k];
		}
		ans = min(ans, sum);
	}
	printf("%lld\n",ans);

	return 0;
}
ll f(ll A, ll B) {
	int i;
	ll r = (1ll << 60);
	for (i = 0; i <= B; i++) {
		if (A - i < 0) {
			r = min(r, a[A - i + N]);
		}
		else {
			r = min(r, a[A - i]);
		}
	}
	return r;
}
ll min(ll A, ll B) {
	if (A >= B) { return B; }
	else { return A; }
} ./Main.c: In function ‘main’:
./Main.c:19:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld",&N,&x);
  ^
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf(" %lld",&a[i]);
   ^