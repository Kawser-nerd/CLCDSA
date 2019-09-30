#include<stdio.h>

int main() {

	long long int pushCount = 0;
	long long int n;
	scanf("%lld", &n);

	long long int a[100010];
	long long int b[100010];

	for (int i = 0; i < n; i++) {
		scanf("%lld%lld", &a[i], &b[i]);
	}
	for (int i = n - 1; i >= 0; i--) {
		long long int plus = 0;
		if ((a[i] + pushCount) % b[i] == 0)	continue;
		plus = b[i] * ((a[i] + pushCount) / b[i] + 1) - (a[i] + pushCount);
		pushCount += plus;
	}
	
	printf("%lld", pushCount);

}