#include <stdio.h>
 
typedef long long ll;
 
ll a[100005];
ll b[100005];
ll sumA[100005];
ll sumB[100005];
 
ll ma(ll a, ll b);
 
int main() {
 
	int N, K;
 
	scanf("%d %d",&N,&K);
 
	int i;
 
	ll s = 0ll;
	for (i = 0; i < N; i++) {
		scanf(" %lld",&a[i]);
		b[i] = ma(0ll,a[i]);
		s += a[i];
		sumA[i] = s;
	}
 
	s = 0ll;
	for (i = 0; i < N; i++) {
		s += b[i];
		sumB[i] = s;
	}
 
 
	int l = 0;
	int r = K-1;
 
	ll ans = 0ll;
 
	while (1) {
		if (r >= N) { break; }
		ll S = sumA[r];
		if (l != 0) { S -= sumA[l - 1]; }
		S = ma(S, 0ll);
		if (l == 0) {
			ll add = sumB[N - 1] - sumB[K - 1];
			S += add;
		}
		else if (r == N - 1) {
			ll add = sumB[l - 1];
			S += add;
		}
		else {
			ll add1 = sumB[l - 1];
			ll add2 = sumB[N - 1] - sumB[r];
			S += add1 + add2;
		}
		if (S > ans) { ans = S; }
		l++;
		r++;
	}
	printf("%lld\n",ans);
 
	return 0;
}
ll ma(ll a, ll b) {
	if (a >= b) { return a; }
	else { return b; }
} ./Main.c: In function ‘main’:
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&N,&K);
  ^
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf(" %lld",&a[i]);
   ^