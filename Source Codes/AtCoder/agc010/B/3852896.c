#include<stdio.h>
int main() {
	long long int n,m, memo = 0;
	long long int a[100005] = {}, sum[100005] = {};
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		sum[i] =sum[i-1]+ a[i];
		memo += i;
	}

	if (sum[n]%memo != 0) { printf("NO"); return 0; }
	m = sum[n] / memo;
	for (int i = 2; i <= n; i++) {
		
		m -= a[i] - a[i - 1] - sum[n] / memo;
		if((a[i]-a[i-1]-sum[n]/memo)%n!=0|| (a[i] - a[i - 1] - sum[n] / memo)>0){ printf("NO"); return 0; }
	}
	if(m<0){ printf("NO"); return 0; }
	printf("YES");
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &n);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &a[i]);
   ^