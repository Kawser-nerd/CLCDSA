#include <stdio.h>
#include <stdlib.h>
#define int long long
#define inf (int)(1e18)

int *x, *a, *s, *skak;

int sum_lt1_r_kak(int l, int r){
	return skak[r] - skak[l];
}

int sum_lt1_r_ak(int l, int r){
	return s[r] - s[l];
}

int x2(int k){
	return k * k;
}

int min(int A, int B){
	return A <= B ? A : B;
}

signed main(){
	int N, X, i, j, ans = inf;
	scanf("%lld%lld", &N, &X);
	x = (int *)malloc(sizeof(int) * (N + 1));
	a = (int *)malloc(sizeof(int) * (N + 1));
	s = (int *)malloc(sizeof(int) * (N + 1));
	skak = (int *)malloc(sizeof(int) * (N + 1));
	x[0] = 0;
	a[0] = 0;
	s[0] = 0;
	skak[0] = 0;
	for(i = 1; i <= N; i++){
		scanf("%lld", &x[i]);
		a[i] = x[i] - x[i - 1];
		s[i] = s[i - 1] + a[i];
		skak[i] = skak[i - 1] + i * a[i];
	}
	int now, stl, str, l, r;
	for(i = 1; i <= N; i++){
		now = (N + i) * X;
		stl = N % i;
		str = N - i;
//		printf("now1 = %lld\n", now);
		for(j = 1; N - j * i > stl; j++){
			l = N - j * i - i;
			r = N - j * i;
			now += i * 1 * sum_lt1_r_ak(l, r);
			now += x2(j + 2) * ((r + 1) * sum_lt1_r_ak(l, r) - sum_lt1_r_kak(l, r));
			now += x2(j + 1) * (sum_lt1_r_kak(l, r) - (l + 1) * sum_lt1_r_ak(l, r));
		}
//		printf("now2 = %lld\n", now);

		l = N - i;
		r = N;
		now += 5 * ((i + l + 1) * sum_lt1_r_ak(l, r) - sum_lt1_r_kak(l, r));
//		printf("now3 = %lld\n", now);
		l = 0;
		r = stl;
//		printf("(l, r, j) = (%lld, %lld, %lld)\n", l, r, j);
		now += i * 1 * sum_lt1_r_ak(l, r);
		now += x2(j + 2) * ((r + 1) * sum_lt1_r_ak(l, r) - sum_lt1_r_kak(l, r));
		now += x2(j + 1) * (sum_lt1_r_kak(l, r) - (l + 1) * sum_lt1_r_ak(l, r) + (i - stl) * sum_lt1_r_ak(0, stl));

		if(now < 0){
			continue;
		}
		ans = min(ans, now);
//		printf("now[%lld] = %lld\n", i, now);
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:26:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &N, &X);
  ^
./Main.c:36:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &x[i]);
   ^