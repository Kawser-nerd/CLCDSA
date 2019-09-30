#include<stdio.h>
long long int small(long long int a, long long int b) {
	if (a >= b) {
		return b;
	}
	else {
		return a;
	}
}
int main() {
	long long int n, s[5000] = {},m,min=10000000,count=0,x;
	scanf("%lld%lld%lld", &n, &m,&x);
	for (int i = 1; i <= m; i++) {
		scanf("%lld", &s[i]);
		
		if (s[i] < x) {
			count++;
		}
	}
	printf("%lld", small(count,m-count));
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld", &n, &m,&x);
  ^
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &s[i]);
   ^