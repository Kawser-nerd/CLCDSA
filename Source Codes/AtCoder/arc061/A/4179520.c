#include<stdio.h>
#include<string.h>
#define ll long long

int main() {
	char S[11];
	scanf("%s", S);
	int p = strlen(S) - 1;
	ll ans = 0;
	for (int i = 0; i < 1 << p; i++)
	{
		ll sum = S[0] - '0';
		for (int j = 0; j < p; j++)
		{
			if (i >> j & 1)
			{
				ans += sum;
				sum = S[j + 1] - '0';
			}
			else {
				sum = sum * 10 + S[j + 1] - '0';
			}
		}
		ans += sum;
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^