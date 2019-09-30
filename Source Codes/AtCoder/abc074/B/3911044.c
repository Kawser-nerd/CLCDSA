#include<stdio.h>
//????(?)
long long int small(long long int a, long long int b) {
	if (a >= b) {
		return b;
	}
	else {
		return a;
	}
}
int main() {
	long long int n, m, num[500] = {}, result;
	scanf("%lld%lld",&n,&m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &num[i]);
		result += small(num[i], m - num[i]) * 2;
	}
	
	printf("%lld", result);
			
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&m);
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &num[i]);
   ^