#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 2*1000000
#define min(x,y) (x)<(y)?(x):(y)
long long a[N];
long long sum[N + 400];
long long Min =1e10;
int main() {
	long long n, m;
	scanf("%lld", &n);
	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1; i <= n - 1; i++) {
		Min = min(abs(sum[i] - (sum[n] - sum[i])), Min);
	}
	printf("%lld\n", Min);
	return 0;
}