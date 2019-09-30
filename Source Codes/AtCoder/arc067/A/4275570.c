#include<stdio.h>
long long int a[100002];
int main() {
	long long N;
	scanf("%lld", &N);
	long long int t;
	long long int ans = 1;
	for (long long int i = 2; i <= N; i++)
	{
		t = i;
		for (long long int j = 2; j <= i; j++)
		{
			while (t%j == 0) {
				a[j]++;
				t = t / j;
			}
		}
	}
	for (long long int i = 2; i <= N; i++)
	{
		if (a[i] != 0)
		{
			ans = ans * (a[i] + 1);
			ans = ans % 1000000007;
		}
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^